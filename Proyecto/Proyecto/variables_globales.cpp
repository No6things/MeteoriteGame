#include "stdafx.h"
int h=640, w=800, mousex, mousey, main_window,radius,radius2, dificultad=EASY, ronda, wave_started=NO;
int cont=0;
float g_RotateY = 0.0f;
float g_TranslateX=0.0f;
float g_smooth_movement = 0.0f;
int start_time=0;
float pi = 4*atan(1.0f);
bool izquierda=false,derecha=false;
float g_TranslateX2=0.0f;
float speed_constant = 20.0f;
CVector3 asteroids_positions[101];
int asteroids_passed[101];
extern int asteroids_upperb=0;
CVector3 ship_position;
Texto info("*****Sin Nombre******");
CVector3 red;
CVector3 centroid;	
CVector3 centroid2;
CTextures Textures;
int milis=0,segs=0,mins=0,hours=0;
int time_actual=0,time_inicial=0;
bool golpe=false;
float temblar=1;

float LightPos[]= {4.0f,3.0f,0.0f,0.0f};   // Light Position
float LightAmb[]={1.0f,0.0f,0.0f,1.0f} ;  // Ambient Light Values
float LightDif[]={0.0f,0.5f,0.0f,1.0f}  ; // Diffuse Light Values
float LightSpc[]={0.0f,1.0f,0.0f,1.0f}   ;// Specular Light Values
int vidas=20;