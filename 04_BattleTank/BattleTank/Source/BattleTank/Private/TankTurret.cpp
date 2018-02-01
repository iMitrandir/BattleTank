// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "BattleTank.h"




void UTankTurret::Rotate(float ReletiveSpeed)
{

	//Move te barrel the right ammount THIS frame
	//give the max elevation speed, and the frame time
	float Speed = FMath::Clamp<float>(ReletiveSpeed, -1.0f, 1.0f);
	auto RotationChange = Speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw+ RotationChange;
	
	SetRelativeRotation(FRotator(0.0f, RawNewRotation, 0.0f));

	
}
