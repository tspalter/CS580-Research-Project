// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "ProceduralCubeTest.generated.h"

UCLASS()
class RESEARCHPROJECT_API AProceduralCubeTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralCubeTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UProceduralMeshComponent* customMesh;

	// Mesh data:
	TArray<FVector> vertices;
	TArray<int32> triangles;

	// Function to create a triangle.
	void AddTriangle(int32 V1, int32 V2, int32 V3);

	// Generate a procedural cube.
	void GenerateCubeMesh();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
