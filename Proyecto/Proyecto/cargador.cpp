#include "stdafx.h"
CLoad3DS g_Load3ds;								// This is 3DS class.  This should go in a good model class.
t3DModel g_3DModel;								// This holds the 3D Model info that we load in
UINT g_Texture[10] = {0};						// This holds the texture info, referenced by an ID

int   g_ViewMode	  = GL_TRIANGLES;			// We want the default drawing mode to be normal
bool  g_RotateObject  = true;					// Turn lighting on initially
float g_RotateX		  = 0.0f;					// This is the current value at which the model is rotated
float g_RotationSpeed = 0.8f;					// This is the speed that our model rotates.  (-speed rotates left)


//set up a structure for the texture system
CTextures Textures;

float	xy_aspect;				//aspect ratio variable

const bool DEBUG = true;		//Specify if information is written about what is going on to the console window

void Load_3DS_Object(char *path)
{
	// Load the *.3DS file.  We just pass in an address to our t3DModel structure and the file name string we want to load
	g_Load3ds.Import3DS(&g_3DModel, path);			// Load our .3DS file into our model structure

	// Depending on how many textures we found, load each one
	for(int i = 0; i < g_3DModel.numOfMaterials; i++)
	{
		// Check to see if there is a file name to load in this material
		if(strlen(g_3DModel.pMaterials[i].strFile) > 0)
		{
			// We pass in our global texture array, the name of the texture, and an ID to reference it.	
			Textures.LoadTexture(g_3DModel.pMaterials[i].strFile, g_Texture[i]);				
		}

		// Set the texture ID for this material
		g_3DModel.pMaterials[i].texureId = i;
	}
}



/******************************************* DrawObject *******************************************/
void Draw_3DS_Object(int pX, int pY, int pZ, int pSize)
{
	// We want the model to rotate around the axis so we give it a rotation
	// value, then increase/decrease it. You can rotate right of left with the arrow keys.

	glPushMatrix();

	if (cont<500){
	glRotatef(g_RotateX, 0, 1.0, 0);
	cont++;
	cout<<cont<<endl;
	}
	if (cont==500){
	glRotatef(g_RotateX,0.1f,0,0);
	}
	// Rotate the object around the Y-Axis	
	if (g_RotateObject  )	{	 g_RotateX += g_RotationSpeed;	}	// Increase the speed of rotation
	
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
			//glEnable(GL_TEXTURE_2D);
			glActiveTexture(GL_TEXTURE0);
			// Reset the color to normal again
			//glColor3ub(255, 255, 255);

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
}