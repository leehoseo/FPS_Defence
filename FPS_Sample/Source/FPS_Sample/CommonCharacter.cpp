// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonCharacter.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ACommonCharacter::ACommonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACommonCharacter::BeginPlay()
{
	CurrentHp = MaxHp;
	Super::BeginPlay();
}

// Called every frame
void ACommonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACommonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACommonCharacter::VaryHp(const int& Value)
{
	int NewHp = CurrentHp + Value;

	if (NewHp < 0 || MaxHp < NewHp )
	{
		return;
	}

	CurrentHp = NewHp;
	NotifyHp(CurrentHp);
}

void ACommonCharacter::OnRep_Hp()
{
	if (IsNetMode(NM_DedicatedServer))
	{
		return;
	}

	// 이벤트들 호출
}

void ACommonCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACommonCharacter, CurrentHp);
}

float ACommonCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	VaryHp(-DamageAmount);

	if (CurrentHp <= 0)
	{
		OnDead(Cast<ACommonCharacter>(DamageCauser));
	}

	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}