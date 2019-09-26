// Fill out your copyright notice in the Description page of Project Settings.


#include "EventSystem.h"
#include "Engine.h"

UEventSystem::UEventSystem()
{
}

void UEventSystem::BeginDestroy()
{
	Super::BeginDestroy();
}

UObject* UEventSystem::GetEventFromClass(UClass* Class, UObject* Outer)
{
	// Outer set to current world can make object be destroy with scene loaded.
	UWorld* World = GEngine->GetWorldFromContextObjectChecked(Outer ? Outer : this);
	if (!Events.Contains(Class))
	{
		Events.Add(Class, NewObject<UObject>(World, Class));
	}
	if (!Events[Class] || !Events[Class]->IsValidLowLevel())
	{
		Events[Class] = NewObject<UObject>(World, Class);
	}
	return Events[Class];
}

int UEventSystem::GetEventCount()
{
	int count = 0;
	for (auto kvp : Events)
	{
		if (kvp.Value && kvp.Value->IsValidLowLevel())
		{
			count++;
		}
	}
	return count;
}
