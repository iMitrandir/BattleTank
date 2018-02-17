// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "BattleTank.h"


void UTankTrack::SetThrottle(float Throttle)
{
	auto TankRoot =Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	auto ForceLocation = GetComponentLocation();
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}

