// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonWidget.h"
#include "ShopWidget.generated.h"

class UListView;
struct FShopItemData;
/**
 * 
 */
UCLASS()
class FPS_SAMPLE_API UShopWidget : public UCommonWidget
{
	GENERATED_BODY()
	
public:
	UShopWidget();

	void CreateShopItem(FShopItemData* ItemData);

	UPROPERTY(meta = (BIndWIdget))
	UListView* List_Shop = nullptr;
};
