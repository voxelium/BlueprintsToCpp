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
	ToFloat = FCString::Atof(*TestStr);

	// конвертируем из числа в текст
	FString FromInt = FString::FromInt(ToInt);
	FString FromFloat = FString::SanitizeFloat(ToFloat);

	const int32 IntVal = 3;
	const float FloatVal = 17.2;

	// конвертация Int и Float в строку String
	FString TestStr3 = FString::Printf(TEXT("%d"), IntVal);
	FString TestStr4 = FString::Printf(TEXT("%f"), FloatVal);

	// конвертирование Int и Float в строку String с форматированием
	FString TextLives = TEXT("Number of Lives: ");
	FString TestStr5 = FString::Printf(TEXT("TextLives %d / Time: %f"), IntVal, FloatVal);

	TextLabel_01->SetText(FText::AsNumber(999));
	TextLabel_02->SetText(FText::FromString(TestStr5));

	//Сравниваем строки

	FString CompStr1 = TEXT("Unreal");
	FString CompStr2 = TEXT("Engine");
	FString CompStr3 = TEXT("UnReAl");

	// Сравнение строк БЕЗ учета регистра 
	// bool IsEqual = CompStr1 == CompStr3;
	
	// Сравнение строк С учетом регистра
	bool IsEqual = CompStr1.Equals(CompStr3, ESearchCase::CaseSensitive);

	FString TestStr6 = IsEqual ? TEXT("true") : TEXT("false");
	TextLabel_03->SetText(FText::FromString(TestStr6));
	
}

