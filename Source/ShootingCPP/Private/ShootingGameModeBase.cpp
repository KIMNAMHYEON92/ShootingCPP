// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingGameModeBase.h"

#include "MainWidget.h"
#include "Blueprint/UserWidget.h"

void AShootingGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	// mainWidget BP 파일을 메모리에 로드
	 mainUI = CreateWidget<UMainWidget>(GetWorld(),mainWidget);
	
	if (mainUI != nullptr)
	{
		mainUI->AddToViewport();
	}
}

void AShootingGameModeBase::PrintScore()
{
	if (mainUI != nullptr)
	{
		mainUI->scoreData->SetText(FText::AsNumber(currentScore));
	}
}

void AShootingGameModeBase::AddScore(int32 point)
{
	currentScore += point;
	
	PrintScore();
}