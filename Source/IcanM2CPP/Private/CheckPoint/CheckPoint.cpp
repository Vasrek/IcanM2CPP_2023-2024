// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckPoint/CheckPoint.h"
#include "Components/SphereComponent.h"
#include "../../../../Source/IcanM2CPP/Public/Pawn/MyPawn.h"

// Sets default values
ACheckPoint::ACheckPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerSphere"));
	Sphere->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void ACheckPoint::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ACheckPoint::OnSphereOverlap);
	
}

void ACheckPoint::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIdex, bool FromSweep, const FHitResult& SweepResult)
{
	AMyPawn* Bird = CastChecked<AMyPawn>(OtherActor);

	if (Bird)
	{
		Bird->setNbCheckpointPassed(Bird->getNbCheckpointPassed() + 1);
	}
}

// Called every frame
void ACheckPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

