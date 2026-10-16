#pragma once

#include <string>

struct Ranking
{
	std::string StrategyName;
	int TotalPoint = 0; 
	int Win = 0;
	int Draw = 0;
	int Lose = 0;
};