#pragma once

#ifndef __Point
#define __Point

#include <amp_math.h>
using namespace Concurrency::fast_math;

class Point {
public:
	union {
		float x, y, z;
		float xyz[3];
	};

	Point() restrict(amp,cpu) {
		x = 0;y = 0;z = 0;
	}

	Point(float _x, float _y, float _z) restrict(amp,cpu) {
		x = _x;
		y = _y;
		z = _z;
	}

	Point operator+(Point p) restrict(amp, cpu) {
		Point np(x + p.x, y + p.y, z + p.z);
		return np;
	}

	Point operator-(Point p) restrict(amp, cpu) {
		Point np(x - p.x, y - p.y, z - p.z);
		return np;
	}

	Point operator*(Point p) restrict(amp, cpu) {
		Point np(x * p.x, y * p.y, z * p.z);
		return np;
	}

	Point operator*(float f) restrict(amp, cpu) {
		Point np(x * f, y * f, z * f);
		return np;
	}

	Point operator/(Point p) restrict(amp, cpu) {
		Point np(x / p.x, y / p.y, z / p.z);
		return np;
	}

	Point operator/(float f) restrict(amp, cpu) {
		Point np(x / f, y / f, z / f);
		return np;
	}

	Point cross(Point p) restrict(amp, cpu) {
		Point np(
			y * p.z - z * p.y,
			z * p.x - x * p.z,
			x * p.y - y * p.x
		);
		return np;
	}

	float dot(Point p) restrict(amp, cpu) {
		return (x * p.x) + (y * p.y) + (z * p.z);
	}

	void normalise() restrict(amp, cpu) {
		float n = sqrt(dot(*this));
		x /= n;
		y /= n;
		z /= n;
	}

	float norm2() restrict(amp, cpu) { return dot(*this); }
	float norm() restrict(amp, cpu) { return sqrtf(norm2()); }
};

#endif // !__Point
