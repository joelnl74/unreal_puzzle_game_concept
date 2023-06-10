// Fill out your copyright notice in the Description page of Project Settings.


#include "MoverController.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMoverController::UMoverController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoverController::BeginPlay()
{
	Super::BeginPlay();

	// ...
	m_startLocation = GetOwner()->GetActorLocation();
}


// Called every frame
void UMoverController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (m_isMoving == false)
	{
		return;
	}

	FVector currentLocation = GetOwner()->GetActorLocation();
	FVector targetLocation = currentLocation + m_MoveOffset;
	float speed = FVector::Distance(currentLocation, targetLocation) / m_moveTime;

	FVector updatedLocation = FMath::VInterpConstantTo(currentLocation, targetLocation, DeltaTime, speed);
	GetOwner()->SetActorLocation(updatedLocation);
	// ...
}

void UMoverController::OnTriggerPlaced()
{
	m_triggerd++;
	CheckShouldTrigger();
}

void UMoverController::OnTriggerRemoved()
{
	m_triggerd--;
	CheckShouldTrigger();
}

void UMoverController::CheckShouldTrigger()
{
	m_isMoving = m_triggerd >= m_amountOfTriggers;
}

