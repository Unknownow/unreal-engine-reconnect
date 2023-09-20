// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "Abilities/GameplayAbility.h"
#include "GAInGameHeal.generated.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Abilities_Heal);

/**
 * 
 */
UCLASS()
class UERECONNECT_API UGAInGameHeal : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UGAInGameHeal();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle     Handle,
		const FGameplayAbilityActorInfo*     ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData*            TriggerEventData
	) override;
};
