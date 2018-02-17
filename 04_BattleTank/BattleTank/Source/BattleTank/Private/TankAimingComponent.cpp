// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; //TODO Should this realy tick?

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}
void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


}

void UTankAimingComponent::AimAt(FVector HitLocation, float LounchSpeed)
{
	if (!Turret) { return; }
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	//calculate the out lounch velocity

	if (UGameplayStatics::SuggestProjectileVelocity
		(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LounchSpeed,
		false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace
			)
		)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);

		
	}
	/*else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f No Aim sollution found "), Time);
	}*/


}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirrection)
{
	// work-out the difference between current barrel rotation and aim dirrection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirrection.Rotation();
	auto DeltaBarrelRotator = AimAsRotator - BarrelRotator;
	auto DeltaTurretRotator = AimAsRotator - TurretRotator;

	Barrel->Elevate(DeltaBarrelRotator.Pitch); 
	Turret->Rotate(DeltaTurretRotator.Yaw);
	//UE_LOG(LogTemp, Warning, TEXT("Rotate at %f  "), DeltaTurretRotator.Yaw);
}


	