// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPS_SampleGameMode.h"
#include "FPS_SampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPS_SampleGameMode::AFPS_SampleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
