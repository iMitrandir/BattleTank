// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankMovementComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);


	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel * BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret * TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
		UTankMovementComponent* TankMovementComponent = nullptr;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LounchSpeed=4000; 

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	// local barrel refernce for spawning
	UTankBarrel* Barrel = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;
};
