// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CommonCharacter.generated.h"

UCLASS()
class FPS_SAMPLE_API ACommonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACommonCharacter();
	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void VaryHp(const int& Value);

	UFUNCTION()
	void OnRep_Hp();


	UPROPERTY(Transient, Replicated, ReplicatedUsing = OnRep_Hp)
	int CurrentHp = 0;

	int MaxHp = 10;

private:
	int CharacterKey = 0;
};
