// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/*
*TankTrack is used to set maximum driving force, 
*and to apply forces to the tank
*/

UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//Set throttle between -1 and 1
	UFUNCTION(BlueprintCallable, Category = Input)
			void SetThrottle (float Throttle);
	
private:
	//Set max throttle force in Newtons
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float TrackMaxDrivingForce = 4000000 ;

};
