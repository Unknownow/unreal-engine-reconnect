// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterHealthAttributeSet.h"

#include "Net/UnrealNetwork.h"

void UCharacterHealthAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterHealthAttributeSet, Health, COND_None, REPNOTIFY_Always);
}

void UCharacterHealthAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
}
