// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "GAS/CustomAbilitySystemComponent.h"
#include "GAS/Attributes/CharacterHealthAttributeSet.h"
#include "PlayerStateInGame.generated.h"

/**
 * 
 */
UCLASS()
class UERECONNECT_API APlayerStateInGame : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	APlayerStateInGame();
	UFUNCTION(BlueprintPure)
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void AddCharacterAbilities();
protected:
	UPROPERTY(Replicated)
	UCustomAbilitySystemComponent* AbilitySystemComponent;
	UPROPERTY(Replicated)
	UCharacterHealthAttributeSet* HealthAttributeSet;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<UGameplayAbility>> Abilities;
};
