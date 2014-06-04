#pragma once

#ifndef VARIABLES_GLOBALES_H
#define VARIABLES_GLOBALES_H

#define EASY			0
#define GANONDORF       1
#define TEMPLEOFWATER   2

extern int main_window, h, w, mousex, mousey, dificultad, ronda;
extern int cont;
extern float g_TranslateX;
extern float pi;
extern bool izquierda,derecha;
extern float speed_constant; //velocidad del meteoro
extern float g_smooth_movement; //Suavidad de movimiento
extern CVector3 asteroids_positions[101];
extern int asteroids_passed[101];
extern int asteroids_lowerb, asteroids_upperb;
extern CVector3 ship_position;
extern CVector3 red;
extern CTextures Textures;
extern CVector3 centroid;	//centroide de la nave
extern CVector3 centroid2; //centroide del meteoro
extern int radius; //radio de la nave
extern int radius2; //radio del meteoro
extern Texto info;	//cuadro de texto
extern int time_actual,time_inicial;
extern int milis,segs,mins,hours;
extern bool golpe;
extern float temblar;
extern HDC			hDC;		// Private GDI Device Context
extern HGLRC		hRC;		// Permanent Rendering Context
extern HWND		hWnd;		// Holds Our Window Handle
extern HINSTANCE	hInstance;		// Holds The Instance Of The Application
#endif