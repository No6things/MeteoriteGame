#include "stdafx.h"

void myGlutIdle(void)
{
  if ( glutGetWindow() != main_window ) 
  glutSetWindow(main_window);  
  glutPostRedisplay();
}

void InitOpenGL()   // inicializa OpenGL
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45,w/h,0.1f,10000.f);
	glClearColor(0.f, 0.f, 0.f, 0.f);  //fondo negro
	glMatrixMode(GL_MODELVIEW);
}

void Init(int argc, char* argv[]){  
	  glutInit(&argc, argv);  //Iniciando GLUT y OpenGL
	  glutInitWindowPosition(250,250);
	  glutInitWindowSize(w, h);
	  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE |GLUT_DEPTH);
	  main_window= glutCreateWindow("*****Sin Nombre******");
	  InitOpenGL();

	  glEnable(GL_TEXTURE_2D);							// Habilitando mapeo de texturas
	  glShadeModel(GL_SMOOTH);							// Shader
	  glClearDepth(1.0f);									// Estado inicial del depth buffer
	  glEnable(GL_DEPTH_TEST);							// Testeo del depth buffer
	  glDepthFunc(GL_LEQUAL);								// Tipo de testeo
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	  //Cargando modelo de nave
	  Load_3DS_Object("Assets/Models/Firebird/Firebird.3ds"); 
	// Turn on a lighting and enable it, we will just use the default values in this case
	// We also want color, so we turn that on
	  glEnable(GL_LIGHT0);								// Turn on a light with defaults set
	  glEnable(GL_LIGHTING);							// Turn on lighting
	  glEnable(GL_COLOR_MATERIAL);						// Allow color

	  asteroids_positions[0].x = 0.0; asteroids_positions[0].y = 0.0; asteroids_positions[0].z = 0.0;
	  asteroids_positions[1].x = -20.0; asteroids_positions[1].y= 50.0; asteroids_positions[1].z = 65.0;
}

int main(int argc, char* argv[])
{
	cout << "ษออออออออออออออออออออออออออออออป" << endl;
	cout << "บ                              บ" << endl;
	cout << "บ         Sin Nombre           บ" << endl;
	cout << "บ                              บ" << endl;
	cout << "บ        By: SupahTeam         บ" << endl;
	cout << "บ                              บ" << endl;
	cout << "ศออออออออออออออออออออออออออออออผ" << endl;
	Init(argc, argv); //inicializando ventana, opengl, glut |Inicializar.h
	Callbacks();	  //asignando callbacks de glut			|Callbacks.h
	glutMainLoop();
  
	return 0;
}