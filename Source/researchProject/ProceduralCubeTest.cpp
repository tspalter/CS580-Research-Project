// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralCubeTest.h"

// Sets default values
AProceduralCubeTest::AProceduralCubeTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	customMesh = CreateDefaultSubobject<UProceduralMeshComponent>("CustomMesh");
	SetRootComponent(customMesh);
	customMesh->bUseAsyncCooking = true;
}

// Called when the game starts or when spawned
void AProceduralCubeTest::BeginPlay()
{
	Super::BeginPlay();
	GenerateCubeMesh();
}


// Function to create a triangle.
void AProceduralCubeTest::AddTriangle(int32 V1, int32 V2, int32 V3)
{
	triangles.Add(V1);
	triangles.Add(V2);
	triangles.Add(V3);
}


// Generate a procedural cube.
void AProceduralCubeTest::GenerateCubeMesh()
{
	if (nullptr == customMesh) return;

	// Relative locations.
	vertices.Add(FVector(0, -100, 0));		// Lower left:  0
	vertices.Add(FVector(0, -100, 100));	// Upper left:  1
	vertices.Add(FVector(0, 100, 0));		// Lower right: 2
	vertices.Add(FVector(0, 100, 100));		// Upper right: 3 

	vertices.Add(FVector(100, -100, 0));	// Lower front left:  4
	vertices.Add(FVector(100, -100, 100));	// Upper front left:  5
	vertices.Add(FVector(100, 100, 100));	// upper front right: 6
	vertices.Add(FVector(100, 100, 0));		// lower front right: 7 

	// Back
	AddTriangle(0, 2, 3);
	AddTriangle(3, 1, 0);

	// Left
	AddTriangle(0, 1, 4);
	AddTriangle(4, 1, 5);

	// Front
	AddTriangle(4, 5, 7);
	AddTriangle(7, 5, 6);

	// Right
	AddTriangle(7, 6, 3);
	AddTriangle(3, 2, 7);

	// Top 
	AddTriangle(1, 3, 5);
	AddTriangle(6, 5, 3);

	// Bottom
	AddTriangle(2, 0, 4);
	AddTriangle(4, 7, 2);

	TArray<FLinearColor> vertexColors;
	vertexColors.Add(FLinearColor(0.f, 0.f, 1.f));
	vertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
	vertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
	vertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
	vertexColors.Add(FLinearColor(0.5f, 1.f, 0.5f));
	vertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
	vertexColors.Add(FLinearColor(1.f, 1.f, 0.f));
	vertexColors.Add(FLinearColor(0.f, 1.f, 1.f));

	// This is the very magical function. No normals or tangents were generated.
	// (I think those get auto-generated based on clockwise ordering)
	customMesh->CreateMeshSection_LinearColor(
		0, vertices, triangles, TArray<FVector>(), TArray<FVector2D>(),
		vertexColors, TArray<FProcMeshTangent>(), true
	);
}

// Called every frame
void AProceduralCubeTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

