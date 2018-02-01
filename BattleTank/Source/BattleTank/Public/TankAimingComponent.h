// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward declaration
class UTankBarrel; 
class UTankTurret;

// enum for aiming status
UENUM()
enum class EFireStatus : uint8
{
	Reloading,
	Aiming,
	Locked
};

// Hold parameters for barrel's properties and Elevate() method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);
 
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFireStatus FireStatus = EFireStatus::Reloading;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveCannonTowards(FVector AimDirection);
};
