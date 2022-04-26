// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopItemWidget.h"
#include "ShopWIdget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "SampleHUD.h"
#include "InventoryComponent.h"
#include "CommonCharacter.h"

UShopItemWidget::UShopItemWidget()
{

}

//void UShopItemWidget::NativeConstruct()
//{
//	 Super::NativeConstruct()
//}
//
void UShopItemWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);
	UShopItemWidget* NewItem = Cast<UShopItemWidget>(ListItemObject);
	Data = NewItem->Data;

	if (nullptr == Data)
	{
		return;
	}

	{
		FString Text_Title;
		Text_Title.Append("Desc : ");
		Text_Title.Append(Data->Desc);

		TextBlock_Title->SetText(FText::FromString(Text_Title));
	}
		
	{
		FString Text_Price;
		Text_Price.Append("Price : ");
		Text_Price.Append(FString::FromInt(Data->Price));

		TextBlock_Price->SetText(FText::FromString(Text_Price));
	}

	{
		Button_Buy->OnPressed.AddUniqueDynamic(this, &UShopItemWidget::OnBuy);
	}
	
}

void UShopItemWidget::NativeOnItemSelectionChanged(bool bIsSelected)
{
}

void UShopItemWidget::Init(FShopItemData* ItemData)
{
	Data = ItemData;
}

void UShopItemWidget::OnBuy()
{
	APawn* GetPawn = UGameplayStatics::GetPlayerController(this, 0)->GetPawn();

	UInventoryComponent* InventoryComponet = GetPawn->FindComponentByClass<UInventoryComponent>();

	if (false == InventoryComponet->VaryMoney(-Data->Price))
	{
		return;
	}

	switch (Data->Type)
	{
	case EItemType::eEItemType_Weapon:

		break;
	case EItemType::eEItemType_PowerBullet:


		break;
	case EItemType::eEItemType_Hp:
		ACommonCharacter* Character = Cast<ACommonCharacter>(GetPawn);
		Character->VaryHp(Data->Param);

		break;
	}
}
