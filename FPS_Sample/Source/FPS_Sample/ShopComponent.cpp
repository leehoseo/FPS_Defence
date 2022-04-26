// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SampleHUD.h"

// Sets default values for this component's properties
UShopComponent::UShopComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UShopComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	ASampleHUD* Hud = Cast<ASampleHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	for (FShopItemData& Data : ItemDataList)
	{
		Hud->CreateShopItem(&Data);
	}
}


// Called every frame
void UShopComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

