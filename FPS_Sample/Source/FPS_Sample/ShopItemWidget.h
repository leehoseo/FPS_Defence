// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonWidget.h"
#include "ShopItemWidget.generated.h"

class UTextBlock;
struct FShopItemData;
/**
 * 
 */
UCLASS()
class FPS_SAMPLE_API UShopItemWidget : public UCommonWidget
{
	GENERATED_BODY()
	
public:
	UShopItemWidget();

	void Init(FShopItemData* ItemData);

	UPROPERTY(meta = (BIndWIdget))
	UTextBlock* TextBlock_Title = nullptr;
};
