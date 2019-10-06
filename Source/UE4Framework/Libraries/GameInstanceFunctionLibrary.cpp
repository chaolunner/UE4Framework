// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstanceFunctionLibrary.h"
#include "UE4Framework/Core/GameInstanceAssembler.h"

bool UGameInstanceFunctionLibrary::GetInstanceFromClass(UClass* Class, UObject* &Object)
{
    UGameInstanceAssembler* instance = UGameInstanceAssembler::GetInstance();
    if (instance)
    {
        return instance->GetInstanceFromClass(Class, Object);
    }
    return false;
}
