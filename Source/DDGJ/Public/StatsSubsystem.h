// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "StatsSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class DDGJ_API UStatsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable)
	void UpdateBestScore(int NewScore);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BestScore = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LatestScore = 0;
};
