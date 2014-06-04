#include "stdafx.h"
//z mueve el eje horizontal -derecha + izquierda
//y mueve el eje vertical   -abajo	 + arriba
//x mueve el eje z			-atras   + delante
CLoad3DS g_Load3ds;														// This holds the 3D Model info that we load in
t3DModel g_3DModel, asteroid;											// This holds models
UINT g_Texture[10] = {0}, g_AstTexture[10] = {0};						// This holds the texture info, referenced by an ID
int   g_ViewMode	  = GL_TRIANGLES;									// We want the default drawing mode to be normal
float astpos = 0.0f;
char* dir = "Assets/Models/Asteroid/asteroid 3DS.3ds";


void Load_3DS_Object(char *path)
{
	int temp;
	// Load the *.3DS file.  We just pass in an address to our t3DModel structure and the file name string we want to load
	g_Load3ds.Import3DS(&g_3DModel, path);			// Load our .3DS file into our model structure
	centroid.x = centroid.y = centroid.z  = 0;
	t3DObject *pObject = &g_3DModel.pObject[0];
	
	calculateCentroid(centroid,&g_3DModel.pObject[0]); //calculating ship's centroid

	ship_position.x=cos(276*pi/180.0)*centroid.x + sin(276*pi/180.0)*centroid.z; //position of the ship with a rotation of 276
	ship_position.y=centroid.y;
	ship_position.z=-sin(276*pi/180.0)*centroid.x + cos(276*pi/180.0)*centroid.z;
	radius=593;
	// Depending on how many textures we found, load each one
/*	for(int i = 0; i < g_3DModel.numOfMaterials; i++)
	{
		// Check to see if there is a file name to load in this material
		
		if(strlen(g_3DModel.pMaterials[i].strFile) > 0)
		{
			// We pass in our global texture array, the name of the texture, and an ID to reference it.	
			Textures.LoadTexture(g_3DModel.pMaterials[i].strFile, g_Texture[i]);				
		}

		// Set the texture ID for this material
		g_3DModel.pMaterials[i].texureId = i;
} */
	g_Load3ds = CLoad3DS();
	g_Load3ds.Import3DS(&asteroid, dir);
	calculateCentroid(centroid2,&asteroid.pObject[0]);
	radius2=65;

	cout<<"radio2-"<<radius2<<endl;
}

