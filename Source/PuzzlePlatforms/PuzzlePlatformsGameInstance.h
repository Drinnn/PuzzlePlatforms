// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	TSubclassOf<UUserWidget> MenuClass;

public:
	explicit UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer);
	virtual void Init() override;

	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(Exec)
	void Host() const;

	UFUNCTION(Exec)
	void Join(const FString& Address) const;
};
