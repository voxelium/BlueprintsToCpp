// Fill out your copyright notice in the Description page of Project Settings.


#include "ConeActor.h"

// Sets default values
AConeActor::AConeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>("Scene");
	ConeMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");

	Scene->SetupAttachment(GetRootComponent());
	ConeMesh->SetupAttachment(Scene);

	Speed = 100;
	Max = 200;
	
	

}

// Реализуем функцию использования енумератора
void AConeActor::DisplayKeyword()
{
	// будет значение по умолчанию
	 UnitKeywords |= static_cast<uint8>(EUnitKeyword::Running);

	// удаляет ключевое слово
	 UnitKeywords &= ~static_cast<uint8>(EUnitKeyword::Activated);

	
	if(UnitKeywords & static_cast<uint8>(EUnitKeyword::Activated))
	{
		UE_LOG(LogTemp, Warning, TEXT("Cone is activated"));
	}

	if(UnitKeywords & static_cast<uint8>(EUnitKeyword::Running))
	{
		UE_LOG(LogTemp, Warning, TEXT("Cone is Running"));
	}

	if(UnitKeywords & static_cast<uint8>(EUnitKeyword::Stopped))
	{
		UE_LOG(LogTemp, Warning, TEXT("Cone is Stopped"));
	}
}

// Called when the game starts or when spawned
void AConeActor::BeginPlay()
{
	Super::BeginPlay();

	const FVector Location = GetActorLocation();
	CurrentZ	= Location.Z;
	MinHeight	= Location.Z;
	MaxHeight	= Location.Z + Max;
	bIsUp		= true;

	TestImplementableFunc(948);
	
}

void AConeActor::TestVectorInput1(const int32 InVal, FVector Location, int32& OutVal)
{
}

void AConeActor::TestVectorInput2(const int32 InVal, const FVector& Location, int32& OutVal)
{
}

void AConeActor::TestInputOutput1(const int32 InVal, AConeActor* ConeActor, int32& OutVal)
{
	OutVal = InVal;
}

void AConeActor::TestInputOutput2(const int32 InVal, AConeActor*& ConeActor, int32& OutVal)
{
	OutVal = InVal;
}

bool AConeActor::TestInputOutput3(const int32 InVal, AConeActor*& ConeActor, int32& OutVal)
{
	return true;
}

void AConeActor::TestFunc1(int32 Val)
{
	UE_LOG(LogTemp, Warning, TEXT("Это тестовый вызов функции %d"), Val);
}

int32 AConeActor::TestPureFunc()
{
	return 255;
}

int32 AConeActor::TestPureFuncInputable1() const
{
	return 686;
}

int32 AConeActor::TestPureFuncInputable2() const
{
	return 99999;
}


void AConeActor::TopHeight_Implementation()
{
	this->Destroy();
}

// Called every frame
void AConeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Определяем что будет происходить в зависимости от переменной bIsUp
	const float Val = DeltaTime * Speed;
	if (bIsUp)
	{
		CurrentZ = CurrentZ + Val;
	}
	else
	{
		CurrentZ = CurrentZ - Val;
	}

	//Устанавливаем актера в метоположение CurrentZ
	FVector Location = GetActorLocation();
	Location.Z = CurrentZ;
	SetActorLocation(Location);

	if(CurrentZ > MaxHeight)
	{
		bIsUp = false;
		TopHeight();
	}
	else if (CurrentZ < MinHeight)
	{
		bIsUp = true;
	}
	

}

