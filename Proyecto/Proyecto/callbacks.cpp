#include "stdafx.h"

void Reshape(int width, int height){
	w=width;
	h=height;
	//TwWindowSize(w,h);
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION); //Reseteo del sistema de coordenadas
	glLoadIdentity();
	//Frustrum
	gluPerspective(45.f,(float)w/(float)h,0.1f,10000.f);
	
	glMatrixMode(GL_MODELVIEW);
}

void Display()  // funcion para dibujar todo!
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(4000,10,0,0,0,0,0,1,0);
	
	//Dibujando modelo
	Draw_3DS_Object(0,0,0,500);

	glutSwapBuffers();
	glutPostRedisplay();


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

	// Set the view so y is up, view point is 2,2,2 and lookat is 0,0,0 
	glMatrixMode(GL_MODELVIEW);	
	
}


void Keyboard(unsigned char key, int x, int y) // callback para eventos del teclado
{
		switch(key)
		{
		case 27: //escape
			exit(0);
			break;
		case 127: //suprimir
			break;
		}
}

void MouseButton(int btn, int state, int x, int y)  // callback de lineas para el mouse
{
	/*if (!TwEventMouseButtonGLUT(btn,state,x,y)){

	}*/
}

void MouseMotion(int x, int y) //mover punto de control
{
	//if( !TwEventMouseMotionGLUT(x, y) )  // send event to AntTweakBar
    //{ 
		mousex=x;
		mousey=y;
//    }
}

void MousePosition(int x, int y){
	mousex=x;
	mousey=h-y;
}

void Callbacks(){
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(MouseButton);
	glutMotionFunc(MouseMotion);
	glutPassiveMotionFunc(MousePosition);
}