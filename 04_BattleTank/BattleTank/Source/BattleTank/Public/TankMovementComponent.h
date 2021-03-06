// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;
/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UTankMovementComponent();
	
	UFUNCTION(BlueprintCallable)
	void IntentMoveForward(float Trow);

	UFUNCTION(BlueprintCallable)
	void Initialise(UTankTrack*LeftTrackToSet, UTankTrack*RightTrackToSet);
	
private:
	UTankTrack * LeftTrack = nullptr;
	UTankTrack * RightTrack = nullptr;

};
