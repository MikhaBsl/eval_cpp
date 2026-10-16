#include "Tournament.h"

#include "AlwaysCooperate.h"
#include "AlwaysBetray.h"
#include "TitForTat.h"
#include "ResentfulCooperate.h"
#include "RandomStrategy.h"
#include "Pavlov.h"
#include "Prober.h"
#include "SoftMajority.h"

#include <algorithm>

std::vector<std::unique_ptr<IStrategy>> Tournament::CreateStrategies()
{
    std::vector<std::unique_ptr<IStrategy>> result;

    result.push_back(std::make_unique<AlwaysCooperate>());
    result.push_back(std::make_unique<AlwaysBetray>());
    result.push_back(std::make_unique<TitForTat>());
    result.push_back(std::make_unique<ResentfulCooperate>());
    result.push_back(std::make_unique<RandomStrategy>());
    result.push_back(std::make_unique<Pavlov>());
    result.push_back(std::make_unique<Prober>());
    result.push_back(std::make_unique<SoftMajority>());

    return result;
}

void Tournament::PopulateStrategy()
{
    strategies = CreateStrategies();
    rankings.clear();

    for (const auto& strategy : strategies)
    {
        Ranking ranking;
        ranking.StrategyName = strategy->Name;
        rankings.push_back(ranking);
    }
}

void Tournament::AddResult(Ranking& ranking, int ownScore, int opponentScore)
{
    ranking.TotalPoint += ownScore;

    if (ownScore > opponentScore)
        ranking.Win++;
    else if (ownScore == opponentScore)
        ranking.Draw++;
    else
        ranking.Lose++;
}

void Tournament::Simulate()
{
    std::vector<std::unique_ptr<IStrategy>> mirrors = CreateStrategies();

    for (size_t i = 0; i < strategies.size(); ++i)
    {
        for (size_t j = i; j < strategies.size(); ++j)
        {
            int scoreA = 0;
            int scoreB = 0;

            if (i == j)
                PlayMatch(*strategies[i], *mirrors[i], scoreA, scoreB);
            else
                PlayMatch(*strategies[i], *strategies[j], scoreA, scoreB);

            AddResult(rankings[i], scoreA, scoreB);

            if (i != j)
                AddResult(rankings[j], scoreB, scoreA);
        }
    }
}

std::vector<Ranking> Tournament::GenerateFinalRankingByPoint() const
{
    std::vector<Ranking> result = rankings;

    std::sort(result.begin(), result.end(), [](const Ranking& r1, const Ranking& r2)
        {
            if (r1.TotalPoint != r2.TotalPoint)
                return r1.TotalPoint > r2.TotalPoint;

            if (r1.Win != r2.Win)
                return r1.Win > r2.Win;

            if (r1.Draw != r2.Draw)
                return r1.Draw > r2.Draw;

            return r1.Lose > r2.Lose;
        });

    return result;
}

std::vector<Ranking> Tournament::GenerateFinalRankingByWinDrawLoss() const
{
    std::vector<Ranking> result = rankings;

    std::sort(result.begin(), result.end(), [](const Ranking& r1, const Ranking& r2)
        {
            if (r1.Win != r2.Win)
                return r1.Win > r2.Win;
            if (r1.Draw != r2.Draw)
                return r1.Draw > r2.Draw;
            return r1.Lose > r2.Lose;
        });

    return result;
}

void Tournament::GetRoundPoints(Choice a, Choice b, int& pointA, int& pointB)
{
    if (a == Choice::Cooperate && b == Choice::Cooperate)
    {
        pointA = 3;
        pointB = 3;
    }
    else if (a == Choice::Cooperate && b == Choice::Betray)
    {
        pointA = 0;
        pointB = 5;
    }
    else if (a == Choice::Betray && b == Choice::Cooperate)
    {
        pointA = 5;
        pointB = 0;
    }
    else
    {
        pointA = 1;
        pointB = 1;
    }
}

void Tournament::PlayMatch( IStrategy& a,  IStrategy& b, int& scoreA, int& scoreB)
{
    a.Reset();
    b.Reset();

    std::vector<Choice> historyA;
    std::vector<Choice> historyB;

    scoreA = 0;
    scoreB = 0;

    for (int round = 0; round < RoundCount; ++round)
    {
        Choice choiceA = a.Decide(historyA, historyB);
        Choice choiceB = b.Decide(historyB, historyA);

        int pointA = 0;
        int pointB = 0;
        GetRoundPoints(choiceA, choiceB, pointA, pointB);

        scoreA += pointA;
        scoreB += pointB;

        historyA.push_back(choiceA);
        historyB.push_back(choiceB);
    }
}
