// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "BattleTank.h"




void UTankTurret::Elevate(float ReletiveSpeed)
{

	//Move te barrel the right ammount THIS frame
	//give the max elevation speed, and the frame time
	float Speed = FMath::Clamp<float>(ReletiveSpeed, -1.0f, 1.0f);
	auto ElevationChange = Speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Yaw + ElevationChange;

	float Elevation = FMath::Clamp<float>(RawNewElevation, 0.0f, 180.0f);
	
	SetRelativeRotation(FRotator(Elevation, 0.0f, 0.0f));

	//UE_LOG(LogTemp, Warning, TEXT("Rotate at %f  "), RawNewElevation);
}
