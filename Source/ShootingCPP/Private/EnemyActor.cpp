// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"

#include "EngineUtils.h"
#include "PlayerPawn.h"
#include "Components/BoxComponent.h"


// Sets default values
AEnemyActor::AEnemyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("EnemyBoxComponent"));
	SetRootComponent(boxComp);
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyStaticMeshComponent"));
	meshComp->SetupAttachment(boxComp);
	FVector boxSize = FVector(50.0f, 50.0f, 50.0f);
	boxComp->SetBoxExtent(boxSize);
	
}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();
	
	// 1~100 사이 임의 값 추첨
	int32 drawResult = FMath::RandRange(1, 100);
	if (drawResult < traceRate)
	{
		// 추적을 위한 벡터 탐색 반복 TActorIterator 활용
		// for(TActorIterator<찾으려는 클래스> 위치포인터변수; 변수 이름;**변수증감식) { 실행부 }
		// 월드 공간에 APlayerPawn 클래스로 된 액터를 검색
		for (TActorIterator<APlayerPawn> player(GetWorld()); player; ++player)
		{
			// 찾은 액터 이름이 BP_PlayerPawn이라면,
			if (player->GetName().Contains(TEXT("BP_PlayerPawn")))
			{
				// 찾은 플레이어 위치 - Enemy 자신의 위치 = 방향
				dir = player->GetActorLocation() - GetActorLocation();
				dir.Normalize();
			}
		}
	}
	else
	{
		// 직진
		dir = GetActorForwardVector();
	}
}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// 정해진 방향으로 이동
	FVector newLocation = GetActorLocation() + dir * moveSpeed * DeltaTime;
	SetActorLocation(newLocation);
}

