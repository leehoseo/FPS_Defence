// Fill out your copyright notice in the Description page of Project Settings.


#include "HitComponent.h"


UHitComponent::UHitComponent()
{

}

void UHitComponent::BeginPlay()
{
	UPrimitiveComponent::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UHitComponent::OnBeginOverlap);
}

void UHitComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	//AFPS_SampleCharacter* Character = Cast<AFPS_SampleCharacter>(OtherActor);
	//if (Character != nullptr)
	//{
	//	// Notify that the actor is being picked up
	//	OnPickUp.Broadcast(Character);

	//	// Unregister from the Overlap Event so it is no longer triggered
	//	OnComponentBeginOverlap.RemoveAll(this);
	//}
}