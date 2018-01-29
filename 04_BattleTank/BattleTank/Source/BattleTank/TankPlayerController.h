// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "Engine.h"
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
 
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

		ATank* GetControlledTank() const;
public:

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool GetSightRayHitLocation(FVector& HitLocationOUT);

	bool GetLookDirection(FVector2D CrosshairPos, FVector& LookDir);


	
private:

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation=0.5;

	UPROPERTY (EditAnywhere)
		float CrosshairYLocation=0.3333;

	UPROPERTY(EditAnywhere)
		int32 LineTraceRange = 100000;
		

	//start the tank moving tha barel tovards crosshair 
	void AimTowardsCrosshair();

	//function that gets viewport size
	FVector2D GetGameViewportSize();

};
