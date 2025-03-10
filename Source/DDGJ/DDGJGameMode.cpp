// Copyright Epic Games, Inc. All Rights Reserved.

#include "DDGJGameMode.h"
#include "DDGJCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADDGJGameMode::ADDGJGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
