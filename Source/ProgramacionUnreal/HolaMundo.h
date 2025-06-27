// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HolaMundo.generated.h"

UCLASS()
class PROGRAMACIONUNREAL_API AHolaMundo : public AActor
{
	GENERATED_BODY()

public:
	//Attribute for speed
	UPROPERTY(EditAnywhere, Category = "Speed")
	float Speed = 1.0f;
	//Attribute for the distance
	UPROPERTY(VisibleAnywhere, Category = "Distance")
	float Distance = 0.0f;
	//Attribute for the direction read
	UPROPERTY(BlueprintReadOnly, Category="Direction")
	FVector Direction = FVector(1.0f, 0.0f, 0.0f);
	//Attribute for the direction modify
	UPROPERTY(BlueprintReadWrite, Category="Direction")
	FVector Direction2 = FVector(1.0f, 0.0f, 0.0f);
	//Attribute for the direction modify blueprint and editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Direction")
	FVector Direction3 = FVector(1.0f, 0.0f, 0.0f);
	//Function that can be called in the blueprint
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void MoveForward(float Value);
	//Function that returns a value that can be read in the blueprint as pure function called get real speed
	UFUNCTION(BlueprintPure, Category = "Speed")
	float GetRealSpeed();
	//Function can be called in the blueprint recieves vector can be modified in blueprint and returns float
	UFUNCTION(BlueprintCallable, Category = "Direction")
	float SetDirection(FVector NewDirection);
	//Same function but parameter is a reference
	UFUNCTION(BlueprintCallable, Category = "Direction")
	float SetDirection2(FVector& NewDirection);
public:	
	// Sets default values for this actor's properties
	AHolaMundo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
