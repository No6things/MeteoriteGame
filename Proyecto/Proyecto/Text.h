#pragma once
#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "GlobalHeader.h"

class Text{
	private:
		//Atributtes:
		int frame,time,timebase;
		char msj[255],msj1[255];
		char *projectName;
		GLfloat fps;

	public:
		//Constructor
		Text(char *);

		//Methods:
		void calculateFramePerSecond();
		void displayText(char*, float, float, int, int, glm::vec3, void*,int);
		void displayFPS(float, float, int, int, glm::vec3, void*, int);
		void displayFPS(unsigned int);
};

#endif