// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameInstanceFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UE4FRAMEWORK_API UGameInstanceFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetInstanceFromClass(class UClass* Class, class UObject* &Object);
};
