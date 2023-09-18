// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerControllerMainMenu.h"
void APlayerControllerMainMenu::Travel(FString URL)
{
	ClientTravel(URL, TRAVEL_Absolute);
}
