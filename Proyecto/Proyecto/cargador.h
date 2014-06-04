#pragma once
#ifndef _CARGADOR_H
#define _CARGADOR_H
#include "3ds.h"
void Load_3DS_Object(char *path);
void Draw_Model(t3DModel & Model, UINT *Texture);
void Draw_3DS_Object(int pX, int pY, int pZ, int pSize);
void CreateList();
void Load_3DS_Asteroid(char *path);
#endif