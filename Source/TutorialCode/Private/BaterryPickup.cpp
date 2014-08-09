

#include "TutorialCode.h"
#include "BaterryPickup.h"


ABaterryPickup::ABaterryPickup(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PowerLevel = 150.0f;
}

void ABaterryPickup::OnPickedUp_Implementation()
{
	Super::OnPickedUp_Implementation();
	Destroy();
}


