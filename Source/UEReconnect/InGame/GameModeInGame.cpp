// Fill out your copyright notice in the Description page of Project Settings.

#include "GameModeInGame.h"

#include "Kismet/GameplayStatics.h"

AGameModeInGame::AGameModeInGame()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/InGame/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AGameModeInGame::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
}

void AGameModeInGame::AddInactivePlayerPawn(APawn* PlayerPawn)
{
	InactivePlayerPawns.Add(PlayerPawn);
}

void AGameModeInGame::AddInactivePlayerController(APlayerControllerInGame* PlayerController)
{
	InactivePlayerControllers.Add(PlayerController);
}

void AGameModeInGame::AddInactivePlayerState(APlayerStateInGame* PlayerState)
{
	InactivePlayerStates.Add(PlayerState);
}

APlayerController* AGameModeInGame::Login(
	UPlayer*                NewPlayer,
	ENetRole                InRemoteRole,
	const FString&          Portal,
	const FString&          Options,
	const FUniqueNetIdRepl& UniqueId,
	FString&                ErrorMessage
)
{
	UE_LOG(LogTemp, Error, TEXT("AGameModeInGame::Login NetId =  %s"), *UniqueId.ToDebugString());

	APlayerControllerInGame* PC = nullptr;

	if (SavedPlayerControllers.Contains(UniqueId))
	{
		PC = SavedPlayerControllers[UniqueId];
		// Find a starting spot
		FString ErrMessage;
		if (!UpdatePlayerStartSpot(PC, Portal, ErrMessage))
		{
			UE_LOG(LogGameMode, Warning, TEXT("InitNewPlayer: %s"), *ErrMessage);
			PC->Destroy();
			return nullptr;
		}

		// Set up spectating
		bool bSpectator = FCString::Stricmp(*UGameplayStatics::ParseOption(Options, TEXT("SpectatorOnly")), TEXT("1")) == 0;
		if (bSpectator || MustSpectate(PC))
		{
			PC->StartSpectatingOnly();
		}
	}
	else
	{
		PC = Cast<APlayerControllerInGame>(Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage));
		SavedPlayerControllers.Add(UniqueId, PC);
	}

	return PC;
}
