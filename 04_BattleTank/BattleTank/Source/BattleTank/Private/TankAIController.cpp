// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
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

	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank find %s"), *PlayerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank can't find PT"));
	}

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


