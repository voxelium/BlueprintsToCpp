// Fill out your copyright notice in the Description page of Project Settings.


#include "TextWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UTextWidget::NativeConstruct()
{
	Super::NativeConstruct();

	TestStr = TEXT("4645");
	
	// конвертируем текст в целое число
	ToInt = FCString::Atoi(*TestStr);

	
	if(TextBtn)
	{
		TextBtn->OnClicked.AddDynamic(this, &UTextWidget::TextBtnOnClicked);
	}
}

void UTextWidget::TextBtnOnClicked()
{
	TextLabel->SetText(FText::AsNumber(999));
	
	FName TestName = FName(*TestStr);
	
	FText TestTxt1 = FText::FromString(TestStr);
	FText TestTxt2 = FText::AsCultureInvariant(TestStr);
	
	
	
	//конвертация в строку из Name или из Text в зависимости от переменной IsName
	//при помощи тернарного оператора "?" он более удобен и лучше читаем чем "If Else"

	FString TestStr2;
	bool IsName = true;
	TestStr2 = IsName ? TestName.ToString() : TestTxt1.ToString();


	// проверяем является ли строка полностью числовой или нет
	
	FString IsNumeric = TestStr.IsNumeric() ? TEXT("true") : TEXT("false");
	TextTrueFalse->SetText(FText::FromString(IsNumeric));

	// конвертируем текст в числа
	ToInt = FCString::Atoi(*TestStr);
	float ToFloat = FCString::Atof(*TestStr);

	// конвертируем из числа в текст
	FString FromInt = FString::FromInt(ToInt);
	FString FromFloat = FString::SanitizeFloat(ToFloat);
}

