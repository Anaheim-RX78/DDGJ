// Fill out your copyright notice in the Description page of Project Settings.


#include "StatsSubsystem.h"

void UStatsSubsystem::UpdateBestScore(int NewScore)
{
	BestScore = BestScore + NewScore;
}
