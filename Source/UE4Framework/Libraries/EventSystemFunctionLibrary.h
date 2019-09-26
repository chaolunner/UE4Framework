// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EventSystemFunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class UE4FRAMEWORK_API UEventSystemFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EventSystem")
	static class UEventSystem* GetEventSystem();
	UFUNCTION(BlueprintCallable, Category = "EventSystem")
	static UObject* GetEventFromClass(class UClass* Class, class UObject* Outer = NULL);
};
