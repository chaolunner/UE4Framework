// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameInstanceAssembler.generated.h"

/**
 *
 */
UCLASS(Blueprintable, BlueprintType)
class UE4FRAMEWORK_API UGameInstanceAssembler : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Shutdown() override;

	UFUNCTION()
	static UGameInstanceAssembler* GetInstance();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EventSystem")
	class UEventSystem* GetEventSystem();

private:
	// UE4 Garbage Collection only counts references to UObjects that are UPROPERTY().
	// Objects belonging to this class will never be saved to disk.
	UPROPERTY(Transient)
	class UEventSystem* EventSystemInstance;
};
