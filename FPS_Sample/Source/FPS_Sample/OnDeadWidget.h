// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonWidget.h"
#include "OnDeadWidget.generated.h"

class AFPS_SampleCharacter;
/**
 * 
 */
UCLASS()
class FPS_SAMPLE_API UOnDeadWidget : public UCommonWidget
{
	GENERATED_BODY()
public:
	UOnDeadWidget();

	void UpdateInfo(const AFPS_SampleCharacter* SampleCharacter);
};
