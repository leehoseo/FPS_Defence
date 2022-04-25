// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleGameState.h"
#include "Kismet/GameplayStatics.h"
#include "SampleHUD.h"

ASampleGameState::ASampleGameState()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ASampleGameState::BeginPlay()
{
	AGameState::BeginPlay();

	ASampleHUD* Hud = Cast<ASampleHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	Hud->AttachTimer(this);
}

void ASampleGameState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentPlayTime += DeltaTime;

	TimerWidgetAction.Broadcast(CurrentPlayTime);
}

const int ASampleGameState::GetEndTime() const
{
	return EndTime;
}
