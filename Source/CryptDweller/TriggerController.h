// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "MoverController.h"
#include "TriggerController.generated.h"
/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTDWELLER_API UTriggerController : public UBoxComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
public:

	UTriggerController();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	AActor* GetActorByTag() const;

public:
	UPROPERTY(EditAnywhere)
	AActor *referenceActor;

private:
	UMoverController* m_moverController;
	bool isTriggerd;
};
