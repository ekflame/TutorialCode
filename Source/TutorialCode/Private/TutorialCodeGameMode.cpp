// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "TutorialCode.h"
#include "TutorialCodeGameMode.h"
#include "TutorialCodeCharacter.h"

ATutorialCodeGameMode::ATutorialCodeGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FObjectFinder<UClass> PlayerPawnBPClass(TEXT("Class'/Game/Blueprints/MyCharacter.MyCharacter_C'"));
	if (PlayerPawnBPClass.Object != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Object;

	}

	DecayRate = 1.0f;
}

void ATutorialCodeGameMode::Tick(float DeltaSeconds)
{
	ATutorialCodeCharacter * MyCharacter = Cast<ATutorialCodeCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (MyCharacter->PowerLevel > 0.05f)
	{
		MyCharacter->PowerLevel = FMath::FInterpTo(MyCharacter->PowerLevel, 0.0f, DeltaSeconds, DecayRate);
	}
	else
	{
		SetCurrentState(ETutorialCodePlayState::EGameOver);
	}
}

void ATutorialCodeGameMode::SetCurrentState(ETutorialCodePlayState NewState)
{
	CurrentState = NewState;

	HandleNewState(NewState);
}

void ATutorialCodeGameMode::HandleNewState(ETutorialCodePlayState NewState)
{
	switch (NewState)
	{
	case ETutorialCodePlayState::EPlaying:
		break;
	case ETutorialCodePlayState::EGameOver:
		break;
	case ETutorialCodePlayState::EUnknown:
		break;
	default:
		break;
	}
}