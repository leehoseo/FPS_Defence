// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "ShopItemWidget.generated.h"

class UTextBlock;
class UButton;
struct FShopItemData;
/**
 * 
 */
UCLASS()
class FPS_SAMPLE_API UShopItemWidget : public UCommonWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
	
public:
	UShopItemWidget();

	//virtual void NativeConstruct() override;

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	virtual void NativeOnItemSelectionChanged(bool bIsSelected) override;

	void Init(FShopItemData* ItemData);


	UPROPERTY(meta = (BIndWIdget))
	UTextBlock* TextBlock_Title = nullptr;

	UPROPERTY(meta = (BIndWIdget))
	UTextBlock* TextBlock_Price = nullptr;

	UPROPERTY(meta = (BIndWIdget))
	UButton* Button_Buy = nullptr;

	UFUNCTION()
	void OnBuy();


	FShopItemData* Data = nullptr;
};