void Draw_Model(t3DModel Model){
	for(int i = 0; i < Model.numOfObjects; i++)
	{
		// Make sure we have valid objects just in case. (size() is in the vector class)
		if(Model.pObject.size() <= 0) break;

		// Get the current object that we are displaying
		t3DObject *pObject = &Model.pObject[i];
			
		// Check to see if this object has a texture map, if so bind the texture to it.
		if(pObject->bHasTexture) 
		{
			// Turn on texture mapping and turn off color
			glEnable(GL_TEXTURE_2D);

			// Reset the color to normal again
			glColor3ub(255, 255, 255);

			// Bind the texture map to the object by it's materialID
			glBindTexture(GL_TEXTURE_2D, g_Texture[pObject->materialID]);
		} 
		else 
		{
			// Turn off texture mapping and turn on color
			glDisable(GL_TEXTURE_2D);

			// Reset the color to normal again
			glColor3ub(255, 255, 255);
		}

		// This determines if we are in wireframe or normal mode
		glBegin(g_ViewMode);					// Begin drawing with our selected mode (triangles or lines)

			// Go through all of the faces (polygons) of the object and draw them
			for(int j = 0; j < pObject->numOfFaces; j++)
			{
				// Go through each corner of the triangle and draw it.
				for(int whichVertex = 0; whichVertex < 3; whichVertex++)
				{
					// Get the index for each point of the face
					int index = pObject->pFaces[j].vertIndex[whichVertex];
			
					// Give OpenGL the normal for this vertex.
					glNormal3f(pObject->pNormals[index].x, pObject->pNormals[index].y, pObject->pNormals[index].z);
				
					// If the object has a texture associated with it, give it a texture coordinate.
					if(pObject->bHasTexture) 
					{

						// Make sure there was a UVW map applied to the object or else it won't have tex coords.
						if(pObject->pTexVerts) 
						{
							//
							glTexCoord2f(pObject->pTexVerts[ index ].x, pObject->pTexVerts[ index ].y);
						}
					} 
					else  //Does not have texture
					{
						// if the size is at > 1 and material ID != -1, then it is a valid material.
						if(Model.pMaterials.size() && pObject->materialID >= 0) 
						{
							// Get and set the color that the object is, since it must not have a texture
							BYTE *pColor = Model.pMaterials[pObject->materialID].color;

							// Assign the current color to this model
							glColor3ub(pColor[0], pColor[1], pColor[2]);
						}
					}

					// Pass in the current vertex of the object (Corner of current face)
					glVertex3f(pObject->pVerts[ index ].x, pObject->pVerts[ index ].y, pObject->pVerts[ index ].z);
				}
			}

		glEnd();			// End the model drawing
	}
}
/******************************************* DrawObject *******************************************/
void Draw_3DS_Object(int pX, int pY, int pZ, int pSize)
{
	// We want the model to rotate around the axis so we give it a rotation
	// value, then increase/decrease it. You can rotate right of left with the arrow keys.

	glPushMatrix();
	glRotatef(276, 0.0f, 1.0f, 0.0f);
	glTranslatef(centroid.x, centroid.y, centroid.z);

	if (derecha){
	
		g_TranslateX-=5;
		ship_position.z-=5;
		glTranslatef (g_TranslateX,0.0f,0.0f);
		glRotatef (g_smooth_movement,0.0f,0.0f,1.0f);
		g_smooth_movement++;
		g_smooth_movement = min(g_smooth_movement, 25.0);
	}

	else if (izquierda){

		g_TranslateX+=5;
		ship_position.z+=5;
		glTranslatef(g_TranslateX,0.0f,0.0f);
		glRotatef (g_smooth_movement,0.0f,0.0f,1.0f);
		g_smooth_movement--;
		g_smooth_movement = max(g_smooth_movement, -25.0);
			
		
	}

	if (golpe && cont<5){
		
		glRotatef(20,0.0f,0.0f,1.0f);
		cont++;
	}

	if (golpe && cont>=5){
		glRotatef(-20,0.0f,0.0f,1.0f);
		cont++;
	}

	if (cont>=10){
	golpe=false;
	cont=0;
	}

	
	glTranslatef(-centroid.x, -centroid.y, -centroid.z);
	// We have a model that has a certain amount of objects and textures.  We want to go through each object 
	// in the model, bind it's texture map to it, then render it by going through all of it's faces (Polygons).
	// Since we know how many objects our model has, go through each of them.
	for(int i = 0; i < g_3DModel.numOfObjects; i++)
	{
		// Make sure we have valid objects just in case. (size() is in the vector class)
		if(g_3DModel.pObject.size() <= 0) break;

		// Get the current object that we are displaying
		t3DObject *pObject = &g_3DModel.pObject[i];
			
		// Check to see if this object has a texture map, if so bind the texture to it.
		if(pObject->bHasTexture) 
		{
			// Turn on texture mapping and turn off color
			glEnable(GL_TEXTURE_2D);

			// Reset the color to normal again
			glColor3ub(255, 255, 255);

			// Bind the texture map to the object by it's materialID
			glBindTexture(GL_TEXTURE_2D, g_Texture[pObject->materialID]);
		} 
		else 
		{
			// Turn off texture mapping and turn on color
			glDisable(GL_TEXTURE_2D);

			// Reset the color to normal again
			glColor3ub(255, 255, 255);
		}

		// This determines if we are in wireframe or normal mode
		glBegin(g_ViewMode);					// Begin drawing with our selected mode (triangles or lines)

			// Go through all of the faces (polygons) of the object and draw them
			for(int j = 0; j < pObject->numOfFaces; j++)
			{
				// Go through each corner of the triangle and draw it.
				for(int whichVertex = 0; whichVertex < 3; whichVertex++)
				{
					// Get the index for each point of the face
					int index = pObject->pFaces[j].vertIndex[whichVertex];
			
					// Give OpenGL the normal for this vertex.
					glNormal3f(pObject->pNormals[index].x, pObject->pNormals[index].y, pObject->pNormals[index].z);
				
					// If the object has a texture associated with it, give it a texture coordinate.
					if(pObject->bHasTexture) 
					{
						// Make sure there was a UVW map applied to the object or else it won't have tex coords.
						if(pObject->pTexVerts) 
						{
							//
							glTexCoord2f(pObject->pTexVerts[ index ].x, pObject->pTexVerts[ index ].y);
						}
					} 
					else  //Does not have texture
					{
						// if the size is at > 1 and material ID != -1, then it is a valid material.
						if(g_3DModel.pMaterials.size() && pObject->materialID >= 0) 
						{
							// Get and set the color that the object is, since it must not have a texture
							BYTE *pColor = g_3DModel.pMaterials[pObject->materialID].color;

							// Assign the current color to this model
							glColor3ub(pColor[0], pColor[1], pColor[2]);
						}
					}

					// Pass in the current vertex of the object (Corner of current face)
					glVertex3f(pObject->pVerts[ index ].x, pObject->pVerts[ index ].y, pObject->pVerts[ index ].z);
				}
			}

		glEnd();			// End the model drawing
	}
	glPopMatrix();
	
	glPushMatrix();		//bounding volume sphere
		//glTranslatef(380.0f,200.0f,230.0f);
		glTranslatef(ship_position.x,ship_position.y,ship_position.z);
		glutWireSphere(radius,20,20);
	glPopMatrix();
	
	for(int i=0; i<3; i++){ //drawing asteroids
		glPushMatrix();
			glScalef(5.0f, 5.0f, 5.0f);
			glTranslated(asteroids_positions[i].x, asteroids_positions[i].y, asteroids_positions[i].z);
			if(distance(asteroids_positions[i].x, asteroids_positions[i].y, asteroids_positions[i].z,centroid.x,centroid.y,centroid.z)>(radius+radius2)){
				Draw_Model(asteroid);
			}else cout<<"choque"<<endl;

			asteroids_positions[i].x+=(0.5*speed_constant);
		glPopMatrix();
	}
	/*glPushMatrix();   //bounding volume sphere
		//glTranslatef(380.0f,200.0f,230.0f);
		glScalef(5.0f, 5.0f, 5.0f);
		Draw_Model(asteroid);
	glPopMatrix();
	glColor3f(255.0,255.0,255.0);
	glutWireSphere(radius2,20,20);
	*/
}