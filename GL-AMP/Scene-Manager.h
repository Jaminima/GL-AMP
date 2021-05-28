#pragma once

#include "Mesh.h"
#include "Shared.h"

#ifndef __SceneMngr
#define __SceneMngr

#include <amp.h>
using namespace Concurrency;

void ClearView() {
	array_view<Color,2> c = *GL::GetWriteBuffer();
	parallel_for_each(
		c.extent,
		[=](index<2> idx) restrict(amp) {
			c[idx].Set(0,0,0);
		}
	);
}

#endif