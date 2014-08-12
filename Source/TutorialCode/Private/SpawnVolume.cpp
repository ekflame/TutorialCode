#include "TutorialCode.h"
#include "SpawnVolume.h"
#include "Pickup.h"

ASpawnVolume::ASpawnVolume(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
	WhereToSpawn = PCIP.CreateDefaultSubobject<UBoxComponent>(this, TEXT("WhereToSpawn"));

	RootComponent = WhereToSpawn;

	SpawnDelayRangeLow = 1.0f;
	SpawnDelayRangeHigh = 4.5f;
	SpawnDelay = GetRandomSpawnDelay();

	PrimaryActorTick.bCanEverTick = true;
}

void ASpawnVolume::SpawnPickup()
{
	if (WhatToSpawn != NULL)
	{
		UWorld * const World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			FVector SpawnLocation = GetRandomPointInVolume();

			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::FRand() * 360.0f;
			SpawnRotation.Pitch = FMath::FRand() * 360.0f;
			SpawnRotation.Roll = FMath::FRand() * 360.0f;

			APickup * const SpawnedPickup = World->SpawnActor<APickup>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
		}
	}
}

float ASpawnVolume::GetRandomSpawnDelay()
{
	return FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
}

FVector ASpawnVolume::GetRandomPointInVolume()
{
	FVector RandomLocation;

	float MinX, MinY, MinZ;
	float MaxX, MaxY, MaxZ;

	FVector Origin;
	FVector BoxExtent;

	Origin = WhereToSpawn->Bounds.Origin;
	BoxExtent = WhereToSpawn->Bounds.BoxExtent;

	MinX = Origin.X - BoxExtent.X * 0.5f;
	MinY = Origin.Y - BoxExtent.Y * 0.5f;
	MinZ = Origin.Z - BoxExtent.Z * 0.5f;

	MaxX = Origin.X + BoxExtent.X * 0.5f;
	MaxY = Origin.Y + BoxExtent.Y * 0.5f;
	MaxZ = Origin.Z + BoxExtent.Z * 0.5f;

	RandomLocation.X = FMath::FRandRange(MinX, MaxX);
	RandomLocation.Y = FMath::FRandRange(MinY, MaxY);
	RandomLocation.Z = FMath::FRandRange(MinZ, MaxZ);

	return RandomLocation;
}

void ASpawnVolume::Tick(float deltaTime)
{
	SpawnTime += deltaTime;

	bool bShouldSpawn = SpawnTime > SpawnDelay;

	if (bShouldSpawn)
	{
		SpawnPickup();
		SpawnTime -= SpawnDelay;

		SpawnDelay = GetRandomSpawnDelay();
	}

}