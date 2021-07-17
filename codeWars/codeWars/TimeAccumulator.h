#pragma once
#include "Timer.h"
#include <fstream>
#include <string>

class TimeAccumulator
{
public:
	TimeAccumulator();
	float Mark(std::string msg);
	float Total();
private:
	Timer t;
	float total;
	float duration;
	std::ofstream of;
};

