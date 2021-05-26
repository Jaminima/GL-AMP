#pragma once

#ifndef __FPSTracker
#define __FPSTracker

#include <iostream>
#include <chrono>

namespace FPS {
	unsigned int frame_count = 0;

	time_t sTime = clock();

	void LogFrame() {
		frame_count++;
	}

	bool TimePassed(unsigned int delayMS) {
		double d = std::difftime(clock(), sTime);
		return d > delayMS;
	}

	unsigned int CollectFrameCount() {
		unsigned int f = frame_count;
		frame_count = 0;
		sTime = clock();
		return f;
	}

}

#endif // !__FPSTracker
