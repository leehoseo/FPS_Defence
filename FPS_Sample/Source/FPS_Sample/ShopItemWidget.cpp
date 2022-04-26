// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopItemWidget.h"
#include "ShopComponent.h"
#include "Components/TextBlock.h"

UShopItemWidget::UShopItemWidget()
{

}

void UShopItemWidget::Init(FShopItemData* ItemData)
{
	TextBlock_Title->SetText(FText::FromString(ItemData->Desc));
}