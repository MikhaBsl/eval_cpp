#pragma once

#include "IStrategy.h"

#include <random>

class RandomStrategy : public IStrategy
{
public:
	RandomStrategy() : IStrategy("Random"), engine(std::random_device{}()), distribution(0, 1) {}

	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override
	{
		return distribution(engine) == 0 ? Choice::Cooperate : Choice::Betray;
	}

private:
	std::mt19937 engine;
	std::uniform_int_distribution<int> distribution;
};