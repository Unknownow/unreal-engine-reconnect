// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerControllerInGame.h"

#include "PlayerStateInGame.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/HUD.h"
#include "GAS/GameplayAbilities/GAInGameHeal.h"
#include "GAS/GameplayAbilities/GAInGameHit.h"

void APlayerControllerInGame::OnNetCleanup(UNetConnection* Connection)
{
	Player = NULL;
	NetConnection = NULL;	
	
	// Super::OnNetCleanup(Connection);
}

void APlayerControllerInGame::Destroyed()
{
	// if (GetPawn() != NULL)
	// {
	// 	// Handle players leaving the game
	// 	if (Player == NULL && GetLocalRole() == ROLE_Authority)
	// 	{
	// 		PawnLeavingGame();
	// 	}
	// 	else
	// 	{
	// 		UnPossess();
	// 	}
	// }
	//
	// if (GetSpectatorPawn() != NULL)
	// {
	// 	DestroySpectatorPawn();
	// }
	// if ( MyHUD != NULL )
	// {
	// 	MyHUD->Destroy();
	// 	MyHUD = NULL;
	// }
	//
	// if (PlayerCameraManager != NULL)
	// {
	// 	PlayerCameraManager->Destroy();
	// 	PlayerCameraManager = NULL;
	// }
	//
	// // Tells the game info to forcibly remove this player's CanUnpause delegates from its list of Pausers.
	// // Prevents the game from being stuck in a paused state when a PC that paused the game is destroyed before the game is unpaused.
	// AGameModeBase* const GameMode = GetWorld()->GetAuthGameMode();
	// if (GameMode)
	// {
	// 	GameMode->ForceClearUnpauseDelegates(this);
	// }
	//
	// PlayerInput = NULL;
	// CheatManager = NULL;
	//
	// AController::Destroyed();
	Super::Destroyed();
}

void APlayerControllerInGame::PawnLeavingGame()
{
	if (GetPawn() != NULL)
	{
		// GetPawn()->Destroy();
		SetPawn(NULL);
	}
}

void APlayerControllerInGame::Hit()
{
	GetPlayerState<APlayerStateInGame>()->GetAbilitySystemComponent()->TryActivateAbilitiesByTag(TAG_Abilities_Hit.GetTag().GetSingleTagContainer());
}
void APlayerControllerInGame::Heal()
{
	GetPlayerState<APlayerStateInGame>()->GetAbilitySystemComponent()->TryActivateAbilitiesByTag(TAG_Abilities_Heal.GetTag().GetSingleTagContainer());
}
