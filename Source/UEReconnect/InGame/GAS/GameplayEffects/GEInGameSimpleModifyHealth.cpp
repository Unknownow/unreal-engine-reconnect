// Fill out your copyright notice in the Description page of Project Settings.

#include "GEInGameSimpleModifyHealth.h"

#include "UEReconnect/InGame/GAS/Attributes/CharacterHealthAttributeSet.h"

UE_DEFINE_GAMEPLAY_TAG(TAG_Modify_Health, "Modify.Health");

UGEInGameSimpleModifyHealth::UGEInGameSimpleModifyHealth()
{
	FGameplayModifierInfo HealthModifer;
	HealthModifer.Attribute         = UCharacterHealthAttributeSet::GetHealthAttribute();
	HealthModifer.ModifierOp        = EGameplayModOp::Additive;
	FSetByCallerFloat SetByCaller;
	SetByCaller.DataName = "HealthModifier";
	SetByCaller.DataTag = TAG_Modify_Health.GetTag();
	HealthModifer.ModifierMagnitude = {SetByCaller};
	Modifiers.Add(HealthModifer);
}
