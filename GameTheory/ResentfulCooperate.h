#pragma once

#include "IStrategy.h"

class ResentfulCooperate : public IStrategy
{
public:
    ResentfulCooperate() : IStrategy("Resent fulCooperate") {}

	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override
	{
        if (!betrayed && !opponentPreviousDecisions.empty() && opponentPreviousDecisions.back() == Choice::Betray)
        {
            betrayed = true;
        }

        return betrayed ? Choice::Betray : Choice::Cooperate;
	}

    void Reset() override
    {
        betrayed = false;
    }

private: 
	bool betrayed = false;
};