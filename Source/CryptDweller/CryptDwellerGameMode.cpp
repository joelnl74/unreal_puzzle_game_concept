// Copyright Epic Games, Inc. All Rights Reserved.

#include "CryptDwellerGameMode.h"
#include "CryptDwellerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACryptDwellerGameMode::ACryptDwellerGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
