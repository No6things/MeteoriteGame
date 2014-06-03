#include "Text.h"

Text::Text(char *projectN){
	frame = time = timebase= 0;
	sprintf_s(msj,"Tarea 4 ICG: 0.0");
	projectName = projectN;
}

void Text::displayText(char *text, float x, float y, int width, int height,glm::vec3 colorF, void* font,int depth){
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

void Text::calculateFramePerSecond(){
	frame++;
	time= glutGet(GLUT_ELAPSED_TIME);

	if(time - timebase > 1000){
		fps= (GLfloat)(frame * 1000.f/(time-timebase));
		timebase=time;
		frame= 0;
	}
}

void Text::displayFPS(float x, float y, int width, int height, glm::vec3 colorF,void* font,int depth){
	sprintf_s(msj1, "FPS: %.2f", fps);
	displayText(msj1, x, y, width, height, colorF,font,depth);
}

void Text::displayFPS(unsigned int win){
	sprintf_s(msj, "%s FPS: %.2f", projectName, fps);
	glutSetWindow(win);
	glutSetWindowTitle(msj);
}