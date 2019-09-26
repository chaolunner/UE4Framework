// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EventBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEvent);

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class UE4FRAMEWORK_API UEventBase : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable, Category = "EventSystem")
	FOnEvent OnEvent;

	virtual void BeginDestroy() override;

	UFUNCTION(BlueprintCallable, Category = "EventSystem")
	virtual void SendEvent();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EventSystem")
	virtual int GetCount();
};
