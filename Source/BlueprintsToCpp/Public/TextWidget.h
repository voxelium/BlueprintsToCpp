// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TextWidget.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTSTOCPP_API UTextWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateWidget();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	int32 Lives;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextLabel_01;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextLabel_02;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextTrueFalse;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* TextBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	FString TestStr;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	int32 ToInt;
	
	virtual void NativeConstruct() override;

	UFUNCTION()
	void TextBtnOnClicked();
	
};
