#pragma once

#ifndef __Point
#define __Point

class Point {
public:
	union {
		float x, y, z;
		float xyz[3];
	};

	Point(float _x, float _y, float _z) restrict(amp,cpu) {
		x = _x;
		y = _y;
		z = _z;
	}
};

#endif // !__Point
