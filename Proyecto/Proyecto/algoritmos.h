#pragma once
#ifndef ALGORITMOS_H
#define ALGORITMOS_H


float distance(float,float,float,float,float,float);
void calculateCentroid(CVector3 &centroid, t3DObject *pObject);
void calculateAsteroidsInitPos(int);
bool chocamos(int i);
#endif