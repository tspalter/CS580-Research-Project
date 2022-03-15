// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine:
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TerrainActor_Grid.generated.h"
// Engine Plugin:
#include "ProceduralMeshComponent.h"

/*
	This actor will represent a grid-based procedural terrain generator.
	Finite in size and resolution.
*/
UCLASS()
class RESEARCHPROJECT_API ATerrainActor_Grid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATerrainActor_Grid();

	// Grid properties:
	FVector2D scale, resolution;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
