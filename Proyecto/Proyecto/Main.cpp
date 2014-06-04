#include "stdafx.h"
#include "main.h"

UINT SkyboxTexture[6];

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
	

				           // Position      View(target)  Up
	// Load the Skybox textures
	
	glMatrixMode(GL_MODELVIEW);
}

void DibujarSkybox(float x, float y, float z, float width, float height, float length)
{
	// Center the Skybox around the given x,y,z position
	x = x - width  / 2;
	y = y - height / 2;
	z = z - length / 2;


	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, SkyboxTexture[SKYFRONT]);
	glBegin(GL_QUADS);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,		  y,		z+length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,		  y+height, z+length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x+width, y+height, z+length); 
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x+width, y,		z+length);
	glEnd();

	// Draw Back side
	glBindTexture(GL_TEXTURE_2D, SkyboxTexture[SKYBACK]);
	glBegin(GL_QUADS);		
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x+width, y,		z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x+width, y+height, z); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,		  y+height,	z);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,		  y,		z);
	glEnd();

	// Draw Left side
	glBindTexture(GL_TEXTURE_2D, SkyboxTexture[SKYLEFT]);
	glBegin(GL_QUADS);		
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,		  y+height,	z);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,		  y+height,	z+length); 
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,		  y,		z+length);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,		  y,		z);		
	glEnd();

	// Draw Right side
	glBindTexture(GL_TEXTURE_2D, SkyboxTexture[SKYRIGHT]);
	glBegin(GL_QUADS);		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x+width, y,		z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x+width, y,		z+length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x+width, y+height,	z+length); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x+width, y+height,	z);
	glEnd();

	// Draw Up side
	glBindTexture(GL_TEXTURE_2D, SkyboxTexture[SKYUP]);
	glBegin(GL_QUADS);		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x+width, y+height, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x+width, y+height, z+length); 
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,		  y+height,	z+length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,		  y+height,	z);
	glEnd();

	// Draw Down side
	glBindTexture(GL_TEXTURE_2D, SkyboxTexture[SKYDOWN]);
	glBegin(GL_QUADS);		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,		  y,		z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,		  y,		z+length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x+width, y,		z+length); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x+width, y,		z);
	glEnd();

}


void Init(int argc, char* argv[]){  
	  red.x=255.0f;red.y=255.f;red.z=255.f; //color of fonts
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
	  calculateAsteroidsInitPos(101);					// Establishing asteroids initial position
	  //asteroids_positions[0].x = 0.0; asteroids_positions[0].y = 0.0; asteroids_positions[0].z = 0.0;
	  //asteroids_positions[1].x = -20.0; asteroids_positions[1].y= 50.0; asteroids_positions[1].z = 65.0;
	  //asteroids_positions[2].x = -1000.0; asteroids_positions[2].y= 50.0; asteroids_positions[2].z = -120.0;
	  JPEG_Skybox(SkyboxTexture,"data/texture/front.jpg",  SKYFRONT);
	JPEG_Skybox(SkyboxTexture,"data/texture/back.jpg",   SKYBACK);
	JPEG_Skybox(SkyboxTexture,"data/texture/left.jpg",   SKYLEFT);
	JPEG_Skybox(SkyboxTexture,"data/texture/right.jpg",  SKYRIGHT);
	JPEG_Skybox(SkyboxTexture,"data/texture/up.jpg",     SKYUP);
	JPEG_Skybox(SkyboxTexture,"data/texture/down.jpg",   SKYDOWN);
	DibujarSkybox(0,0,0,10000,100000,100000);
}

int main(int argc, char* argv[])
{
	srand((unsigned)time(NULL));
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