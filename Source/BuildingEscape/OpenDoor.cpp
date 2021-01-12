// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("No pressure plate assigned on %s ."), *GetOwner()->GetName());
	}

	//Find the owning AActor
	//OpenDoor();

	//UE_LOG(LogTemp, Warning, TEXT("Rotation angle: %s"), *angleText);
	// ...
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetTotalMassOfActorsOnPlate() > TriggerMass)
	{
		UE_LOG(LogTemp, Warning, TEXT("MERGE"));
		OnOpenRequest.Broadcast();
	}
	else
	{
		OnCloseRequest.Broadcast();
	}
	
	
	
	
	// ...
}

float UOpenDoor::GetTotalMassOfActorsOnPlate()
{	
	float TotalMass = 0.0f;
	TArray<AActor*> OverlapingActors;
	//Find All Overlaping Actors
	if (!PressurePlate)
	{
		return TotalMass;
	}
	PressurePlate->GetOverlappingActors(OUT OverlapingActors);

	
	//Iterate through them adding their masses
	for (const auto& actor : OverlapingActors)
	{
		TotalMass+=actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate "), *actor->GetName());
	}


	return TotalMass;
}

