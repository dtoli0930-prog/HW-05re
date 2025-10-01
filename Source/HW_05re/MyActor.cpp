// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PreviousLocation = FVector2D(0, 0);
	CurrentLocation = FVector2D(0, 0);
	TotalDistance = 0.f;
	TotalEventCount = 0;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Inital Location:(%f, %f)"), CurrentLocation.X, CurrentLocation.Y);
	Move(10);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
int32 AMyActor::Step()
{
	return FMath::RandRange(0, 1);
}
void AMyActor::Move(int32 MoveCount)
{
	for (int32 i = 0; i < MoveCount; ++i)
	{
		PreviousLocation = CurrentLocation;
		CurrentLocation.X += Step();
		CurrentLocation.Y += Step();
		TriggerEventWithProbability(50);
		float MovedDistance = Distance(
			FVector(CurrentLocation.X, CurrentLocation.Y, 0.0),
			FVector(PreviousLocation.X, PreviousLocation.Y, 0.0)
		);
		TotalDistance += MovedDistance;
		UE_LOG(LogTemp, Warning, TEXT("Inital Location:(%d, %f, %f)"), i+1, CurrentLocation.X, CurrentLocation.Y);
	}
	UE_LOG(LogTemp, Warning, TEXT("Total Distance: %f, Total Event Count: %d"), TotalDistance, TotalEventCount);
}

void AMyActor::TriggerEventWithProbability(float Probability)
{
	int32 RandomValue = FMath::RandRange(1, 100);
	if (RandomValue <= Probability)
	{
		UE_LOG(LogTemp, Warning, TEXT("Event Occured"));
		++TotalEventCount;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Event Not Occured"));
	}
}

float AMyActor::Distance(FVector second, FVector first)
{
	float dx = second.X - first.X;
	float dy = second.Y - first.Y;
	return FMath::Sqrt(FMath::Square(dx) + FMath::Square(dy));
}
