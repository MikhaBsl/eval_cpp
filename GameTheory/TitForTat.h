#pragma once

#include "IStrategy.h"

class TitForTat : public IStrategy
{
public:
	TitForTat() : IStrategy("Tit For Tat") {}

	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override
	{
		if (previousDecisions.empty())
			return Choice::Cooperate;

		return opponentPreviousDecisions.back();
	}
};