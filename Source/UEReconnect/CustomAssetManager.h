// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "CustomAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class UERECONNECT_API UCustomAssetManager : public UAssetManager
{
	GENERATED_BODY()

	virtual void StartInitialLoading() override;
};
