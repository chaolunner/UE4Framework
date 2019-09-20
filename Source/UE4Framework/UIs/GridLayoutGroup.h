// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/GridPanel.h"
#include "GridLayoutGroup.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnValueChangedEvent);

/**
 *
 */
UCLASS()
class UE4FRAMEWORK_API UGridLayoutGroup : public UGridPanel
{
	GENERATED_BODY()

public:

	UGridLayoutGroup();

	virtual void SynchronizeProperties() override;

	UPROPERTY(BlueprintAssignable, Category = "Event")
	FOnValueChangedEvent OnValueChanged;

	UPROPERTY(EditAnywhere, Category = "Layout")
	FVector2D CellSize;

	UFUNCTION(BlueprintCallable, Category = "Custom")
	TArray<class USizeBox*> GetAllCells();
	UFUNCTION(BlueprintCallable, Category = "Custom")
	void SetCellSize(class USizeBox* Element);
};
