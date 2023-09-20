// Fill out your copyright notice in the Description page of Project Settings.

#include "GEInGameInitialize.h"

#include "UEReconnect/InGame/GAS/Attributes/CharacterHealthAttributeSet.h"

UGEInGameInitialize::UGEInGameInitialize()
{	
	FGameplayModifierInfo HealthModifer;
	HealthModifer.Attribute = UCharacterHealthAttributeSet::GetHealthAttribute();
	HealthModifer.ModifierOp = EGameplayModOp::Override;
	HealthModifer.ModifierMagnitude = {{100}};
	Modifiers.Add(HealthModifer);
}
