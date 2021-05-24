#pragma once

#ifndef __GLManager
#define __GLManager

#include "GL/freeglut.h"
#include "GL/glut.h"
#include <iostream>
#include <string>

namespace GL {

	unsigned int window_Width=0, window_Height=0;

	void InitializeWindow(int argc, char** argv, std::string title = "GL AMP", unsigned int width = 1280, unsigned int height = 720) {
		window_Height = height;
		window_Width = width;

		glutInit(&argc, argv);
		glutInitWindowSize(window_Width, window_Height);
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
		glutCreateWindow(title.c_str());
			
		glutMainLoop();
	}

};

#endif // !__GLManager
