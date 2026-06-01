// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterSamGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "ShooterSamCharacter.h"
#include "ShooterAI.h"
AShooterSamGameMode::AShooterSamGameMode()
{
	// stub
}

void AShooterSamGameMode::BeginPlay()
{
	Super::BeginPlay();
	AShooterSamCharacter* Player = Cast<AShooterSamCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(),0));
	
	TArray<AActor*> ShooterAiActors;
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AShooterAI::StaticClass(), ShooterAiActors);
	for (int32 LoopIndex = 0; LoopIndex < ShooterAiActors.Num(); LoopIndex++)
	{
		AActor* ShooterAIActor = ShooterAiActors[LoopIndex];
		AShooterAI* ShooterAI = Cast<AShooterAI>(ShooterAIActor);
		if (ShooterAI)
		{
			ShooterAI->StartBehaviorTree(Player);
			UE_LOG(LogTemp, Log, TEXT("Started behavior tree for %s"), *ShooterAI->GetActorNameOrLabel());
		}
	}
	
}
