// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterCharacter.h"
#include "InventoryComponent.h"

AMonsterCharacter::AMonsterCharacter()
{

}

void AMonsterCharacter::OnDead(ACommonCharacter* AttackerCharacter)
{
	UInventoryComponent* Inventory = AttackerCharacter->FindComponentByClass<UInventoryComponent>();
	if (nullptr != Inventory)
	{
		Inventory->VaryMoney(Reward);
		Destroy();
	}
}