// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MathFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UE4FRAMEWORK_API UMathFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Math|Float")
	static float MinValue();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Math|Float")
	static float MaxValue();
};
