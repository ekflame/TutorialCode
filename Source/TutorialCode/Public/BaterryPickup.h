
#pragma once

#include "Pickup.h"
#include "BaterryPickup.generated.h"

/**
 * 
 */
UCLASS()
class TUTORIALCODE_API ABaterryPickup : public APickup
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
	float PowerLevel;
	
	void OnPickedUp_Implementation() override;
};
