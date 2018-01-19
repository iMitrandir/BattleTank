// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"));

	APawn* PosessedTank = GetControlledTank();
	if (PosessedTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller %s"), *PosessedTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller nulptr"));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	

	return Cast<ATank>(GetPawn());
}


