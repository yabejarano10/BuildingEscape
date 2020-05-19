// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CPPGAME1_API UOpenDoor : public UActorComponent
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
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActors() const;
	void FindAudioComponent();
	void FindPressurePlate();

	bool OpenDoorSound = false;
	bool CloseDoorSound = true;

private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.f;
	float DoorLastOpened = 0.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.5f;

	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed = 45.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseSpeed = 500.f;

	float InitialYaw;
	float CurrentYaw;

	UPROPERTY(EditAnywhere)
	ATriggerVolume *PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
	float MassToOpenDoor = 50.f;

	UPROPERTY()
	UAudioComponent* AudioComponent = nullptr;
};
