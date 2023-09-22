// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerControllerInGame.h"
#include "PlayerStateInGame.h"
#include "GameFramework/GameModeBase.h"
#include "UObject/Object.h"
#include "GameModeInGame.generated.h"

/**
 * 
 */
UCLASS()
class UERECONNECT_API AGameModeInGame : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameModeInGame();

	virtual void Logout(AController* Exiting) override;

	void AddInactivePlayerPawn(APawn* PlayerPawn);
	void AddInactivePlayerController(APlayerControllerInGame* PlayerController);
	void AddInactivePlayerState(APlayerStateInGame* PlayerState);

	virtual APlayerController* Login(
		UPlayer*                NewPlayer,
		ENetRole                InRemoteRole,
		const FString&          Portal,
		const FString&          Options,
		const FUniqueNetIdRepl& UniqueId,
		FString&                ErrorMessage
	) override;

protected:
	UPROPERTY()
	TArray<APawn*> InactivePlayerPawns;
	UPROPERTY()
	TArray<APlayerControllerInGame*> InactivePlayerControllers;
	UPROPERTY()
	TArray<APlayerStateInGame*> InactivePlayerStates;

	UPROPERTY()
	TMap<FUniqueNetIdRepl, TObjectPtr<APlayerControllerInGame>> SavedPlayerControllers;
};
