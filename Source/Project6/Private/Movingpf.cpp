#include "Movingpf.h"

AMovingpf::AMovingpf()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Props/SM_Rock.SM_Rock"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	MoveSpeed = 300.0f;
	MaxRange = 250.0f;

	PrimaryActorTick.bCanEverTick = true;

}

void AMovingpf::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = FVector(240.0f, 150.0f, 90.0f);
	SetActorLocation(StartLocation);
	SetActorScale3D(FVector(0.5f));
}

void AMovingpf::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation.X += MoveSpeed * DeltaTime * MoveDirection;
	float DistanceMoved = FMath::Abs(CurrentLocation.X - StartLocation.X);

	if (DistanceMoved > MaxRange)
	{
		MoveDirection *= -1;
	}

	SetActorLocation(CurrentLocation);
}

 