// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PlayerControllerInGame.generated.h"

/**
 * 
 */
UCLASS()
class UERECONNECT_API APlayerControllerInGame : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void Destroyed() override;
	virtual void PawnLeavingGame() override;

	UFUNCTION(BlueprintCallable)
	virtual void Hit();
	UFUNCTION(BlueprintCallable)
	virtual void Heal();
};
