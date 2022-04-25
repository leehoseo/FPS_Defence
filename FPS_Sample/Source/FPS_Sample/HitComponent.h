// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "HitComponent.generated.h"

class ACommonCharacter;
/**
 * 
 */
UCLASS()
class FPS_SAMPLE_API UHitComponent : public UPrimitiveComponent
{
	GENERATED_BODY()

public:
	UHitComponent();

	void OnHit(ACommonCharacter* AttackerCharacter);

protected:

	/** Called when the game starts */
	virtual void BeginPlay() override;
};
