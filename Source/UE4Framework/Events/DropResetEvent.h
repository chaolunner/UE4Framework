// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Events/EventBase.h"
#include "DropResetEvent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReset, int, LoseHealth);

/**
 * 
 */
UCLASS()
class UE4FRAMEWORK_API UDropResetEvent : public UEventBase
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintAssignable, Category = "EventSystem")
	FOnReset OnReset;

	UFUNCTION(BlueprintCallable, Category = "EventSystem")
	virtual void SendResetEvent(int LoseHealth);
	virtual int GetCount() override;
};
