#pragma once

#include "IStrategy.h"

class Prober : public IStrategy
{
public:
	Prober() : IStrategy("Prober") {}

	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override
	{
		if (previousDecisions.empty())
			return Choice::Betray;

		if (previousDecisions.size() < 3)
			return Choice::Cooperate;

		bool opponentPunished = opponentPreviousDecisions[1] == Choice::Betray
			|| opponentPreviousDecisions[2] == Choice::Betray;

		if (!opponentPunished)
			return Choice::Betray;

		return opponentPreviousDecisions.back();
	}
};