// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonCharacter.h"
#include "MonsterCharacter.generated.h"

/**
 * 
 */
UCLASS()
class FPS_SAMPLE_API AMonsterCharacter : public ACommonCharacter
{
	GENERATED_BODY()

public:
	AMonsterCharacter();

public:
	virtual void OnDead(ACommonCharacter* AttackerCharacter);

	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable)
	void OnAttack();

	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable)
	void OnOverlappedCharacter(ACommonCharacter* Target);

	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable)
	void OffOverlappedCharacter(ACommonCharacter* Target);

private:
	UPROPERTY(EditAnywhere, Category = Reward, meta = (AllowPrivateAccess = "true"))
	int Reward = 10;

	TArray<ACommonCharacter*> TargetCharacterList;
};
