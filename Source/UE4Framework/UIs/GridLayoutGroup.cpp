// Fill out your copyright notice in the Description page of Project Settings.


#include "GridLayoutGroup.h"
#include "Components/SizeBox.h"

UGridLayoutGroup::UGridLayoutGroup()
{
	CellSize = 100 * FVector2D::UnitVector;
	//UE_LOG(LogTemp, Log, TEXT("%s"), *CellSize.ToString());
}

void UGridLayoutGroup::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	for (USizeBox* element : GetAllCells())
	{
		SetCellSize(element);
		//UE_LOG(LogTemp, Log, TEXT("%s"), *GetNameSafe(element));
	}
}

TArray<USizeBox*> UGridLayoutGroup::GetAllCells()
{
	TArray<USizeBox*> Cells = TArray<USizeBox*>();
	for (int i = 0; i < GetChildrenCount(); i++)
	{
		Cells.Add(dynamic_cast<USizeBox*>(GetChildAt(i)));
	}
	return Cells;
}

void UGridLayoutGroup::SetCellSize(USizeBox* Element)
{
	Element->SetWidthOverride(CellSize.X);
	Element->SetHeightOverride(CellSize.Y);
}
