#include "stdafx.h"
#include "variables_globales.h"
int h=640, w=800, mousex, mousey, main_window;
int cont=0;
float g_RotateY = 0.0f;
float g_TranslateX=0.0f;
bool izquierda=false,derecha=false;
float g_TranslateX2=0.0f;
float speed_constant = 0.0f;
CVector3 asteroids_positions[101];