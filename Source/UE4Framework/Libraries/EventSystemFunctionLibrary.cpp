// Fill out your copyright notice in the Description page of Project Settings.


#include "EventSystemFunctionLibrary.h"
#include "UE4Framework/Core/GameInstanceAssembler.h"
#include "UE4Framework/Core/EventSystem.h"

UEventSystem* UEventSystemFunctionLibrary::GetEventSystem()
{
	UGameInstanceAssembler* instance = UGameInstanceAssembler::GetInstance();
	if (instance)
	{
		return instance->GetEventSystem();
	}
	return NULL;
}

UObject* UEventSystemFunctionLibrary::GetEventFromClass(UClass* Class, UObject* Outer)
{
	UEventSystem* eventSystem = GetEventSystem();
	if (eventSystem)
	{
		return eventSystem->GetEventFromClass(Class, Outer);
	}
	return NULL;
}
