// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnumTest.generated.h"

//Первый способ Объявляем Enumerator енумератор
UENUM(BlueprintType, Category="GameRules")
enum EBarrierTypeStd
{
	EBT_BarrierNone		UMETA(DisplayName = "No Barrier"),
	EBT_ModerateBarrier UMETA(DisplayName = "Moderate Barrier"),
	EBT_Difficult		UMETA(DisplayName = "Difficult Barrier"),
	EBT_VeryDifficult	UMETA(DisplayName = "Very Difficult Barrier"),
	EBT_Impassable		UMETA(DisplayName = "Impassable Barrier")
	
};

//Второй способ Объявляем Enumerator енумератор - ПРЕДПОЧТИТЕЛЬНЫЙ
UENUM(BlueprintType, Category="GameRules")
enum class EBarrierType : uint8
{
	BarrierNone			UMETA(DisplayName = "2 Barrier"),
	ModerateBarrier		UMETA(DisplayName = "2 Moderate Barrier"),
	Difficult			UMETA(DisplayName = "2 Difficult Barrier"),
	VeryDifficult		UMETA(DisplayName = "2 Very Difficult Barrier"),
	Impassable			UMETA(DisplayName = "2 Impassable Barrier")
	
};

//Третий способ Объявляем Enumerator енумератор с флагами
UENUM(BlueprintType, Meta = (Bitflags))
enum class EUnitKeyword : uint8
{
	None			= 0 UMETA(Hidden),
	Activated		= 1 UMETA(DisplayName = "Activated"),
	Stopped			= 2 UMETA(DisplayName = "Stopped"),
	Prone			= 4 UMETA(DisplayName = "Prone"),
	Running			= 8 UMETA(DisplayName = "Running")
};
