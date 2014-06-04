#ifndef _MAIN_H
#define _MAIN_H


#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glaux.lib")

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
#pragma comment(lib, "data/lib/jpeg.lib")
//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
#define CAMERASPEED	0.03f				// The Camera Speed

#define SKYFRONT 0						// Give Front ID = 0
#define SKYBACK  1						// Give Back  ID = 1
#define SKYLEFT  2						// Give Left  ID = 2
#define SKYRIGHT 3						// Give Right ID = 3
#define SKYUP    4						// Give Up    ID = 4
#define SKYDOWN  5						// Give Down  ID = 5

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////







//////////////////////////////////////
//The tVector3 Struct
//////////////////////////////////////
typedef struct tVector3					// expanded 3D vector struct
{			
	tVector3() {}	// constructor
	tVector3 (float new_x, float new_y, float new_z) // initialize constructor	 
	{x = new_x; y = new_y; z = new_z;}
	// overload + operator so that we easier can add vectors
	tVector3 operator+(tVector3 vVector) {return tVector3(vVector.x+x, vVector.y+y, vVector.z+z);}
	// overload - operator that we easier can subtract vectors
	tVector3 operator-(tVector3 vVector) {return tVector3(x-vVector.x, y-vVector.y, z-vVector.z);}
	// overload * operator that we easier can multiply by scalars
	tVector3 operator*(float number)	 {return tVector3(x*number, y*number, z*number);}
	// overload / operator that we easier can divide by a scalar
	tVector3 operator/(float number)	 {return tVector3(x/number, y/number, z/number);}
	
	float x, y, z;						// 3D vector coordinates
}tVector3;


//////////////////////////////////////
//The CCamera Class
//////////////////////////////////////
class CCamera 
{
	public:

		tVector3 mPos;	
		tVector3 mView;		
		tVector3 mUp;			

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
		int mWindowWidth;
		int mWindowHeight;


		// This function let you control the camera with the mouse
		void Mouse_Move();

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

		void Rotate_View(float x, float y, float z);
		void Move_Camera(float cameraspeed);
		void Position_Camera(float pos_x, float pos_y,float pos_z,
			 				 float view_x, float view_y, float view_z,
							 float up_x,   float up_y,   float up_z);
};



//////////////////////////////////////
//	Global Variables
//////////////////////////////////////
extern	HDC			hDC;				// Device context
extern	HGLRC		hRC;				// Permanent rendering context
extern	HWND		hWnd;				// Holds our window handle
extern	HINSTANCE	hInstance;			// Holds the instance of the application



//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

//////////////////////////////////////
//	MAIN FUNCTIONS
//////////////////////////////////////
void Keyboard_Input();
void Draw_Grid();
void Draw_Skybox(float x, float y, float z, float width, float height, float length);

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////




#endif

//Ronny André Reierstad
//www.morrowland.com
//apron@morrowland.com