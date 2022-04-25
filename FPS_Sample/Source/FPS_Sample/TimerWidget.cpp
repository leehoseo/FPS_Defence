// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerWidget.h"
#include "SampleGameState.h"
#include "Engine/World.h"
#include "UMG/Public/Components/TextBlock.h"

UTimerWidget::UTimerWidget()
{

}

void UTimerWidget::UpdateTimer(int Timer)
{
	FString Text_Timer;
	Text_Timer.Append(FString::FromInt(Timer));
	Text_Timer.Append(" Sec ");

	TextBlock_Timer->SetText(FText::FromString(Text_Timer));
}