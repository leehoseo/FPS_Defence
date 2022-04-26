// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopWidget.h"
#include "Components/ListView.h"
#include "ShopItemWidget.h"
#include "ShopComponent.h"

UShopWidget::UShopWidget()
{

}

void UShopWidget::CreateShopItem(FShopItemData* ItemData)
{
	UShopItemWidget* ItemWidget = CreateWidget<UShopItemWidget>(this, UShopItemWidget::StaticClass());

	ItemWidget->Init(ItemData);
	List_Shop->AddItem(ItemWidget);
}
