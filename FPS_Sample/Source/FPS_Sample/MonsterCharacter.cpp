// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterCharacter.h"
#include "InventoryComponent.h"
#include "HitComponent.h"

AMonsterCharacter::AMonsterCharacter()
{
	TeamNo = 1;
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

void AMonsterCharacter::OnAttack()
{
	TArray<ACommonCharacter*> AttackedCharacterList;

	for (ACommonCharacter* Target : TargetCharacterList)
	{
		if (true == AttackedCharacterList.Contains(Target))
		{
			continue;
		}

		if (TeamNo == Target->TeamNo)
		{
			continue;
		}

		UHitComponent* HitComponent = Target->FindComponentByClass<UHitComponent>();
		if (nullptr != HitComponent)
		{
			HitComponent->OnHit(this);
		}

		AttackedCharacterList.AddUnique(Target);
	}
}

void AMonsterCharacter::OnOverlappedCharacter(ACommonCharacter* Target)
{
	TargetCharacterList.Add(Target);
}

void AMonsterCharacter::OffOverlappedCharacter(ACommonCharacter* Target)
{
	TargetCharacterList.Remove(Target);
}
