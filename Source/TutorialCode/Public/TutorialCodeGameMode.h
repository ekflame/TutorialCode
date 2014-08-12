// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "TutorialCodeGameMode.generated.h"


enum class ETutorialCodePlayState : short
{
	EPlaying,
	EGameOver,
	EUnknown
};

UCLASS(minimalapi)
class ATutorialCodeGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Power)
	float DecayRate;

	ETutorialCodePlayState GetCurrentState() const;
	void SetCurrentState(ETutorialCodePlayState NewState);

private:
	ETutorialCodePlayState CurrentState;

	void HandleNewState(ETutorialCodePlayState NewState);
};



