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

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocationOUT)
{
	//find the crosshair position
	FVector2D ScreenSize = GetGameViewportSize();
	FVector2D CrosshairPos = FVector2D((ScreenSize.X*CrosshairXLocation), (ScreenSize.Y*CrosshairYLocation));

	// deproject the screen position fo the crosshair to world direction
	FVector WorldDir;
	if (GetLookDirection(CrosshairPos, WorldDir))
	{
		
		//linetrease along that look direction? and see what we hit ( up to max renge - start\end hit result)
		FHitResult HitResult;  //The trace data is stored here
		FVector Start = PlayerCameraManager->GetCameraLocation();
		FVector End = Start + WorldDir * LineTraceRange; //10000 units in facing direction of PC (10000 units in front of the camera)
		GetWorld()->LineTraceSingleByChannel(
			HitResult,
			Start,
			End,
			ECollisionChannel::ECC_Visibility);
			UE_LOG(LogTemp, Warning, TEXT(" HitData: %s "), *HitResult.ToString());
			HitLocationOUT = HitResult.Location;
			return true;  
	

		
	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D CrosshairPos, FVector& LookDir )
{
	
	FVector CameraWorldLoc;
	return DeprojectScreenPositionToWorld(
		CrosshairPos.X,
		CrosshairPos.Y,
		CameraWorldLoc,
		LookDir);

	
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; } // ���� ����� ���� �� ������ �� ������� �� ������� ������ �� �����
	
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

FVector2D ATankPlayerController::GetGameViewportSize()
{
	FVector2D Result = FVector2D(1, 1);

	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize( /*out*/Result);
	}

	return Result;
}



