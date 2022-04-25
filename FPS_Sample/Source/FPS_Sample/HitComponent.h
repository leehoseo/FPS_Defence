// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "HitComponent.generated.h"

/**
 * 
 */
UCLASS()
class FPS_SAMPLE_API UHitComponent : public UPrimitiveComponent
{
	GENERATED_BODY()

public:
	UHitComponent();

protected:

	/** Called when the game starts */
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
