#pragma once

#ifndef __Mesh
#define __Mesh

#include "Triangle.h"
#include "Shared.h"
#include "Scene-Manager.h"

class Mesh {
private:
	int TriStart = -1, TriEnd = -1, triCount = 0;

public:

	Mesh() restrict(amp, cpu) {

	}

	void RegisterTriangles(Triangle* triangles, int _triCount) restrict(cpu) {
		triCount = _triCount;
		TriStart = TriangleViewHead;
		TriangleViewHead += triCount;
		TriEnd = TriangleViewHead;

		for (int i = TriStart;i < TriEnd;i++) sceneTrianglesView[i] = triangles[i - TriStart];
	}

	Mesh(Triangle* triangles, int _triCount) restrict(cpu) {
		RegisterTriangles(triangles, _triCount);
	}
};

#endif // !__Mesh
