#pragma once

#include "GameFramework/Actor.h"
#include "Spawnvolume.generated.h"

UCLASS()
class ASpawnVolume: public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleInstanceOnly, Category = Spawnning)
	TSubobjectPtr<UBoxComponent> WhereToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawnning)
	float SpawnDelayRangeLow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawnning)
	float SpawnDelayRangeHigh;

	UPROPERTY(BlueprintPure, Category = Spawnning)
	FVector GetRandomPointInVolume();

	virtual void Tick(float deltaTime) override;

private:
	float GetRandomSpawnDelay();

	float SpawnDelay;

	void SpawnPickup();

	float SpawnTime;

};