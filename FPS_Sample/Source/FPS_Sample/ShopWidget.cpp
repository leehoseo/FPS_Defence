// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopWidget.h"
#include "Components/ListView.h"
#include "ShopItemWidget.h"
#include "ShopComponent.h"

UShopWidget::UShopWidget()
{

}

void UShopWidget::NativeConstruct()
{
	Super::NativeConstruct();

	for (FShopItemData& Data : ItemDataList)
	{
		UShopItemWidget* ItemWidget = CreateWidget<UShopItemWidget>(GetWorld(), OriginClass);
		if (nullptr != ItemWidget)
		{
			ItemWidget->Init(&Data);
			List_Shop->AddItem(ItemWidget);
		}
	}
}

void UShopWidget::CreateShopItem(FShopItemData* ItemData)
{
	//UShopItemWidget* ItemWidget = CreateWidget<UShopItemWidget>(GetOwningPlayer(), OriginClass);

	//if (nullptr != ItemWidget)
	//{
	//	ItemWidget->Init(ItemData);
	//	List_Shop->AddItem(ItemWidget);
	//}
}
