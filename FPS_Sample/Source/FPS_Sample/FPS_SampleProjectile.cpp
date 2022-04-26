// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPS_SampleProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "HitComponent.h"
#include "FPS_SampleCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Math/Vector.h"

AFPS_SampleProjectile::AFPS_SampleProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AFPS_SampleProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AFPS_SampleProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UHitComponent* HitComponent = OtherActor->FindComponentByClass<UHitComponent>();
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		switch (Type)
		{
		case EProjectileType::eProjectileType_Normal:
			OnHitNormal(HitComponent);
			break;

		case EProjectileType::eProjectileType_Power:
			OnHitPower();
			break;
		}
		

		Destroy();
	}
}

void AFPS_SampleProjectile::OnHitNormal(UHitComponent* HitComponent)
{
	if (nullptr != HitComponent)
	{
		HitComponent->OnHit(Character, Power);
	}
}

void AFPS_SampleProjectile::OnHitPower()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACommonCharacter::StaticClass(), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		float Distance = FVector::Dist(GetActorLocation(), Actor->GetActorLocation());

		if (DamagedDistance < Distance)
		{
			continue;
		}

		UHitComponent* HitComponent = Actor->FindComponentByClass<UHitComponent>();
		if (nullptr != HitComponent)
		{
			HitComponent->OnHit(Character, Power);
		}
	}
}
