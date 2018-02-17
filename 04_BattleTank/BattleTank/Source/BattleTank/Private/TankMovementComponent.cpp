// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"


UTankMovementComponent::UTankMovementComponent()
{

}

void UTankMovementComponent::IntentMoveForward(float Trow)
{

	UE_LOG(LogTemp, Warning, TEXT("Intend move forward %f "), Trow);
}
