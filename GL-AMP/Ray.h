#pragma once


#ifndef __Ray
#define __Ray

#include "Point.h"
#include "GL-Manager.h"
#include "ScreenPos.h"

class Ray {
public:
	Point origin, direction;

	Ray() restrict(amp,cpu) {}

	Ray(Point _origin, Point _direction) restrict(amp, cpu) {
		origin = _origin;
		direction = _direction;
	}

	Ray(Point _origin, Point _destination, bool NormaliseDirection) restrict(amp, cpu) {
		origin = _origin;

		direction = _destination / _origin;
		if (NormaliseDirection) direction.normalise();
	}
	
	ScreenPos GetScreenPosition(unsigned int width, unsigned int height) restrict(amp, cpu) {
		direction = direction / direction.z;
		return ScreenPos(floorf(direction.x * width), floorf(direction.y * height));
	}
};

#endif