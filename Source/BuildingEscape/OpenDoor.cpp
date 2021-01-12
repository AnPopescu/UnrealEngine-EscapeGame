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

	//Find the owning AActor
	//OpenDoor();

	//UE_LOG(LogTemp, Warning, TEXT("Rotation angle: %s"), *angleText);
	// ...
	
}

void UOpenDoor::OpenDoor()
{
	
	//Create a rotator
	//FRotator NewRotation = ;

	//Set the door rotation
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));

	//FVector angle = Owner->GetTransform().GetRotation().Euler();
	//FString angleText = angle.ToString();
}

void UOpenDoor::CloseDoor()
{
	//Create a rotator
	//FRotator NewRotation = FRotator(0.0f, -80.0f, 0.0f);

	//Set the door rotation
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));

	//FVector angle = Owner->GetTransform().GetRotation().Euler();
	//FString angleText = angle.ToString();
}




// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetTotalMassOfActorsOnPlate() > 50.0f)
	{
		OpenDoor();
		LastDoorOpnTime = GetWorld()->GetTimeSeconds();
	}
	
	if ((GetWorld()->GetTimeSeconds() - LastDoorOpnTime) > DoorCloseDelay)
	{
		CloseDoor();
	}
	// ...
}

float UOpenDoor::GetTotalMassOfActorsOnPlate()
{	
	float TotalMass = 0.0f;
	TArray<AActor*> OverlapingActors;
	//Find All Overlaping Actors
	PressurePlate->GetOverlappingActors(OUT OverlapingActors);

	//Iterate through them adding their masses
	for (const auto& actor : OverlapingActors)
	{
		TotalMass+=actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate "), *actor->GetName());
	}


	return TotalMass;
}

