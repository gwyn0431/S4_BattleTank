// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s"), *(ControlledTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController not possessing a tank."));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation; // Out parameter
	if (GetSightRayHitLocation(OutHitLocation)) // Has "side-effect", is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OutHitLocation.ToString())

		// TODO Tell controlled tank to aim at this point
	}
	
}

// Get world location if linetrace trough crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& out_HitLocation) const
{
	out_HitLocation = FVector(1.0);	
	return true;
}