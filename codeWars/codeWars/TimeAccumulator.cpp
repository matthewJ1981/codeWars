#include "TimeAccumulator.h"
#include <iostream>

TimeAccumulator::TimeAccumulator()
	:
	total(0.0f),
	duration(0.0f)
{}

float TimeAccumulator::Mark()
{
	duration = t.Mark();
	total += duration;
	//std::cerr << "str: " << duration << "\n";
	return duration;
}

float TimeAccumulator::Total() const
{
	return total;
}