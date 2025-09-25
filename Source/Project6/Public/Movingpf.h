#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Movingpf.generated.h"

UCLASS()
class PROJECT6_API AMovingpf : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingpf();

protected:

	USceneComponent* SceneRoot;

	UStaticMeshComponent* StaticMeshComp;

	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category="Move")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, Category="Move")
	float MaxRange;

	int32 MoveDirection = 1;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
