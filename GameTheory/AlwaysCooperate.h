#pragma once

#include "IStrategy.h"

class AlwaysCooperate : public IStrategy
{
public:

	AlwaysCooperate() : IStrategy("Always Cooperate") {}

	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override
	{
		return Choice::Cooperate;
	}
};