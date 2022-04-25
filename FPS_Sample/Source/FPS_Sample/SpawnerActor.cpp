// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerActor.h"
#include "CommonCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/Array.h"
#include "Engine/World.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ASpawnerActor::ASpawnerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnerActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (0 == SpawnDataList.Num())
	{
		FSpawnData CurrentData = SpawnDataList[0];

		SpawnTick = CurrentData.SpawnCycle;
		NextDataTick = CurrentData.NextLevelCycle;
	}
}

// Called every frame
void ASpawnerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const int Size = SpawnDataList.Num();

	if (Size <= CurrentLevel)
	{
		return;
	}

	FSpawnData CurrentData = SpawnDataList[CurrentLevel];

	NextDataTick -= DeltaTime;
	if (NextDataTick < 0)
	{
		++CurrentLevel;
		NextDataTick = CurrentData.NextLevelCycle;
	}

	SpawnTick -= DeltaTime;

	if (SpawnTick < 0 )
	{
		if (true == CurrentData.IsActive)
		{
			for (int index = 0; index < CurrentData.SpawnNum; ++index)
			{
				ACommonCharacter* NewActor = CloneActor();

				// 위치 랜덤 수정
			}
		}

		SpawnTick = CurrentData.SpawnCycle;
	}
}

ACommonCharacter* ASpawnerActor::CloneActor()
{
	FActorSpawnParameters Params;
	//Params.bDeferConstruction = true; // We defer construction so that we set ParentComponentActor prior to component registration so they appear selected
	//Params.bAllowDuringConstructionScript = true;
	//Params.OverrideLevel = GetOwner()->GetLevel();
	//Params.Name = "Monster";
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	Params.Template = OriginActor->GetDefaultObject<AActor>();
	Params.Owner = this;

	FVector Location = FindNonOverlappedLocation(GetActorLocation(), 0);
	const FRotator& Rotation = GetActorRotation();

	Location.Z += OriginActor->GetDefaultObject<AActor>()->GetSimpleCollisionHalfHeight();

	ACommonCharacter* Result =  GetWorld()->SpawnActor<ACommonCharacter>(OriginClass, Location, Rotation, Params);

	Result->SpawnDefaultController();

	return Cast<ACommonCharacter>(Result);
}

const FVector ASpawnerActor::FindNonOverlappedLocation(const FVector& InLocation, const int CallStack)
{
	if (10 <= CallStack)
	{
		return InLocation;
	}

	FVector Location = InLocation;

	float RangeXValue = RangeX / Constant;
	float RangeYValue = RangeY / Constant;
	float RandX = FMath::RandRange(-RangeXValue, RangeXValue) * Constant;
	float RandY = FMath::RandRange(-RangeYValue, RangeYValue) * Constant;
	Location.X += RandX;
	Location.Y += RandY;

	FHitResult OutHit;
	{
		FVector Start = Location;
		Start.Z += 1000.f;

		FVector TargetVector = Location - Start;
		TargetVector.Normalize();

		FVector End = Start + (TargetVector * 5000.f);

		FCollisionQueryParams CollisionParams;
		bool IsHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_WorldStatic, CollisionParams);

		EObjectFlags::RF_Transactional;
		if (true == IsHit)
		{
			// 이동 가능한 것이면위치를 다시 잡음
			if (RF_Transactional == OutHit.GetActor()->GetFlags())
			{
				FVector NewMoveVector = Location - OutHit.Location;
				NewMoveVector.Normalize();

				int RandConstant = 10 + ( FMath::RandRange(0, 10) * Constant);

				FVector NewLocation = OutHit.Location + (NewMoveVector.Normalize() * RandConstant);
				return FindNonOverlappedLocation(NewLocation , CallStack + 1);
			}

			Location = OutHit.Location;
		}

		return Location;
	}
}