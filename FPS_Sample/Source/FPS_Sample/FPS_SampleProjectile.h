// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPS_SampleProjectile.generated.h"

UENUM(BlueprintType)
enum class EProjectileType :uint8
{
	eProjectileType_Normal	UMETA(DisplayName = "Normal"),
	eProjectileType_Power	UMETA(DisplayName = "Power"),
};


class USphereComponent;
class UHitComponent;
class AFPS_SampleCharacter;
class UProjectileMovementComponent;

UCLASS(config=Game)
class AFPS_SampleProjectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

public:
	AFPS_SampleProjectile();

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void OnHitNormal(UHitComponent* HitComponent);
	void OnHitPower();
	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }

	/** The Character holding this weapon*/
	AFPS_SampleCharacter* Character = nullptr;


	UPROPERTY(EditAnywhere, Category = Item, meta = (AllowPrivateAccess = "true"))
	EProjectileType Type = EProjectileType::eProjectileType_Normal;

	UPROPERTY(EditAnywhere, Category = Item, meta = (AllowPrivateAccess = "true"))
	float Power = 1.f;

	/** Used Only Power Weapon */
	UPROPERTY(EditAnywhere, Category = Item, meta = (AllowPrivateAccess = "true"))
	float DamagedDistance = 0.f;
};

