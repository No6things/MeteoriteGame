#pragma once
#ifndef TextureManager_H
#define TextureManager_H

#pragma comment(lib, "FreeImage.lib")

class TextureManager
{
public:
	TextureManager(void);
	virtual ~TextureManager();

	//load a texture an make it the current texture
	//if texID is already in use, it will be unloaded and replaced with this texture
	bool loadTexture(const char* filename,	//where to load the file from
		unsigned int *texID,				//arbitrary id you will reference the texture by
											//does not have to be generated with glGenTextures
		bool isMipMap = false,              // ** AGREGADO ** (si es o no mipmap)
		GLenum image_format = GL_RGB,		//format the image is in
		GLint internal_format = GL_RGB,		//format to store the image in
		GLint level = 0,					//mipmapping level
		GLint border = 0                    //border size
		);			    

	//free the memory for a texture
	bool unloadTexture(const unsigned int texID);

	//set the current texture
	bool bindTexture(const unsigned int texID);

	//free all texture memory
	void unloadAllTextures();
	

protected:
	std::map<unsigned int, GLuint> m_texID;
};

#endif

