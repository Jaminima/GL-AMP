#pragma once

#ifndef __Shared
#define __Shared

#include <amp.h>
using namespace concurrency;

unsigned int TriangleCap = 1000;
int TriangleViewHead = 0;

Triangle* sceneTriangles = new Triangle[TriangleCap];
array_view<Triangle, 1> *sceneTrianglesView = new array_view<Triangle, 1>(TriangleCap, sceneTriangles);


bool pick_accelerator()
{
	std::vector<accelerator> accs = accelerator::get_all();
	accelerator chosen_one;

	auto result = std::find_if(accs.begin(), accs.end(),
		[](const accelerator& acc)
		{
			return !acc.is_emulated &&
				acc.supports_double_precision &&
				!acc.has_display;
		});

	if (result != accs.end())
	{
		chosen_one = *(result);
	}

	std::wcout << chosen_one.description << std::endl;
	bool success = accelerator::set_default(chosen_one.device_path);
	return success;
}

#endif // !__Shared
