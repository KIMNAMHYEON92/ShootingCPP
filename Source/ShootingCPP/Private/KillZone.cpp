// Fill out your copyright notice in the Description page of Project Settings.


#include "KillZone.h"

#include "Components/BoxComponent.h"


// Sets default values
AKillZone::AKillZone()
{
	// Tick()이 필요없는 actor에는 항상 false로 설정
	PrimaryActorTick.bCanEverTick = false;
	
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("KZBoxComponent"));
	SetRootComponent(boxComp);
	
	// 박스 모빌리티 고정으로 설정
	boxComp->SetMobility(EComponentMobility::Static);
	
	FVector boxSize = FVector(50.0f,2000.0f,50.0f);
	boxComp->SetBoxExtent(boxSize);
	boxComp->SetCollisionProfileName(TEXT("KillZone"));
}

// Called when the game starts or when spawned
void AKillZone::BeginPlay()
{
	Super::BeginPlay();
	
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AKillZone::OnKillZoneOverlap);
}

void AKillZone::OnKillZoneOverlap(
		UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult
		)
{
	OtherActor->Destroy();
}