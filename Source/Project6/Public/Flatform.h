#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Flatform.generated.h"

UCLASS()
class PROJECT6_API AFlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AFlatform();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Platform Settings")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Platform Settings")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
