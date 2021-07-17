#include "Timer.h"

Timer::Timer()
{
	Last();
}

float Timer::Mark()
{
	auto old = last;
	return std::chrono::duration<float>(Last() - old).count();
}

std::chrono::steady_clock::time_point Timer::Last()
{
	last = std::chrono::steady_clock::now();
	return last;
}
