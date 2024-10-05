// Fill out your copyright notice in the Description page of Project Settings.


#include "Ghost/GhostCharacter.h"
#include "Components/BoxComponent.h"
#include "GameFramework//FloatingPawnMovement.h"

// Sets default values
AGhostCharacter::AGhostCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(BoxCollision);

	MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(TEXT("MovementComponent"));
	MovementComponent->UpdatedComponent = BoxCollision;

}

// Called when the game starts or when spawned
void AGhostCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGhostCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// float distance = FVector::DistSquared(targetLocation, currentLocation);
	// if (distance <= 5) { change targetLocation }
	// MoveTo(Seek(targetLocation));
}

// Called to bind functionality to input
void AGhostCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGhostCharacter::MoveTo(FVector Location)
{
	MovementComponent->AddInputVector(Location);
}

FVector AGhostCharacter::Seek(FVector Target)
{
	FVector DesiredVelocity = Target - GetActorLocation();
	DesiredVelocity.Normalize();
	DesiredVelocity *= MovementComponent->GetMaxSpeed();

	FVector Steering = DesiredVelocity - MovementComponent->Velocity;
	Steering = Steering.GetClampedToMaxSize(MovementComponent->GetMaxSpeed());

	return Steering;
}