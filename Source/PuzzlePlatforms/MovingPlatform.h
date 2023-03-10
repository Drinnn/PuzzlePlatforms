// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;
	UPROPERTY(EditAnywhere)
	float Speed = 50;

	void AddActiveTrigger();
	void RemoveActiveTrigger();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	FVector GlobalStartingLocation;
	FVector GlobalTargetLocation;

	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 0;
};
