// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerStateInGame.h"

#include "GAS/GameplayAbilities/GAInGameHeal.h"
#include "GAS/GameplayEffects/GEInGameInitialize.h"
#include "Net/UnrealNetwork.h"

APlayerStateInGame::APlayerStateInGame()
{
	AbilitySystemComponent = CreateDefaultSubobject<UCustomAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	HealthAttributeSet = CreateDefaultSubobject<UCharacterHealthAttributeSet>(TEXT("HealthAttributeSet"));

	Abilities.Add(UGAInGameHeal::StaticClass());
}

UAbilitySystemComponent* APlayerStateInGame::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void APlayerStateInGame::BeginPlay()
{
	Super::BeginPlay();

	const auto NewSpec = GetAbilitySystemComponent()->MakeOutgoingSpec
		(UGEInGameInitialize::StaticClass(), 1, GetAbilitySystemComponent()->MakeEffectContext());
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*NewSpec.Data);

	AddCharacterAbilities();
}

void APlayerStateInGame::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(APlayerStateInGame, AbilitySystemComponent, COND_None);
	DOREPLIFETIME_CONDITION(APlayerStateInGame, HealthAttributeSet, COND_None);
}

void APlayerStateInGame::AddCharacterAbilities()
{
	// Grant abilities, but only on the server	
	if (GetLocalRole() != ROLE_Authority || !IsValid(AbilitySystemComponent))
	{
		return;
	}

	// just let it simple like this!
	for (TSubclassOf<UGameplayAbility>& StartupAbility : Abilities)
	{
		AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility));
	}
}
