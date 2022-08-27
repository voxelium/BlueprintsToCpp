// Copyright Epic Games, Inc. All Rights Reserved.


#include "BlueprintsToCppGameModeBase.h"
#include "TextWidget.h"
#include "Blueprint/UserWidget.h"


void ABlueprintsToCppGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (WidgetClass)
	{
		TextWidget = Cast<UTextWidget>(CreateWidget(GetWorld(), WidgetClass));
		if(TextWidget)
		{
			TextWidget->AddToViewport();
			StartUpdateWidget();
		}
	}
	
}

	
void ABlueprintsToCppGameModeBase::StartUpdateWidget()
{
	TextWidget->UpdateWidget();
}
