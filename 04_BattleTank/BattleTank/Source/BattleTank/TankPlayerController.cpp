// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"));

	APawn* PosessedTank = GetControlledTank();
	if (PosessedTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller %s"), *PosessedTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller nulptr"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocationOUT) const
{
/*	
	//we have strat and end of the vector. 
	//Start - location of point conwertetd from screen to world space,
	// End - some distance
		//if this vector penetrate something
			//- get location of hit
			//- generert hit result
	FHitResult* Hit;
	if (GetHitResultAtScreenPosition((50.0f, 33.3f), ECC_WorldStatic, true, Hit) == true)
	{
		HitLocationOUT = Hit->GetActor()->GetActorLocation();
	}
	
	//APlayerController::DeprojectScreenPositionToWorld(33.3,33.3,)

	*/
	HitLocationOUT = FVector(1);
	return true;
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; } // если плеер танк не найден то выходим из функции ничего не делая
	
	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT(" Hit Location: %s "), *HitLocation.ToString());
		//Get world location of linetrace through crosshair
		//if it hits the landscape
		//tell controller tank to aim at this point

	}

	
	
}

ATank* ATankPlayerController::GetControlledTank() const
{
	
	return Cast<ATank>(GetPawn());
}




