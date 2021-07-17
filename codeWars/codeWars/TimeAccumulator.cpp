#include "TimeAccumulator.h"
#include <iostream>

TimeAccumulator::TimeAccumulator()
	:
	total(0.0f),
	duration(0.0f)
{
	of.open("timing.txt", std::ios::app);
}

float TimeAccumulator::Mark(std::string msg)
{
	duration = t.Mark();
	total += duration;
	//std::cerr << "str: " << duration << "\n";
	of << msg << " " << duration << "\n";
	return duration;
}

float TimeAccumulator::Total()
{
	of << "total: " << total << "\n\n";
	of.close();
	return total;
}