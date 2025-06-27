// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include "ABRUniversalPlatform.generated.h"

UCLASS()
class PROGRAMACIONUNREAL_API AABRUniversalPlatform : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ABR")
	bool isActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ABR")
	double Distance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ABR")
	double MaximumDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ABR")
	FVector VDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ABR")
	FVector Destination;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ABR")
	float Velocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ABR")
	FRotator RotationDistance;
	//Add static mesh component
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="ABR")
	UStaticMeshComponent* Mesh;
	//Add box collision component
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="ABR")
	UBoxComponent* BoxCollision;
public:	
	// Sets default values for this actor's properties
	AABRUniversalPlatform();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	virtual void MovePlatform(float DeltaTime);


};
