// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SampleHUD.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	ASampleHUD* Hud = Cast<ASampleHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	Hud->AttachInventory(this);
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UInventoryComponent::VaryMoney(const int Value)
{
	int NewMoney = CurrentMoney + Value;

	if (NewMoney < 0)
	{
		return false;
	}

	CurrentMoney = NewMoney;

	MoneyWidgetAction.Broadcast(this);
	return true;
}

const int UInventoryComponent::GetCurrentMoney() const
{
	return CurrentMoney;
}