// Copyright © gwyn0431 

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
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFireStatus FireStatus = EFireStatus::Reloading;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel * Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	void MoveCannonTowards(FVector AimDirection);
};
