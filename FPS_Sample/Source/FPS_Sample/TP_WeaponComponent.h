// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TP_WeaponComponent.generated.h"

class AFPS_SampleCharacter;
class UTP_WeaponComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWeaponAction, const UTP_WeaponComponent*, _Owner);

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_SAMPLE_API UTP_WeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class AFPS_SampleProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	USoundBase* FireSound;
	
	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAnimMontage* FireAnimation;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector MuzzleOffset;

	/** Sets default values for this component's properties */
	UTP_WeaponComponent();

	/** Attaches the actor to a FirstPersonCharacter */
	UFUNCTION(BlueprintCallable, Category="Weapon")
	void AttachWeapon(AFPS_SampleCharacter* TargetCharacter);

	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable, Category="Weapon")
	void Fire();

	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Reload();

	void GetBulletInfo( int& OutMaxBullet, int& OutCurrentBullet ) const;

	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FWeaponAction BulletWidgetAction;

protected:
	/** Ends gameplay for this component. */
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
		
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	void DecreaseBullet();
	bool IsExistBullet();
	void VaryBullet(int VaryBullet);
private:
	/** The Character holding this weapon*/
	AFPS_SampleCharacter* Character;

	UPROPERTY(EditAnywhere, Category = Item, meta = (AllowPrivateAccess = "true"))
	int MaxBullet = 30;

	int CurrentBullet = 0;
};
