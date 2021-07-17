#pragma once

#include <chrono>

class Timer
{
public:
	Timer();
	float Mark();
	std::chrono::steady_clock::time_point Last();
private:
	std::chrono::steady_clock::time_point last;
};

