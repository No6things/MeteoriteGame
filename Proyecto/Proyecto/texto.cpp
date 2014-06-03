#include "stdafx.h"

Texto::Texto(char *projectN){
	frame = time = timebase= 0;
	projectName = projectN;
}

void Texto::mostrarTexto(char *text, float x, float y, int width, int height,CVector3 colorF, void* font,int depth){
	char *c;

	if (depth==GL_DEPTH_TEST)
		glDisable(GL_DEPTH_TEST);
	else if(depth==GL_CULL_FACE)
		glDisable(GL_CULL_FACE);
	

	glColor3f(colorF.x,colorF.y,colorF.z);

	glMatrixMode(GL_PROJECTION);

	glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, width, 0, height);
		glScalef(1.0f, -1.0f, 1.0f);
		glTranslatef(0.0f, (GLfloat)-height, 0.0f);
		glMatrixMode(GL_MODELVIEW);	
		glPushMatrix();
		glLoadIdentity();
		glRasterPos2f(x, y);
		for(c = text; *c != '\0'; c++)	
			glutBitmapCharacter(font, *c);
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);	

	if (depth==GL_DEPTH_TEST)
		glEnable(GL_DEPTH_TEST);
	else if(depth==GL_CULL_FACE)
		glEnable(GL_CULL_FACE);
}

void Texto::FramesPerSecond(){
	frame++;
	time= glutGet(GLUT_ELAPSED_TIME);
	if(time-timebase>1000){
		fps= (GLfloat)(frame * 1000.f/(time-timebase));
		timebase=time;
		frame= 0;
	}

	
	time_actual++;
	
	
	if (time_actual==30){
		time_actual=0;
		segs++;
	}

	if (segs==60){
		segs=0;
		mins++;
	}

	if (mins==60){
		mins=0;
		hours++;
	}
	
}

void Texto::mostrarFPS(float x, float y, int width, int height, CVector3 colorF,void* font,int depth){
	sprintf_s(msj1, "%s FPS: %.2f Vidas: %d Tiempo: %d:%d:%d",projectName, fps,3,hours,mins,segs);
	mostrarTexto(msj1, x, y, width, height, colorF,font,depth);
}
