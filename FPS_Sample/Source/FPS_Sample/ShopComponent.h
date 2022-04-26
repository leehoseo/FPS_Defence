// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShopComponent.generated.h"

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
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_SAMPLE_API UShopComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShopComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category = "ItemData")
	TArray<FShopItemData> ItemDataList;
};
