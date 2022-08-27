// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BlueprintsToCppGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTSTOCPP_API ABlueprintsToCppGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Type Class")
	TSubclassOf<UUserWidget> WidgetClass;

	
	UPROPERTY(VisibleInstanceOnly)
	class UTextWidget* TextWidget;

	virtual void BeginPlay() override;

	void StartUpdateWidget();
};
