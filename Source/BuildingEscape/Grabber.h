// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <PhysicsEngine\PhysicsHandleComponent.h>
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 120.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputHandle = nullptr;
	/// Raycast and grab what is in reach
	void Grab();
	void Release();

	///Find attached PhusicsHnadleComponent
	void FindPhysicsHandleComponent();

	///Setup Input Component
	void SetupInputComponent();

	//Return Hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	//Returs the vector location of the reach line end
	FVector GetReachLineEnd();

	//Return 
	FVector GetReachLineStart();
		
};
