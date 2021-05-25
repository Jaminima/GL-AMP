#pragma once

#ifndef __Mesh
#define __Mesh

#include "Triangle.h"
#include "Scene-Manager.h"

class Mesh {
private:
	int TriStart = -1, TriEnd = -1, triCount = 0;

public:

	Mesh() restrict(amp, cpu) {

	}

	Mesh(Triangle* triangles, int _triCount) restrict(cpu) {
		triCount = _triCount;
		TriStart = TriangleViewHead;
		TriangleViewHead += triCount;
		TriEnd = TriangleViewHead;
	}
};

#endif // !__Mesh
