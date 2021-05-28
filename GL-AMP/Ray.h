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

	Ray(Point _origin, Point _destination, bool NormaliseDirection) {
		origin = _origin;

		direction = _destination / _origin;
		if (NormaliseDirection) direction.normalise();
	}
	
	//Assumes 
	ScreenPos GetScreenPosition() {
		#warning no camera rotation applied
		return ScreenPos(direction.x*GL::window_Width, direction.y*GL::window_Height);
	}
};

#endif