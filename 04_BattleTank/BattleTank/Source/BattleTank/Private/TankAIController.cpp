// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "BattleTank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	AimTowardsPlayer(ControlledTank, PlayerTank);
	ControlledTank->Fire();
}

void ATankAIController::AimTowardsPlayer(ATank* ControlledTank, ATank* PlayerTank)
{
	if (PlayerTank)  // если нету плеер танка ничего не делаем
	{
		//TODO move to player

		//Aim tovards the player
		auto PlayerLocation = PlayerTank->GetActorLocation();
		ControlledTank->AimAt(PlayerLocation);

		
	}

	
}


