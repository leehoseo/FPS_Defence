// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleHUD.h"
#include "CommonWidget.h"
#include "Kismet/GameplayStatics.h"
#include "TP_WeaponComponent.h"

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
        TargetWeaponComponent->BulletWidgetAction.RemoveDynamic(this, &ASampleHUD::UpdateWidget);
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

void ASampleHUD::UpdateWidget(const UTP_WeaponComponent* WeaponComponent)
{
    CurrentWidget->UpdateWidget(WeaponComponent);
}

void ASampleHUD::AttachWeapon(UTP_WeaponComponent* WeaponComponent)
{
    TargetWeaponComponent = WeaponComponent;
    TargetWeaponComponent->BulletWidgetAction.AddDynamic(this, &ASampleHUD::UpdateWidget);
}
