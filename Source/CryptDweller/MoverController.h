// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoverController.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTDWELLER_API UMoverController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoverController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OnTriggerPlaced();
	void OnTriggerRemoved();
	void CheckShouldTrigger();

private:
	UPROPERTY(EditAnywhere)
	FVector m_MoveOffset;
	
	UPROPERTY(EditAnywhere)
	bool m_isMoving;

	UPROPERTY(EditAnywhere)
	float m_moveTime = 4.0f;

	UPROPERTY(EditAnywhere)
	int m_amountOfTriggers = 1;

	FVector m_startLocation;
	int m_triggerd;
};
