// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonWidget.h"
#include "ShopWidget.generated.h"

class UListView;
struct FShopItemData;


UENUM(BlueprintType)
enum class EItemType :uint8
{
	eEItemType_Weapon		UMETA(DisplayName = "Weapon"),
	eEItemType_PowerBullet	UMETA(DisplayName = "Power Bullet"),
	eEItemType_Hp			UMETA(DisplayName = "Hp"),
};

USTRUCT(BlueprintType)
struct FShopItemData
{
	GENERATED_BODY()

public:
	FShopItemData() {};

	UPROPERTY(EditAnywhere, Category = "ItemData")
		EItemType Type = EItemType::eEItemType_Weapon;

	UPROPERTY(EditAnywhere, Category = "ItemData")
		int Param = 0;

	UPROPERTY(EditAnywhere, Category = "ItemData")
		FString Desc;

	UPROPERTY(EditAnywhere, Category = "ItemData")
		int Price;
};

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

	/** Projectile class to spawn */
	UPROPERTY(EditAnywhere, Category = "Shop")
	TSubclassOf<class UShopItemWidget> OriginClass;

	UPROPERTY(EditAnywhere, Category = "ItemData")
	TArray<FShopItemData> ItemDataList;

	UPROPERTY(meta = (BIndWIdget))
	UListView* List_Shop = nullptr;
};
