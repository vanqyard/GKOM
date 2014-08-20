#include "SceneObjects.h"
const GLfloat Yellow[4] = {0.84, 0.64, 0.12, 1.0};

PrzednieRamie::PrzednieRamie(GLuint noe)
{
	NumberOfElements = noe;	
	
	for(int i=0 ; i!=NumberOfElements ; i++)
		Elements.push_back(*(new SegmentWiezy));
}

////////////////////////////////////////////////////////////////////////
// Buduje SegmentWiezy w pamięci na stosie
////////////////////////////////////////////////////////////////////////
void PrzednieRamie::Build()
{
	for(int i=0 ; i!=NumberOfElements ; i++)
		Elements[i].Build();
}

////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////
void PrzednieRamie::Display()
{
	for(int i=0 ; i!=NumberOfElements ; i++) {
		glPushMatrix();
		glTranslatef(i*Elements[i].GetHeight(), 0.0, 0.0);
		glRotatef(90.0, 0.0, 0.0, 1.0);
		Elements[i].Display();

		glPopMatrix();
	}
}

////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////
GLuint PrzednieRamie::GetTexture(std::string Filename)
{
	texId = SOIL_load_OGL_texture(
				Filename.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_POWER_OF_TWO
				| SOIL_FLAG_MIPMAPS
				| SOIL_FLAG_MULTIPLY_ALPHA
				| SOIL_FLAG_COMPRESS_TO_DXT
				| SOIL_FLAG_DDS_LOAD_DIRECT
				| SOIL_FLAG_INVERT_Y
			);

	if( texId > 0 )
	{
		glEnable( GL_TEXTURE_2D );
		glBindTexture( GL_TEXTURE_2D, texId );
			
		return 0;
	}
	else
		return 1;
}
