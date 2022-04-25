// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnerActor.generated.h"

class ACommonCharacter;

USTRUCT(BlueprintType)
struct FSpawnData
{
	GENERATED_BODY()

public:
	FSpawnData() {};

	UPROPERTY(EditAnywhere, Category = "ActorSpawner")
	int SpawnCycle = 0;

	UPROPERTY(EditAnywhere, Category = "ActorSpawner")
	int SpawnNum = 0;

	UPROPERTY(EditAnywhere, Category = "ActorSpawner")
	int NextLevelCycle = 0;

	UPROPERTY(EditAnywhere, Category = "ActorSpawner")
	bool IsActive = false;
};

UCLASS()
class FPS_SAMPLE_API ASpawnerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	ACommonCharacter* CloneActor();

	UPROPERTY(EditAnywhere, Category = "ActorSpawner")
	TSubclassOf<ACommonCharacter> OriginActor = nullptr;

	/** Projectile class to spawn */
	UPROPERTY(EditAnywhere, Category = "ActorSpawner")
	TSubclassOf<class ACommonCharacter> OriginClass;

	UPROPERTY(EditAnywhere, Category = "ActorSpawner")
	TArray<FSpawnData> SpawnDataList;

	UPROPERTY(EditAnywhere, Category = "ActorSpawner")
	int CurrentLevel = 0;

	UPROPERTY(EditAnywhere, Category = "ActorSpawner")
	float RangeX = 0.f;

	UPROPERTY(EditAnywhere, Category = "ActorSpawner")
	float RangeY = 0.f;

	UPROPERTY(EditAnywhere, Category = "ActorSpawner")
	float Constant = 3.f;

	float SpawnTick = 0;
	float NextDataTick = 0;
};
