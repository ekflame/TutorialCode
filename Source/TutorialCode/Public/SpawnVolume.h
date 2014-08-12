#pragma once

#include "Pickup.h"
#include "Spawnvolume.generated.h"

UCLASS()
class ASpawnVolume: public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleInstanceOnly, Category = Spawnning)
	TSubobjectPtr<UBoxComponent> WhereToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawnning)
	TSubclassOf<APickup> WhatToSpawn;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawnning)
	float SpawnDelayRangeLow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawnning)
	float SpawnDelayRangeHigh;

	UFUNCTION(BlueprintPure, Category = Spawnning)
	FVector GetRandomPointInVolume();

	virtual void Tick(float deltaTime) override;

private:
	float GetRandomSpawnDelay();

	float SpawnDelay;

	void SpawnPickup();

	float SpawnTime;

};