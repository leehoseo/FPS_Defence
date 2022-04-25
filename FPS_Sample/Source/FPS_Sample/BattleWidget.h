// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonWidget.h"
#include "BattleWidget.generated.h"

class UTextBlock;
class UTP_WeaponComponent;
/**
 * 
 */
UCLASS()
class FPS_SAMPLE_API UBattleWidget : public UCommonWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BIndWIdget))
	UTextBlock* TextBlock_Bullet = nullptr;

	void UpdateBullet( const int MaxBullet, const int CurrentBullet );

	virtual void UpdateWidget(const UTP_WeaponComponent* WeaponComponent);
};
