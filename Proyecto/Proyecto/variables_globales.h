#pragma once

#ifndef VARIABLES_GLOBALES_H
#define VARIABLES_GLOBALES_H

#define EASY			0
#define GANONDORF       1
#define TEMPLEOFWATER   2
#define YES  3
#define NO   4

extern int main_window, h, w, mousex, mousey, dificultad, ronda;
extern int cont;
extern float g_TranslateX;
extern float pi;
extern bool izquierda,derecha;
extern float speed_constant; //velocidad del meteoro
extern float g_smooth_movement; //Suavidad de movimiento
extern CVector3 asteroids_positions[101];
extern int asteroids_passed[101];
extern int  asteroids_upperb,wave_started;
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
extern float LightPos[] ;   // Light Position
extern float LightAmb[] ;  // Ambient Light Values
extern float LightDif[]  ; // Diffuse Light Values
extern float LightSpc[]   ;// Specular Light Values
extern int vidas;
#endif