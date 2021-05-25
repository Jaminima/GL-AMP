#pragma once

#ifndef __Triangle
#define __Triangle

#include "Point.h"

class Triangle {

public:
	Point p1, p2, p3;

	Triangle(Point _p1, Point _p2, Point _p3) restrict(amp,cpu) {
		p1 = _p1;
		p2 = _p2;
		p3 = _p3;
	}
};

#endif // !__Triangle
