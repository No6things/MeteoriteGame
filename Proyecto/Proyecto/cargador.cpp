#include "stdafx.h"
//z mueve el eje horizontal -derecha + izquierda
//y mueve el eje vertical   -abajo	 + arriba
//x mueve el eje z			-atras   + delante
#define MAX_OBJECTS 204
CLoad3DS g_Load3ds;														// This holds the 3D Model info that we load in
t3DModel g_3DModel, asteroid;											// This holds models
UINT g_Texture[10] = {0}, g_AstTexture[10] = {0};						// This holds the texture info, referenced by an ID
int   g_ViewMode	  = GL_TRIANGLES;									// We want the default drawing mode to be normal
float astpos = 0.0f;
char* dir = "Assets/Models/Asteroid/asteroid 3DS.3ds";
int idList;
bool support_list;


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

}

void Draw_Model(t3DModel & Model, UINT *Texture){
	for(int i = 0; i <Model.numOfObjects; i++){
		if(Model.pObject.size() <= 0) break;

		t3DObject *pObject = &Model.pObject[i];
			
		if(pObject->bHasTexture){
			glEnable(GL_TEXTURE_2D);
			glColor3ub(255, 255, 255);
			glBindTexture(GL_TEXTURE_2D, Texture[pObject->materialID]);
		}else{
			glDisable(GL_TEXTURE_2D);
			glColor3ub(255, 255, 255);
		}
		glBegin(GL_TRIANGLES);
			for(int j = 0; j < pObject->numOfFaces; j++){
				for(int whichVertex = 0; whichVertex < 3; whichVertex++){
					int index = pObject->pFaces[j].vertIndex[whichVertex];
					glNormal3f(pObject->pNormals[index].x, pObject->pNormals[index].y, pObject->pNormals[index].z);

					if(pObject->bHasTexture){
						if(pObject->pTexVerts)
							glTexCoord2f(pObject->pTexVerts[ index ].x, pObject->pTexVerts[index].y);
						
					}else{ // if the size is at > 1 and material ID != -1, then it is a valid material.
						if(g_3DModel.pMaterials.size() && pObject->materialID >= 0){
							BYTE *pColor = g_3DModel.pMaterials[pObject->materialID].color; // Get and set the color that the object is, since it must not have a texture
							glColor3ub(pColor[0], pColor[1], pColor[2]);// Assign the current color to this model
						}
					}
					// Pass in the current vertex of the object (Corner of current face)
					glVertex3f(pObject->pVerts[index].x, pObject->pVerts[index].y, pObject->pVerts[index].z); //Esta son las coordenadas iniciales que tiene el objeto :P 
				}
			}
		glEnd();// End the model drawing
	}
}

void CreateList(){
	idList = glGenLists(204);
	support_list = idList > 0;
	if(support_list){
		//Lista de la nave:
		glNewList(idList, GL_COMPILE); //Nave :P 
			Draw_Model(g_3DModel, g_Texture);
		glEndList();
		for(int i=1; i<MAX_OBJECTS-1; ++i){ //Lista de los asteroides
			glNewList(idList+i, GL_COMPILE); //Asteroide i-ésimo 
				Draw_Model(asteroid, g_AstTexture);
			glEndList();
		}
		//Falta la luna :)
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
	if(!golpe){
		if (derecha){
	
			g_TranslateX-=40;
			ship_position.z-=40;
			glTranslatef (g_TranslateX,0.0f,0.0f);
			glRotatef (g_smooth_movement,0.0f,0.0f,1.0f);
			g_smooth_movement++;
			g_smooth_movement = min(g_smooth_movement, 25.0);
		}

		else if (izquierda){

			g_TranslateX+=40;
			ship_position.z+=40;
			glTranslatef(g_TranslateX,0.0f,0.0f);
			glRotatef (g_smooth_movement,0.0f,0.0f,1.0f);
			g_smooth_movement--;
			g_smooth_movement = max(g_smooth_movement, -25.0);
			
		
		}
	}else if (cont<5){
		
		glRotatef(20,-1.0f,0.0f,1.0f);
		cont++;

	}else if (cont>=5 && cont<10){
		glRotatef(-20,-1.0f,0.0f,1.0f);
		cont++;
	}

	if (cont>=10){
		golpe=false;
		cont=0;
	}
	
	glTranslatef(-centroid.x, -centroid.y, -centroid.z);
	if(support_list)
		glCallList(idList); //Dibujar nave
	else
		Draw_Model(g_3DModel, g_Texture);
	glPopMatrix();
	
	glPushMatrix();		//bounding volume sphere
		glTranslatef(ship_position.x,ship_position.y,ship_position.z);
		glutWireSphere(radius,20,20);
	glPopMatrix();

	if(segs%6==0)if(wave_started==NO)speed_constant+=3;  //aumentamos la velocidad cada 6 segundos

	if (segs%3==0){						//pero hacemos rondas de meteoros cada 3 segundo por la velocidad de los mismo
		if(wave_started==NO){			//control de estados para evitar movernos de rango varias veces en un segundo
			wave_started=YES;		
															//Establecimiento de rondas dependiendo del nivel
			if(dificultad==EASY)ronda=rand()%2+3;				//---Si es facil, 3-4 meteroso
			else ronda=rand()%4+4;								//---Si no, 4-5

			if (asteroids_upperb+ronda<101){						//Desplazamiento de rango normal
				cout<<"chill pill"<<endl;
				asteroids_upperb+=ronda;

			}else if(asteroids_upperb+ronda>=101 && dificultad==EASY){	// ultimo rango de meteoritos
				cout<<"no eres tan malo- ahi viene la recta final"<<endl;
				asteroids_upperb=101;
				dificultad++;											//cambiando a dificultad GANONDORF || TEMPLEOFWATER

			}else if(dificultad==GANONDORF){						//reiniciando secuencia de meteoros
				cout<<"reiniciando ronda"<<endl;
				speed_constant=30;
				calculateAsteroidsInitPos(101);
				asteroids_upperb=ronda;

			}else{ //lanzar luna
				cout<<"¡¡¡¡¡¡Link's nightmare is coming!!!!!!"<<endl;
			}
		}
	}else if (segs%6==5)wave_started=NO;								//cambiando de estado


	for(int i=0; i<asteroids_upperb; i++){ //drawing asteroids
	
		glPushMatrix();

			if(!asteroids_passed[i]){
				if ((!chocamos(i))||(chocamos(i)&&golpe)){
					glScalef(5.0f, 5.0f, 5.0f);
					glTranslated(asteroids_positions[i].x, asteroids_positions[i].y, asteroids_positions[i].z);

					if(support_list)
						glCallList(idList+1+i); //Dibujar nave
					else
						Draw_Model(asteroid, g_AstTexture);
				}else{					//insertar llamada a animacion y salir de juego
					asteroids_passed[i]=1;
					cout<<"chocamos con el asteroide - "<<i<<endl; 
					//golpe=true;
				}
				asteroids_positions[i].x+=max((0.5*speed_constant),80);

			}

			if (asteroids_positions[i].x>=4000)asteroids_passed[i]=1;
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