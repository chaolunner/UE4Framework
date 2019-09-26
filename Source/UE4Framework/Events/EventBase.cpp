// Fill out your copyright notice in the Description page of Project Settings.


#include "EventBase.h"

void UEventBase::BeginDestroy()
{
	Super::BeginDestroy();
}

void UEventBase::SendEvent()
{
	if (OnEvent.IsBound())
	{
		OnEvent.Broadcast();
	}
}

int UEventBase::GetCount()
{
	return OnEvent.IsBound() ? OnEvent.GetAllObjects().Num() : 0;
}
