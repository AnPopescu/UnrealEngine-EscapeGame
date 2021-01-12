// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenEvent);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private :
	//See UPROPERTIES - MACRO - Un fel de [SeriazibleField] doar ca nu putem modifica - Propietatea devine vizibila in editor

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	AActor* Owner=nullptr;

	UPROPERTY(EditAnywhere)
	float TriggerMass = 30.f;

	float GetTotalMassOfActorsOnPlate();

	UPROPERTY(BlueprintAssignable)
	FOnOpenEvent OnOpenRequest;

	UPROPERTY(BlueprintAssignable)
	FOnOpenEvent OnCloseRequest;

		
};
