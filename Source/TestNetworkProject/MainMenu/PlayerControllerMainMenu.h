// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PlayerControllerMainMenu.generated.h"

/**
 * 
 */
UCLASS()
class TESTNETWORKPROJECT_API APlayerControllerMainMenu : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Travel(FString URL);
};
