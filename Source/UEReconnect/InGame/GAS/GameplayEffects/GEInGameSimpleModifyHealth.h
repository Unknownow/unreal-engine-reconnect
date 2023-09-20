// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "NativeGameplayTags.h"
#include "GEInGameSimpleModifyHealth.generated.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Modify_Health);

/**
 * 
 */
UCLASS()
class UERECONNECT_API UGEInGameSimpleModifyHealth : public UGameplayEffect
{
	GENERATED_BODY()

public:
	UGEInGameSimpleModifyHealth();
};
