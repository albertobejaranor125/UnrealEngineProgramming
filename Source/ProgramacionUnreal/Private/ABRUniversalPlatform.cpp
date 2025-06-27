// Fill out your copyright notice in the Description page of Project Settings.


#include "ABRUniversalPlatform.h"

// Sets default values
AABRUniversalPlatform::AABRUniversalPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform Mesh"));
	SetRootComponent(Mesh);
	//Add a box collision
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetupAttachment(Mesh);
}
void AABRUniversalPlatform::MovePlatform(float DeltaTime) {
	FVector pos = GetActorLocation();
	FVector inc = VDirection * Velocity * DeltaTime;
	Distance += FVector::Distance(pos+inc,pos);
	SetActorLocation(pos + inc);
	if (Distance >= MaximumDistance) {
		VDirection = -VDirection;
		Distance = 0;
	}
}
// Called when the game starts or when spawned
void AABRUniversalPlatform::BeginPlay()
{
	Super::BeginPlay();
	FVector Origin;
	Origin = GetActorLocation();
	MaximumDistance = FVector::Distance(Destination, Origin);
	VDirection = Destination - Origin;
	Distance = 0;
	RotationDistance = FRotator(0, 0, 0);
}

// Called every frame
void AABRUniversalPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
}

