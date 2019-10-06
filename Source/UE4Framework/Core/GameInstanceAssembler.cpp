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

bool UGameInstanceAssembler::GetInstanceFromClass(UClass* Class, UObject* &Object)
{
    if (Instances.Contains(Class))
    {
        Object = Instances[Class];
        return true;
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Created!!!!"));
        Object = NewObject<UObject>(this, Class);
        if (Object && Object->IsValidLowLevel())
        {
            Instances.Add(Class, Object);
            return true;
        }
    }
    return false;
}

UEventSystem* UGameInstanceAssembler::GetEventSystem()
{
    UObject* Object = NULL;
    if (GetInstanceFromClass(UEventSystem::StaticClass(), Object))
    {
        return Cast<UEventSystem>(Object);
    }
    return NULL;
}
