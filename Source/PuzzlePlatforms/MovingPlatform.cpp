// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	GlobalStartingLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);

	if(HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);	
	}
}


void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
 
	if(HasAuthority())
	{
		FVector Location = GetActorLocation();
		const float JourneyLength = (GlobalTargetLocation - GlobalStartingLocation).Size();
		const float JourneyTraveled = (Location - GlobalStartingLocation).Size();
		if(JourneyTraveled >= JourneyLength)
		{
			const FVector Swap = GlobalStartingLocation;
			GlobalStartingLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;
		}
		const FVector Direction = (GlobalTargetLocation - GlobalStartingLocation).GetSafeNormal();
		Location += Direction * Speed * DeltaTime;
		SetActorLocation(Location);
	}
}
