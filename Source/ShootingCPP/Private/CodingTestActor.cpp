// Fill out your copyright notice in the Description page of Project Settings.


#include "CodingTestActor.h"

// Sets default values
ACodingTestActor::ACodingTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACodingTestActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hello World"));
	
	UE_LOG(LogTemp, Warning, TEXT("%d"), number1);
	UE_LOG(LogTemp, Warning, TEXT("%.2f"), number2);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *name);
	UE_LOG(LogTemp, Warning, TEXT("%d"), isReady);	
	UE_LOG(LogTemp, Warning, TEXT("Add 결과: %d"), AddCustom(number3, number4));
	
	// 조건문
	if (number3 > 50)
	{
		UE_LOG(LogTemp, Warning, TEXT("%d(number3)은 50부다 큽니다."), number3);
	}
	else if (number3 == 50)
	{
		UE_LOG(LogTemp, Warning, TEXT("%d(number3)은 50입니다."), number3);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%d(number3)은 50부다 작습니다."), number3);
	}
	
	// 반복문
	for (int32 i=1;i<=5;i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("반복 %d회"), i);
	}
}

// Called every frame
void ACodingTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 ACodingTestActor::AddCustom(int32 a, int32 b)
{
	int32 result = a + b;
	return result;
}

