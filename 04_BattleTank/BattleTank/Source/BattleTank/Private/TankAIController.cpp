// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"));
	auto PlayerTank = GetPlayerTank();
	APawn* PosessedTank = GetControlledTank();
	if (PosessedTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller %s"), *PosessedTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller nulptr"));
	}

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank can't find PT"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank find %s"), *PlayerTank->GetName());

	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsPlayer();
}

ATank* ATankAIController::GetControlledTank() const
{
	
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerTank)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerTank);
}
void ATankAIController::AimTowardsPlayer()
{
	if (GetPlayerTank())  // если нету плеер танка ничего не делаем
	{
		//TODO move to player

		//Aim tovards the player
		auto PlayerLocation = GetPlayerTank()->GetActorLocation();
		GetControlledTank()->AimAt(PlayerLocation);

		
	}

	
}


