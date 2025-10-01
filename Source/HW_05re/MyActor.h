// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()

class HW_05RE_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	float TotalDistance;
	int32 TotalEventCount;
	FVector2D CurrentLocation;
	FVector2D PreviousLocation;
	int32 Step();
	void Move(int32 MoveCount);
	void TriggerEventWithProbability(float Probability);
	float Distance(FVector second, FVector first);
};
