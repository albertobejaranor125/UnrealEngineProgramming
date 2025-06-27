// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProgramacionUnrealGameMode.h"
#include "ProgramacionUnrealCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProgramacionUnrealGameMode::AProgramacionUnrealGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
