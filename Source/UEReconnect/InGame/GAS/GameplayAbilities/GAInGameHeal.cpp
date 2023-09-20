// Fill out your copyright notice in the Description page of Project Settings.

#include "GAInGameHeal.h"

#include "AbilitySystemComponent.h"
#include "UEReconnect/InGame/GAS/GameplayEffects/GEInGameSimpleModifyHealth.h"

UE_DEFINE_GAMEPLAY_TAG(TAG_Abilities_Heal, "Abilities.Heal");

UGAInGameHeal::UGAInGameHeal()
{
	// Default to Instance Per Actor
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	AbilityTags.AddTag(TAG_Abilities_Heal.GetTag());
}

void UGAInGameHeal::ActivateAbility(
	const FGameplayAbilitySpecHandle     Handle,
	const FGameplayAbilityActorInfo*     ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData*            TriggerEventData
)
{
	CommitAbility(Handle, ActorInfo, ActivationInfo);
	if (!ActorInfo->AbilitySystemComponent.IsValid())
	{
		CancelAbility(Handle, ActorInfo, ActivationInfo, true);
		return;
	}

	const auto ASC     = ActorInfo->AbilitySystemComponent.Get();
	const auto NewSpec = ASC->MakeOutgoingSpec(UGEInGameSimpleModifyHealth::StaticClass(), 1, ASC->MakeEffectContext());
	NewSpec.Data->SetSetByCallerMagnitude(TAG_Modify_Health.GetTag(), 10);
	ASC->ApplyGameplayEffectSpecToSelf(*NewSpec.Data);
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
