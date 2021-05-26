#pragma once

#ifndef __GLManager
#define __GLManager

#include "GL/freeglut.h"
#include "GL/glut.h"
#include "Color.h"
#include <iostream>
#include <string>

#include <amp.h>
using namespace concurrency;

namespace GL {

	unsigned int window_Width=0, window_Height=0, window_Size=0;

	Color* screenBuffer;
	array_view<Color, 2> *sBuffer1View;
	array_view<Color, 2>* sBuffer2View;

	bool BufferFlip = false;
	completion_future bufferSync;

	array_view<Color, 2>* GetWriteBuffer() {
		return BufferFlip ? sBuffer1View : sBuffer2View;
	}

	Color* GetReadBuffer() {
		return &screenBuffer[!BufferFlip];
	}

	void (*renderSceneFunction)(array_view<Color, 2>*);

	void DisplayFrame() {
		if (bufferSync.valid()) bufferSync.wait();
		glDrawPixels(window_Width, window_Height, GL_RGBA, GL_UNSIGNED_BYTE, GetReadBuffer());
		glutSwapBuffers();
		BufferFlip = !BufferFlip;
	}

	void GlutIdling() {
		array_view<Color, 2> *buff = GetWriteBuffer();
		renderSceneFunction(buff);

		glutPostRedisplay();

		bufferSync = buff->synchronize_async();
	}

	void InitializeWindow(int argc, char** argv, std::string title = "GL AMP", unsigned int width = 1280, unsigned int height = 720) {
		window_Height = height;
		window_Width = width;
		window_Size = height * width;

		screenBuffer = new Color[window_Size * 2];
		sBuffer1View = new array_view<Color, 2>(window_Height, window_Width, &screenBuffer[0]);
		sBuffer2View = new array_view<Color, 2>(window_Height, window_Width, &screenBuffer[window_Size]);
			
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
		if (renderSceneFunction!=0x0)
			glutMainLoop();
	}

};

#endif // !__GLManager
