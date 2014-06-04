#include "stdafx.h"

float distance(float x2, float y2, float z2, float x, float y, float z){
	float hueres=(x2-x)*(x2-x)+(y2-y)*(y2-y)+(z2-z)*(z2-z);
	return sqrtf(hueres);
}

void calculateCentroid(CVector3 &centroid, t3DObject *pObject){
	for(int i=0; i<pObject->numOfVerts; i++){
		centroid.x+=pObject->pVerts[i].x;
		centroid.y+=pObject->pVerts[i].y;
		centroid.z+=pObject->pVerts[i].z;
	}
	centroid.x/=pObject->numOfVerts;
	centroid.y/=pObject->numOfVerts;
	centroid.z/=pObject->numOfVerts;
}
void calculateAsteroidsInitPos(int tam){
	  for(int i=0;i<tam;i++){
		asteroids_passed[i]=0;
		asteroids_positions[i].x=-(rand()%900);
		asteroids_positions[i].y=(rand()%(h/3)-(h/3))+200;
		asteroids_positions[i].z=(rand()%(w/2)-(w/2))+200;
	  }
}
bool chocamos(int i){
	if(distance(asteroids_positions[i].x, asteroids_positions[i].y, asteroids_positions[i].z,ship_position.x,ship_position.y,ship_position.z)>(radius+radius2)) return false;
	else return true;
}