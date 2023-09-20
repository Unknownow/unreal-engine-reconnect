// Fill out your copyright notice in the Description page of Project Settings.

#include "GameModeInGame.h"

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
