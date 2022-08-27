// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumTest.h"
#include "GameFramework/Actor.h"
#include "ConeActor.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API AConeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConeActor();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ConeActor")
	float Speed;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USceneComponent* Scene;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* ConeMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ConeActor")
	bool bIsUp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="ConeActor")
	float MinHeight;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="ConeActor")
	float MaxHeight;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="ConeActor")
	float CurrentZ;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ConeActor")
	float Max;

	//Добавляем Enumerator енумератор первого способа
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EBarrierTypeStd> BarrierTypeStd = EBT_Impassable;

	//Добавляем Enumerator енумератор второго способа - ПРЕДПОЧТИТЕЛЬНЫЙ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EBarrierType BarrierType = EBarrierType::Difficult;
	
	//Добавляем Enumerator енумератор третьего способа с флагами
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Bitmask, BitmaskEnum = "EUnitKeyWord"))
	uint8 UnitKeywords = static_cast<uint8>(EUnitKeyword::Activated);

	//Объявляем функцию использования енумератора
	UFUNCTION(BlueprintCallable)
	void DisplayKeyword();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	//Executable функция вызываемая в blueprints со входом типа Vector (здесь Vector может быть назначен)
	UFUNCTION(BlueprintCallable, Category="Cone Functions")
	void TestVectorInput1(const int32 InVal, FVector Location, int32& OutVal);

	//Executable функция вызываемая в blueprints со входом типа Vector (Vector не изменяется и передается для дальнейшего использования)
	UFUNCTION(BlueprintCallable, Category="Cone Functions")
	void TestVectorInput2(const int32 InVal, const FVector& Location, int32& OutVal);
	
	//Executable функция вызываемая в blueprints со входом типа Cone Actor Reference
	UFUNCTION(BlueprintCallable, Category="Cone Functions")
	void TestInputOutput1(const int32 InVal, AConeActor* ConeActor, int32& OutVal);

	//Executable функция вызываемая в blueprints со входом и выходом, типа Cone Actor Reference
	UFUNCTION(BlueprintCallable, Category="Cone Functions")
	void TestInputOutput2(const int32 InVal, AConeActor*& ConeActor, int32& OutVal);

	//Executable функция вызываемая в blueprints со входом и выходом, типа Cone Actor Reference
	UFUNCTION(BlueprintCallable, Category="Cone Functions")
	bool TestInputOutput3(const int32 InVal, AConeActor*& ConeActor, int32& OutVal);
	
	//Executable функция вызываемая в blueprints
	UFUNCTION(BlueprintCallable, Category="Cone Functions")
	void TestFunc1(int32 Val);

	//Pure функция вызываемая в blueprints
	UFUNCTION(BlueprintPure, Category="Cone Functions")
	int32 TestPureFunc();

	// Если данные не изменяются, то отметь их CONST !!!
	
	//Pure функция c Target Input вызываемая в blueprints
	UFUNCTION(BlueprintCallable, Category="Cone Functions")
	int32 TestPureFuncInputable1() const;
	
	//Pure функция c Target Input (со скрытым пином Self) вызываемая в blueprints
	UFUNCTION(BlueprintCallable, Category="Cone Functions", meta=(HideSelfPin="true"))
	int32 TestPureFuncInputable2() const;
	
	//Имплементарное событие красная функция вызываемая в blueprints
	UFUNCTION(BlueprintImplementableEvent, Category="Cone Functions")
	void TestImplementableFunc(int32 Val);
	
	//Имплементарное событие красная функция вызываемая в blueprints - возвращает Bool
	UFUNCTION(BlueprintImplementableEvent, Category="Cone Functions")
	bool TestImplementableFuncBool(int32 Val);
	
	//Blieprint Native функция вызываемая в blueprints
	UFUNCTION(BlueprintNativeEvent, Category="Cone Functions")
	void TopHeight();
	void TopHeight_Implementation();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
