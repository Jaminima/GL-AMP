#pragma once

#ifndef __SceneMngr
#define __SceneMngr

#include "Mesh.h"
#include <amp.h>

using namespace Concurrency;

unsigned int TriangleCap = 1000;
int TriangleViewHead = 0;

Triangle* sceneTriangles = new Triangle[TriangleCap];
array_view<Triangle, 1> sceneTrianglesView(TriangleCap, sceneTriangles);

#endif