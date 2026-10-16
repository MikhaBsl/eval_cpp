#pragma once

#include "IStrategy.h"

class Pavlov : public IStrategy
{
public:
	Pavlov() : IStrategy("Pavlov") {}

	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override
	{
		if (previousDecisions.empty())
			return Choice::Cooperate;

		Choice lastChoice = previousDecisions.back();

		if (opponentPreviousDecisions.back() == Choice::Cooperate)
			return lastChoice;

		return lastChoice == Choice::Cooperate ? Choice::Betray : Choice::Cooperate;
	}
};