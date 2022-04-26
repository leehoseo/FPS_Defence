// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleWidget.h"
#include "UMG/Public/Components/TextBlock.h"
#include "GameFramework/Actor.h"

void UBattleWidget::UpdateBullet(const int MaxBullet, const int CurrentBullet)
{
	if (0 == MaxBullet)
	{
		TextBlock_Bullet->SetText(FText::FromString(""));
		return;
	}

	FString Text_Bullet;
	Text_Bullet.Append(FString::FromInt(CurrentBullet));
	Text_Bullet.Append( " / ");
	Text_Bullet.Append(FString::FromInt(MaxBullet));

	TextBlock_Bullet->SetText( FText::FromString(Text_Bullet));
}

void UBattleWidget::UpdateMoney(const int Money)
{
	FString Text_Money;
	Text_Money.Append("Money : ");
	Text_Money.Append(FString::FromInt(Money));

	TextBlock_Money->SetText(FText::FromString(Text_Money));
}

void UBattleWidget::UpdateHp(const int Hp)
{
	FString Text_Hp;
	Text_Hp.Append("HP : ");
	Text_Hp.Append(FString::FromInt(Hp));

	TextBlock_Hp->SetText(FText::FromString(Text_Hp));
}