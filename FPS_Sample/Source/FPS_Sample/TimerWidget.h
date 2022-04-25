// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonWidget.h"
#include "TimerWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class FPS_SAMPLE_API UTimerWidget : public UCommonWidget
{
	GENERATED_BODY()
	
public:
	UTimerWidget();
	void UpdateTimer(int Timer);


	UPROPERTY(meta = (BIndWIdget))
	UTextBlock* TextBlock_Timer = nullptr;
};
