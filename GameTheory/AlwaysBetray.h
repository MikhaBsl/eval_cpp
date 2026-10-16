#pragma once

#include "IStrategy.h"

class AlwaysBetray : public IStrategy
{
public:
	AlwaysBetray() : IStrategy("Always Betray") {}

	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override
	{
		return Choice::Betray;
	}
};