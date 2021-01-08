// Fill out your copyright notice in the Description page of Project Settings.


#include "PositionReporter.h"
//#include "Gameframework/Actor.h"

// Sets default values for this component's properties
UPositionReporter::UPositionReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	//Macro to log a text
	//UE_LOG(LogTemp, Warning, TEXT("Position Report Reporting for duty!"));

	// ...
}


// Called when the game starts
void UPositionReporter::BeginPlay()
{
	Super::BeginPlay();

	//Macro to log a text
	
	FString ObjectName = GetOwner()->GetName();
	FString ObjectPos = GetOwner()->GetTransform().GetLocation().ToString();
	float WorldPosX = GetOwner()->GetTransform().GetLocation().X;
	float WorldPosY = GetOwner()->GetTransform().GetLocation().Y;
	float WorldPosZ = GetOwner()->GetTransform().GetLocation().Z;

	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *ObjectName, *ObjectPos);

	// ...
	
}


// Called every frame
void UPositionReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

