// Fill out your copyright notice in the Description page of Project Settings.


#include "TerrainActor_Grid.h"

// Sets default values
ATerrainActor_Grid::ATerrainActor_Grid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATerrainActor_Grid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATerrainActor_Grid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

