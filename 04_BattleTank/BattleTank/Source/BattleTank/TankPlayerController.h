// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

		ATank* GetControlledTank() const;
public:

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool GetSightRayHitLocation(FVector& HitLocationOUT) const;
	
private:

	//start the tank moving tha barel tovards crosshair 
	void AimTowardsCrosshair();


};
