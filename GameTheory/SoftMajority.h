#pragma once

#include "IStrategy.h"

#include <algorithm>

/*
* Step 4 : on coop puis on joue ce que l'adversaire fait le plus 
*/

class SoftMajority : public IStrategy
{
public:
	SoftMajority() : IStrategy("Soft Majority") {}

	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override
	{
		auto betrayCount = std::count(opponentPreviousDecisions.begin(), opponentPreviousDecisions.end(), Choice::Betray);
		auto cooperateCount = static_cast<long long>(opponentPreviousDecisions.size()) - betrayCount;

		return betrayCount > cooperateCount ? Choice::Betray : Choice::Cooperate;
	}
};