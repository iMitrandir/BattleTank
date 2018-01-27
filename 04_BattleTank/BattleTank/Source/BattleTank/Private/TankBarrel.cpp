// Fill out your copyright notice in the Description page of Project Settings.



#include "TankBarrel.h"
#include "BattleTank.h"




void UTankBarrel::Elevate(float DegreesPerSecond)
{

	//Move te barrel the right ammount THIS frame
	UE_LOG(LogTemp, Warning, TEXT(" Speed %f "), DegreesPerSecond);
	//give the max elevation speed, and the frame time
}