// Fill out your copyright notice in the Description page of Project Settings.


#include "HitComponent.h"
#include "CommonCharacter.h"
#include "Kismet/GameplayStatics.h"

UHitComponent::UHitComponent()
{

}

void UHitComponent::BeginPlay()
{
	UPrimitiveComponent::BeginPlay();
}

void UHitComponent::OnHit(ACommonCharacter* AttackerCharacter)
{
	// Checking if it is a First Person Character overlapping
	ACommonCharacter* Character = Cast<ACommonCharacter>(GetOwner());
	if ( nullptr != Character)
	{
		TSubclassOf<UDamageType> TempDamageType;
		UGameplayStatics::ApplyDamage(GetOwner(), AttackerCharacter->Power, AttackerCharacter->GetController(), AttackerCharacter, TempDamageType);
	}
}
