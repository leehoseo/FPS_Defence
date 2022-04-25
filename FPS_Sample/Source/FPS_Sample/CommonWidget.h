// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CommonWidget.generated.h"

/**
 * 
 */
class UTP_WeaponComponent;

UCLASS()
class FPS_SAMPLE_API UCommonWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void UpdateWidget(const UTP_WeaponComponent* WeaponComponent) {};
};
