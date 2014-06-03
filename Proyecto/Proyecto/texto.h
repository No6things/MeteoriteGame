#pragma once
#ifndef _DISPLAY_H_
#define _DISPLAY_H_

class Texto{
	private:
		int frame,time,timebase;
		char msj1[255];
		char *projectName;
		GLfloat fps;

	public:
		Texto(char *);
		void FramesPerSecond();
		void mostrarTexto(char*, float, float, int, int, CVector3, void*,int);
		void mostrarFPS(float, float, int, int, CVector3, void*, int);
};

#endif