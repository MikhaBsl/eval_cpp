#pragma once

#include "Ranking.h"

#include <vector>
#include <memory>
#include "IStrategy.h"
#include "Choice.h"

class Tournament
{
public:
	void PopulateStrategy();

	void Simulate();

	std::vector<Ranking> GenerateFinalRankingByPoint() const;
	std::vector<Ranking> GenerateFinalRankingByWinDrawLoss() const;

private:
	std::vector<std::unique_ptr<IStrategy>> strategies;
	std::vector<Ranking> rankings;
	static void GetRoundPoints(Choice a, Choice b, int& pointA, int& pointB);

	static constexpr int RoundCount = 50;

	static void PlayMatch( IStrategy& a,  IStrategy& b, int& scoreA, int& scoreB);

	static std::vector<std::unique_ptr<IStrategy>> CreateStrategies();
	static void AddResult(Ranking& ranking, int ownScore, int opponentScore);
};