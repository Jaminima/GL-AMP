#pragma once

#ifndef __GLManager
#define __GLManager

#include "GL/freeglut.h"
#include "GL/glut.h"
#include "Color.h"
#include <iostream>
#include <string>

namespace GL {

	unsigned int window_Width=0, window_Height=0;
	Color* screenBuffer;

	void DisplayFrame() {
		glDrawPixels(window_Width, window_Height, GL_RGBA, GL_UNSIGNED_BYTE, screenBuffer);
		glutSwapBuffers();
	}

	void GlutIdling() {

	}

	void InitializeWindow(int argc, char** argv, std::string title = "GL AMP", unsigned int width = 1280, unsigned int height = 720) {
		window_Height = height;
		window_Width = width;

		screenBuffer = new Color[window_Height * window_Width];

		glutInit(&argc, argv);
		glutInitWindowSize(window_Width, window_Height);
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
		glutCreateWindow(title.c_str());

		glutDisplayFunc(DisplayFrame);
		glutIdleFunc(GlutIdling);
	}

	void SetMouseMoveFunc(void moveFunc(int,int)) {
		glutPassiveMotionFunc(moveFunc);
	}

	void SetKeyboardFunc(void keyFunc(unsigned char, int, int)) {
		glutKeyboardFunc(keyFunc);
	}

	void StartGL() {
		glutMainLoop();
	}

};

#endif // !__GLManager
