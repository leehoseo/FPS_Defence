// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SampleHUD.generated.h"

class UCommonWidget;
/**
 * 
 */
UCLASS()
class FPS_SAMPLE_API ASampleHUD : public AHUD
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Widget")
	FName StartWidget;

	UPROPERTY(EditAnywhere, Category = "Widget")
	TMap<FName, TSubclassOf<UCommonWidget>> WidgetList;


	UFUNCTION(BlueprintCallable)
	void ChangeWidget(FName WidgetKey);
	bool IsExistWidget(FName WidgetKey) const;

	UFUNCTION(BlueprintCallable)
	UCommonWidget* GetCurrentWidget();

private:
	UCommonWidget* CurrentWidget = nullptr;
};
