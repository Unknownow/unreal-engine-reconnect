// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "Abilities/GameplayAbility.h"
#include "GAInGameHit.generated.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Abilities_Hit);

/**
 * 
 */
UCLASS()
class UERECONNECT_API UGAInGameHit : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UGAInGameHit();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle     Handle,
		const FGameplayAbilityActorInfo*     ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData*            TriggerEventData
	) override;
};
