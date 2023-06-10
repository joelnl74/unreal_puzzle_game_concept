// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerController.h"

UTriggerController::UTriggerController()
{
	PrimaryComponentTick.bCanEverTick = true;
	isTriggerd = false;
}

void UTriggerController::BeginPlay()
{
	m_moverController = (UMoverController*)referenceActor->FindComponentByClass<UMoverController>();
}

void UTriggerController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* activeActor = GetActorByTag();

	if (activeActor == nullptr && isTriggerd)
	{
		m_moverController->OnTriggerRemoved();
		isTriggerd = false;
	}
	else if (isTriggerd == false && activeActor != nullptr)
	{
		m_moverController->OnTriggerPlaced();
		isTriggerd = true;
	}
}

AActor* UTriggerController::GetActorByTag() const
{
	TArray<AActor*> overlappingActors;
	GetOverlappingActors(overlappingActors);

	for (AActor* actor : overlappingActors)
	{
		if (actor->ActorHasTag("Unlock"))
		{
			UE_LOG(LogTemp, Log, TEXT("MOVE CONTROLLER IS %s"), *actor->GetName());

			return actor;
		}
	}

	return nullptr;
}
