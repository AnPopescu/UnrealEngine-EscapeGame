// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include <Runtime\Engine\Public\DrawDebugHelpers.h>

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"));
	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Get lpayer viewpoint /tick

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation,OUT PlayerViewPointRotation);

	//Log out to test
	UE_LOG(LogTemp, Warning, TEXT("Player View Location: %s  Player View Rotation %s"), *PlayerViewPointLocation.ToString(), *PlayerViewPointRotation.ToString());

	FVector LineGrabDirection = PlayerViewPointRotation.Vector();
	FVector LineTraceEnd = PlayerViewPointLocation + LineGrabDirection * Reach;
	//Draw red trace to visualize
	DrawDebugLine(GetWorld(), PlayerViewPointLocation, LineTraceEnd, FColor(255, 0, 0), false, 0.0f, 0.f, 10.0f);

	//Setup

	//Ray-Casting
	FHitResult LineTraceHit;

	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(OUT LineTraceHit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);


	AActor* ActorHit = LineTraceHit.GetActor();
	if (ActorHit)
	{
		FString ActorHitName = LineTraceHit.GetActor()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Raycast HIT: %s"), *ActorHitName);
	}

	

	//See What we hit


	// ...
}

