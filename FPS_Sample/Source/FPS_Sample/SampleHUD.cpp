// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleHUD.h"
#include "CommonWidget.h"

void ASampleHUD::BeginPlay()
{
	Super::BeginPlay();

    ChangeWidget(StartWidget);
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