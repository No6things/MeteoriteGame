#include "stdafx.h"
int h=640, w=800, mousex, mousey, main_window,radius,radius2;
int cont=0;
float g_RotateY = 0.0f;
float g_TranslateX=0.0f;
float g_smooth_movement = 0.0f;
float pi = 4*atan(1.0f);
bool izquierda=false,derecha=false;
float g_TranslateX2=0.0f;
float speed_constant = 0.0f;
CVector3 asteroids_positions[101];
CVector3 ship_position;
Texto info("*****Sin Nombre******");
CVector3 red;
CVector3 centroid;	
CVector3 centroid2;
CTextures Textures;
int milis=0,segs=0,mins=0,hours=0;
int time_actual=0,time_inicial=0;
