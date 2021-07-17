#pragma once
#include "Timer.h"

class TimeAccumulator
{
public:
	TimeAccumulator();
	float Mark();
	float Total() const;
private:
	Timer t;
	float total;
	float duration;
};

