#pragma once

#ifndef __Shared
#define __Shared

unsigned int TriangleCap = 1000;
int TriangleViewHead = 0;

Triangle* sceneTriangles = new Triangle[TriangleCap];
array_view<Triangle, 1> sceneTrianglesView(TriangleCap, sceneTriangles);

#endif // !__Shared
