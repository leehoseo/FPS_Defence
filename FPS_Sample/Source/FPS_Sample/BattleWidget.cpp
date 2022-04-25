// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleWidget.h"
#include "UMG/Public/Components/TextBlock.h"
#include "TP_WeaponComponent.h"
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

void UBattleWidget::UpdateWidget(const UTP_WeaponComponent* WeaponComponent)
{
	int OutMaxBullet = 0;
	int OutCurrentBullet = 0;
	WeaponComponent->GetBulletInfo(OutMaxBullet, OutCurrentBullet);

	UpdateBullet(OutMaxBullet, OutCurrentBullet);
}