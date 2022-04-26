// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleHUD.h"
#include "CommonWidget.h"
#include "BattleWidget.h"
#include "Kismet/GameplayStatics.h"
#include "TP_WeaponComponent.h"
#include "InventoryComponent.h"
#include "TimerWidget.h"
#include "OnDeadWidget.h"
#include "SampleGameState.h"
#include "FPS_SampleCharacter.h"
#include "ShopWIdget.h"

void ASampleHUD::BeginPlay()
{
	Super::BeginPlay();
    ChangeWidget(StartWidget);
}

void ASampleHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (TargetWeaponComponent != nullptr)
    {
        // Unregister from the OnUseItem Event
        TargetWeaponComponent->BulletWidgetAction.RemoveDynamic(this, &ASampleHUD::UpdateBullet);
    }

    if (TargetInventoryComponent != nullptr)
    {
        // Unregister from the OnUseItem Event
        TargetInventoryComponent->MoneyWidgetAction.RemoveDynamic(this, &ASampleHUD::UpdateMoney);
    }

    if (TargetGameState != nullptr)
    {
        // Unregister from the OnUseItem Event
        TargetGameState->TimerWidgetAction.RemoveDynamic(this, &ASampleHUD::UpdateTimer);
    }

    if (TargetSampleCharacter != nullptr)
    {
        // Unregister from the OnUseItem Event
        TargetSampleCharacter->ChangeHpAction.RemoveDynamic(this, &ASampleHUD::UpdateHp);
        TargetSampleCharacter->OnDeadAction.RemoveDynamic(this, &ASampleHUD::UpdateOnDead);
    }
}


void ASampleHUD::ChangeWidget(FName WidgetKey)
{
    if (false == IsExistWidget(WidgetKey))
    {
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
        ensureMsgf(0, TEXT("Invalid layer name %s"), *WidgetKey.ToString());
#endif
        return;
    }

    if (true == IsValid(CurrentWidget))
    {
        CurrentWidget->RemoveFromParent();
        CurrentWidget = nullptr;
    }

    CurrentWidget = CreateWidget<UCommonWidget>(GetWorld(), *WidgetList.Find(WidgetKey));

    if (true == IsValid(CurrentWidget))
    {
        CurrentWidget->AddToViewport();
    }
}

bool ASampleHUD::IsExistWidget(FName WidgetKey) const
{
    return WidgetList.Contains(WidgetKey);
}

UCommonWidget* ASampleHUD::GetCurrentWidget()
{
    return CurrentWidget;
}

void ASampleHUD::UpdateBullet(const UTP_WeaponComponent* WeaponComponent)
{
    UBattleWidget* BattleWidget = Cast<UBattleWidget>(CurrentWidget);

    if (nullptr == BattleWidget)
    {
        return;
    }

    int OutMaxBullet = 0;
    int OutCurrentBullet = 0;
    WeaponComponent->GetBulletInfo(OutMaxBullet, OutCurrentBullet);

    BattleWidget->UpdateBullet(OutMaxBullet, OutCurrentBullet);
}

void ASampleHUD::UpdateMoney(const UInventoryComponent* InventoryComponent)
{
    UBattleWidget* BattleWidget = Cast<UBattleWidget>(CurrentWidget);

    if (nullptr == BattleWidget)
    {
        return;
    }

    BattleWidget->UpdateMoney(InventoryComponent->GetCurrentMoney());
}

void ASampleHUD::UpdateTimer(const int Timer )
{
    UTimerWidget* TimerWidget = Cast<UTimerWidget>(WidgetList.Find("Timer")->GetDefaultObject());

    if (nullptr != TimerWidget)
    {
        TimerWidget->UpdateTimer(Timer);
    }
}

void ASampleHUD::UpdateHp(const int Hp)
{
    UBattleWidget* BattleWidget = Cast<UBattleWidget>(CurrentWidget);

    if (nullptr == BattleWidget)
    {
        return;
    }

    BattleWidget->UpdateHp(Hp);
}

void ASampleHUD::UpdateOnDead(const AFPS_SampleCharacter* SampleCharacter)
{
    ChangeWidget("OnDead");
    UOnDeadWidget* OnDeadWidget = Cast<UOnDeadWidget>(CurrentWidget);
    OnDeadWidget->UpdateInfo(SampleCharacter);
}

void ASampleHUD::CreateShopItem(FShopItemData* ShopItemData)
{
    //UCommonWidget* CommonWidget = ;
    UShopWidget* ShopWidget = Cast<UShopWidget>(WidgetList.Find("Shop")->GetDefaultObject());

    if (nullptr != ShopWidget)
    {
        ShopWidget->CreateShopItem(ShopItemData);
    }
}

void ASampleHUD::AttachWeapon(UTP_WeaponComponent* WeaponComponent)
{
    TargetWeaponComponent = WeaponComponent;
    TargetWeaponComponent->BulletWidgetAction.AddDynamic(this, &ASampleHUD::UpdateBullet);
}

void ASampleHUD::AttachInventory(UInventoryComponent* InventoryComponent)
{
    TargetInventoryComponent = InventoryComponent;
    TargetInventoryComponent->MoneyWidgetAction.AddDynamic(this, &ASampleHUD::UpdateMoney);
}

void ASampleHUD::AttachTimer(ASampleGameState* SampleGameState)
{
    TargetGameState = SampleGameState;
    TargetGameState->TimerWidgetAction.AddDynamic(this, &ASampleHUD::UpdateTimer);
}

void ASampleHUD::AttachHp(AFPS_SampleCharacter* SampleCharacter)
{
    TargetSampleCharacter = SampleCharacter;
    TargetSampleCharacter->ChangeHpAction.AddDynamic(this, &ASampleHUD::UpdateHp);
}

void ASampleHUD::AttachOnDead(AFPS_SampleCharacter* SampleCharacter)
{
    TargetSampleCharacter = SampleCharacter;
    TargetSampleCharacter->OnDeadAction.AddDynamic(this, &ASampleHUD::UpdateOnDead);
}
