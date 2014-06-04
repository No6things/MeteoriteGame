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

