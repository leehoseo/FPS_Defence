// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SamplePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class FPS_SAMPLE_API ASamplePlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	void VaryMoney(const int& Value) { Money += Value; };

private:
	int Money = 0;
};
