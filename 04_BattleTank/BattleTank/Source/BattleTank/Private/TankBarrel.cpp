// Fill out your copyright notice in the Description page of Project Settings.



#include "TankBarrel.h"
#include "BattleTank.h"




void UTankBarrel::Elevate(float ReletiveSpeed)
{

	//Move te barrel the right ammount THIS frame
	//give the max elevation speed, and the frame time
	float Speed = FMath::Clamp<float>(ReletiveSpeed, -1.0f, 1.0f);
	auto ElevationChange = Speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	float Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
	
}
