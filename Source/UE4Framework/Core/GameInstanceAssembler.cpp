// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstanceAssembler.h"
#include "Engine.h"
#include "UE4Framework/Core/EventSystem.h"

void UGameInstanceAssembler::Shutdown()
{
	Super::Shutdown();
}

UGameInstanceAssembler* UGameInstanceAssembler::GetInstance()
{
	UGameInstanceAssembler* instance = NULL;

	if (GEngine)
	{
		FWorldContext* context = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport);
		instance = Cast<UGameInstanceAssembler>(context->OwningGameInstance);
	}

	return instance;
}

UEventSystem* UGameInstanceAssembler::GetEventSystem()
{
	if (!EventSystemInstance || !EventSystemInstance->IsValidLowLevel())
	{
		EventSystemInstance = NewObject<UEventSystem>(this, FName("EventSystem"));
	}
	return EventSystemInstance;
}
