// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectBandGameMode.h"
#include "ProjectBandCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectBandGameMode::AProjectBandGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
