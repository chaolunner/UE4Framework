// Fill out your copyright notice in the Description page of Project Settings.


#include "MathFunctionLibrary.h"
#include "Math/NumericLimits.h"

float UMathFunctionLibrary::MinValue()
{
	return TNumericLimits<float>::Min();
}

float UMathFunctionLibrary::MaxValue()
{
	return TNumericLimits<float>::Max();
}
