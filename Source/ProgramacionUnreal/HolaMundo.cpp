// Fill out your copyright notice in the Description page of Project Settings.


#include "HolaMundo.h"

void AHolaMundo::MoveForward(float Value)
{
}

float AHolaMundo::GetRealSpeed()
{
	return 0.0f;
}

float AHolaMundo::SetDirection(FVector NewDirection)
{
	return 0.0f;
}

float AHolaMundo::SetDirection2(FVector& NewDirection)
{
	return 0.0f;
}

// Sets default values
AHolaMundo::AHolaMundo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// print "Hola Mundo" to the output log
	UE_LOG(LogTemp, Warning, TEXT("C++ Hola Mundo: Constructor"));
	// print also to the screen
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("C++ Hola Mundo: Constructor"));
}

// Called when the game starts or when spawned
void AHolaMundo::BeginPlay()
{
	Super::BeginPlay();
	// print C++ Hola Mundo: BeginPlay to the output log an also to the screen
	UE_LOG(LogTemp, Warning, TEXT("C++ Hola Mundo: BeginPlay"));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("C++ Hola Mundo: BeginPlay"));
	// Obtener acceso al nombre del padre
	AActor* padre = GetParentActor();

	// chequear si el nombre es valido
	if (padre == nullptr) {
		// si no es valido, escribir en pantalla el mensaje "No se pudo obtener el nombre del padre"
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No se pudo obtener el nombre del padre"));

	}
	else {
		// Escribir en pantalla el texto "Nombre del padre" seguido del nombre del padre
		FString nombre = GetParentActor()->GetName();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Nombre del padre: ") + nombre);
	}

	// hacer lo mismo con getOwner
	AActor* owner = GetOwner();
	if (owner == NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No se pudo obtener el nombre del owner"));
	}
	else {
		FString nombreOwner = GetOwner()->GetName();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Nombre del owner: ") + nombreOwner);
	}
}

// Called every frame
void AHolaMundo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

