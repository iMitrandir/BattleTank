// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "TankBarrel.generated.h"


UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	//-1 max downward speed, 1 max up movement speed
	void Elevate(float ReletiveSpeed);
	
private:

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20; //TODO Sensible defaults

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 40; 

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = 0; 



	
};
