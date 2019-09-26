// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EventSystem.generated.h"

/**
 *
 */
UCLASS(Blueprintable, BlueprintType)
class UE4FRAMEWORK_API UEventSystem : public UObject
{
	GENERATED_BODY()

public:
	UEventSystem();

	virtual void BeginDestroy() override;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EventSystem")
	UObject* GetEventFromClass(class UClass* Class, class UObject* Outer = NULL);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EventSystem")
	int GetEventCount();

private:
	// UE4 Garbage Collection only counts references to UObjects that are UPROPERTY().
	// Objects belonging to this class will never be saved to disk.
	UPROPERTY(Transient)
	TMap<class UClass*, class UObject*> Events;
};
