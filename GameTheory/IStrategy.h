#pragma once

#include "Choice.h"

#include <string>
#include <vector>

class IStrategy
{
public:

	IStrategy(const std::string& name) : Name(name) {}
	~IStrategy() = default;

	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) = 0;

	std::string Name;

	virtual void Reset() {};
};