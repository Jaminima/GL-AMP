#pragma once

#ifndef __Color
#define __Color

class Color {
private:
	unsigned int rgba = 0xFF000000;

public:
	void Set(unsigned int r, unsigned int g, unsigned int b, unsigned int a = 255) restrict(amp, cpu) {
		rgba = ((a & 0xFF) << 24) | ((b & 0xFF) << 16) | ((g & 0xFF) << 8) | (r & 0xFF);
	}

	void Set(unsigned int* colors) {
		Set(colors[0], colors[1], colors[2], colors[3]);
	}

	unsigned int* Colors() {
		unsigned int* colors = new unsigned int[4];

		colors[0] = rgba & 0xFF;
		colors[1] = (rgba >> 8) & 0xFF;
		colors[2] = (rgba >> 16) & 0xFF;
		colors[3] = (rgba >> 24) & 0xFF;

		return colors;
	}
};

#endif // !__Color
