#include "stdafx.h"

void skybox(){
	ImageDataRec *mImage = NULL;
	UINT mTexture;
	
	mImage= LoadJPG("Assets/SKB/SKB_FR.jpg");	
	glEnable(GL_TEXTURE_2D);
	// Generate a texture with the texture ID stored in the texture item
	glGenTextures(1, &mTexture);

	// Bind the texture to OpenGL and initalize the texture - GL_TEXTURE_2D tells it we are using a 2D texture
	glBindTexture(GL_TEXTURE_2D, mTexture);

	// Build Mipmaps - this builds different versions of the picture for distances to make the image look better at different distances
	// gluBuild2DMipmaps Parameters: (2D texture, 3 channels (RGB), bitmap width, bitmap height, It is an RGB format, data is stored as unsigned bytes, the actuall pixel data);
	
	//gluBuild2DMipmaps(GL_TEXTURE_2D, 3, mImage->sizeX, mImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, mImage->data);
	glTexImage2D( GL_TEXTURE_2D, 1, 0,mImage->sizeX, mImage->sizeY, 0,  GL_RGB, GL_UNSIGNED_BYTE, mImage->data );

	// Tell OpenGL the quality of our texture map.  
	//		GL_LINEAR_MIPMAP_LINEAR is the smoothest.  
	//		GL_LINEAR_MIPMAP_NEAREST is faster than GL_LINEAR_MIPMAP_LINEAR, but looks blochy and pixilated.  		
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

	glBegin(GL_QUADS);
		glColor3f(1.0,0.0,0.0);
		glNormal3f(0,1,1);
	    glTexCoord2f(0, 0);
		glVertex3f(0,-65536,-65536);

		glNormal3f(0,1,1);
	    glTexCoord2f(0, 1);
		glVertex3f(0,-65536,65536);

		glNormal3f(0,1,1);
		glTexCoord2f(1, 1);
		glVertex3f(0,65536,65536);

		glNormal3f(0,1,1);
		glTexCoord2f(1, 0);
		glVertex3f(0,65536,-65536);

	glEnd();

	
}