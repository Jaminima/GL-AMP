#pragma once

#ifndef __SPos
#define __SPos

class ScreenPos {
public:
	unsigned int x, y;

	ScreenPos(unsigned int _x, unsigned int _y) restrict(amp, cpu) {
		x = _x;
		y = _y;
	}
};

#endif