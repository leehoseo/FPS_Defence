// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "SampleGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTimerAction, int, _Owner);
/**
 * 
 */
UCLASS()
class FPS_SAMPLE_API ASampleGameState : public AGameState
{
	GENERATED_BODY()
public:
	ASampleGameState();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	const int GetEndTime() const;

	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FTimerAction TimerWidgetAction;

private:

	UPROPERTY(EditAnywhere, Category = "GameState")
	int EndTime = 60;

	float CurrentPlayTime = 0;
};
