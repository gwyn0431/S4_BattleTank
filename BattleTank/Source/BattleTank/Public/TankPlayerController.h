// Copyright © gwyn0431 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
* Responsible for helping the player aim.
*/
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup") 
	void FoundAimingComponent(UTankAimingComponent* AimCompRef); // Called from TankPlayerController_BP to determine when to create Player UI

	UFUNCTION()
	void OnPossesedTankDeath();

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;

	// Start the tank moving the barrel so that a shot would hit where
	// the crosshair intersects the world
	void AimTowardsCrosshair();

	//Return an OUT parameter, true if hits landscape
	bool GetSightRayHitLocation(FVector& out_HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.333333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	UTankAimingComponent* AimingComponent;
};