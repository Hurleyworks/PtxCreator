// from the Code Blacksmith
// https://www.youtube.com/watch?v=GV0JMHOpoEw

#pragma once

#include "NanoLog.hpp"
#include <chrono>

class ScopedStopWatch
{

 public:
	using Clock = std::conditional_t < std::chrono::high_resolution_clock::is_steady,
										std::chrono::high_resolution_clock,
										std::chrono::steady_clock>;
	ScopedStopWatch(const char function[] = "unknown function")
		: func(function)
	{}
	~ScopedStopWatch()
	{
		LOG_INFO << func << " took " << std::chrono::duration_cast< std::chrono::milliseconds >(Clock::now() - start).count() << " milliseconds";
	}

 private:
	const char * func = nullptr;
	Clock::time_point start = Clock::now();
};