#include "stdafx.h"

float distance(float x2, float y2, float z2, float x, float y, float z){
	float hueres=(x2-x)*(x2-x)+(y2-y)*(y2-y)+(z2-z)*(z2-z);
	return hueres;
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
		asteroids_positions[i].y=(rand()%(h/3)-(h/3))+150;
		asteroids_positions[i].z=(rand()%(w/2)-(w/2))+200;
	  }
}
bool chocamos(int i){
	if(distance(asteroids_positions[i].x, asteroids_positions[i].y, asteroids_positions[i].z,ship_position.x,ship_position.y,ship_position.z)> (radius+radius2) * (radius+radius2)) return false;
	else return true;
}

void skybox(){
	glBindTexture(GL_TEXTURE_2D, texID[0]);	//front
    glBegin(GL_POLYGON);
    {
        glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1000.0F, 3000.0f, 3500.0f);
 
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1000.0f, -3000.0f, 3500.0f);

        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-1000.0f, -3000.0f, -3500.0f);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-1000.0f, 3000.f, -3500.0f);
    }
    glEnd();

	glBindTexture(GL_TEXTURE_2D, texID[1]);	//back
    glBegin(GL_POLYGON);
    {
        glTexCoord2f(0.0f, 0.0f);
		glVertex3f(4010.0F, 3000.0f, -3500.0f);
 
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(4010.0f, -3000.0f, -3500.0f);

        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(4010.0f, -3000.0f, 3500.0f);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(4010.0f, 3000.f, 3500.0f);
    }
    glEnd();

	glBindTexture(GL_TEXTURE_2D, texID[2]);		//Left
    glBegin(GL_POLYGON);
    {
        glTexCoord2f(0.0f, 0.0f);
		glVertex3f(4010.0F, 3000.0f, 3500.0f);
 
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(4010.0f, -3000.0f, 3500.0f);

        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-1000.0f, -3000.0f, 3500.0f);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-1000.0f, 3000.f, 3500.0f);
    }
    glEnd();
	glBindTexture(GL_TEXTURE_2D, texID[3]);	//right
    glBegin(GL_POLYGON);
    {
        glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1000.0F, 3000.0f, -3500.0f);
 
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1000.0f, -3000.0f, -3500.0f);

        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(4010.0f, -3000.0f, -3500.0f);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(4010.0f, 3000.f, -3500.0f);
    }
    glEnd();
	glBindTexture(GL_TEXTURE_2D, texID[4]);	//up
    glBegin(GL_POLYGON);
    {
        glTexCoord2f(0.0f, 0.0f);
		glVertex3f(4010.0F, 3000.0f, 3500.0f);
 
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1000.0f, 3000.0f, 3500.0f);

        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-1000.0f, 3000.0f, -3500.0f);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(4010.0f, 3000.f, -3500.0f);
    }
    glEnd();
	glBindTexture(GL_TEXTURE_2D, texID[5]);	//down
    glBegin(GL_POLYGON);
    {
        glTexCoord2f(0.0f, 0.0f);
		glVertex3f(4010.0F, -3000.0f, 3500.0f);
 
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(4010.0f, -3000.0f, 3500.0f);

        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-1000.0f, -3000.0f, -3500.0f);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-1000.0f, -3000.f, -3500.0f);
    }
    glEnd();
}