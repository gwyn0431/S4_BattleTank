// Copyright � gwyn0431 

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	if (!LeftTrack || !RightTrack) 
	{ 
		UE_LOG(LogTemp, Error, TEXT("Tracks was't initialized properly, probably not able to move."));
		TracksInitialised = false; 
	}
}


void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call Super as we're replacing the functionallity 

	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto MovementThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	MoveTank(MovementThrow);

	auto RotationThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	RotateTank(RotationThrow);
}

void UTankMovementComponent::MoveTank(float Throw)
{
	if (!TracksInitialised) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::RotateTank(float Throw)
{
	if (!TracksInitialised) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}
