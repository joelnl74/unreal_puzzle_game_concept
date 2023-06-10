// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

#include "ObjectPickerController.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTDWELLER_API UObjectPickerController : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObjectPickerController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
	void Release();
	UFUNCTION(BlueprintCallable)
	void Press();

private:
	UPhysicsHandleComponent* GetPhysicsHandle() const;
	bool GetObjectInReach(FHitResult &outHitResult) const;

	void GetComponetBySweep(FHitResult &hitResult);
private:
	UPROPERTY(EditAnywhere)
	float m_maxPickerDistance = 400;
	UPROPERTY(EditAnywhere)
	float m_holdDistance = 200;
	UPROPERTY(EditAnywhere)
	float m_grabRadius = 200;
};
