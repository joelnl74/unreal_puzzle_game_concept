// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectPickerController.h"

#include "Engine/World.h"

// Sets default values for this component's properties
UObjectPickerController::UObjectPickerController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UObjectPickerController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UObjectPickerController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UPhysicsHandleComponent* physicsComponent = GetPhysicsHandle();

	if (physicsComponent == nullptr)
	{
		return;
	}

	if (physicsComponent->GetGrabbedComponent() == nullptr)
	{
		return;
	}

	FVector target = GetComponentLocation() + GetForwardVector() * m_holdDistance;
	physicsComponent->SetTargetLocationAndRotation(target, GetComponentRotation());
}

void UObjectPickerController::Release()
{
	UPhysicsHandleComponent* physicsComponent = GetPhysicsHandle();

	if (physicsComponent == nullptr)
	{
		return;
	}

	UPrimitiveComponent* prmitiveComponent = physicsComponent->GetGrabbedComponent();

	if (prmitiveComponent == nullptr)
	{
		return;
	}

	prmitiveComponent->WakeAllRigidBodies();
	physicsComponent->ReleaseComponent();
}

void UObjectPickerController::Press()
{
	FHitResult hitResult;
	bool hasHit = GetObjectInReach(hitResult);

	if (hasHit == false)
	{
		return;
	}

	GetComponetBySweep(hitResult);
}

bool UObjectPickerController::GetObjectInReach(FHitResult& outHitResult) const
{
	FVector start = GetComponentLocation();
	FVector end = start + GetForwardVector() * m_maxPickerDistance;

	FCollisionShape collisionShape = FCollisionShape::MakeSphere(m_grabRadius);
	bool hasHit = GetWorld()->SweepSingleByChannel(outHitResult, start, end, FQuat::Identity, ECC_GameTraceChannel2, collisionShape);

	return hasHit;
}


void UObjectPickerController::GetComponetBySweep(FHitResult& hitResult)
{
	UPhysicsHandleComponent* physicsComponent = GetPhysicsHandle();

	if (physicsComponent == nullptr)
	{
		return;
	}

	UPrimitiveComponent* primitiveComponent = hitResult.GetComponent();
	physicsComponent->GrabComponentAtLocationWithRotation(primitiveComponent, NAME_None, hitResult.ImpactPoint, GetComponentRotation());
	primitiveComponent->WakeAllRigidBodies();
}

UPhysicsHandleComponent* UObjectPickerController::GetPhysicsHandle() const
{
	return GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
}

