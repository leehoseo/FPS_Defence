// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SampleHUD.generated.h"

class UCommonWidget;
class UTP_WeaponComponent;
class UInventoryComponent;
class ASampleGameState;

/**
 * 
 */
UCLASS()
class FPS_SAMPLE_API ASampleHUD : public AHUD
{
	GENERATED_BODY()

public:
	void BeginPlay() override;
	/** Ends gameplay for this component. */
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere, Category = "Widget")
	FName StartWidget;

	UPROPERTY(EditAnywhere, Category = "Widget")
	TMap<FName, TSubclassOf<UCommonWidget>> WidgetList;


	UFUNCTION(BlueprintCallable)
	void ChangeWidget(FName WidgetKey);
	bool IsExistWidget(FName WidgetKey) const;

	UFUNCTION(BlueprintCallable)
	UCommonWidget* GetCurrentWidget();

	UFUNCTION()
	void UpdateBullet(const UTP_WeaponComponent* WeaponComponent);	
	
	UFUNCTION()
	void UpdateMoney(const UInventoryComponent* InventoryComponent);

	UFUNCTION()
	void UpdateTimer(const int Timer);

	void AttachWeapon(UTP_WeaponComponent* WeaponComponent);
	void AttachInventory(UInventoryComponent* InventoryComponent);
	void AttachTimer(ASampleGameState* SampleGameState);

private:
	UCommonWidget* CurrentWidget = nullptr;
	UTP_WeaponComponent* TargetWeaponComponent = nullptr;
	UInventoryComponent* TargetInventoryComponent = nullptr;
	ASampleGameState* TargetGameState = nullptr;
};
