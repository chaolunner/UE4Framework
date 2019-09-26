// Fill out your copyright notice in the Description page of Project Settings.


#include "DropResetEvent.h"

void UDropResetEvent::SendResetEvent(int LoseHealth)
{
	if (OnReset.IsBound())
	{
		OnReset.Broadcast(LoseHealth);
	}
}

int UDropResetEvent::GetCount()
{
	int count = 0;
	count += OnEvent.IsBound() ? OnEvent.GetAllObjects().Num() : 0;
	count += OnReset.IsBound() ? OnReset.GetAllObjects().Num() : 0;
	return count;
}
