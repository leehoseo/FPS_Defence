// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonWidget.h"
#include "ShopWidget.generated.h"

class UListView;
class UShopComponent;
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
	virtual void NativeConstruct() override;

	void CreateShopItem(FShopItemData* ItemData);

	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable, Category = "Shop")
	void AttachShopComponent(UShopComponent* NewShopComponet);

	/** Projectile class to spawn */
	UPROPERTY(EditAnywhere, Category = "Shop")
	TSubclassOf<class UShopItemWidget> OriginClass;

	UPROPERTY(EditAnywhere, Category = "Shop")
	UShopComponent* ShopComponet = nullptr;

	UPROPERTY(meta = (BIndWIdget))
	UListView* List_Shop = nullptr;
};
