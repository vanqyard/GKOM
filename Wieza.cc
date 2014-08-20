#include "SceneObjects.h"
const GLfloat Yellow[4] = {0.84, 0.64, 0.12, 1.0};

////////////////////////////////////////////////////////////////////////
// Wieza
////////////////////////////////////////////////////////////////////////
Wieza::Wieza(GLuint noe)
{
	NumberOfElements = noe;	
	
	for(int i=0 ; i!=NumberOfElements ; i++)
		Elements.push_back(*(new SegmentWiezy));
}

////////////////////////////////////////////////////////////////////////
// Buduje SegmentWiezy w pamięci na stosie
////////////////////////////////////////////////////////////////////////
void Wieza::Build()
{
	for(int i=0 ; i!=NumberOfElements ; i++)
		Elements[i].Build();
}

////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////
void Wieza::Display()
{
	for(int i=0 ; i!=NumberOfElements ; i++) {
		glPushMatrix();
		glTranslatef(0.0, i*Elements[i].GetHeight(), 0.0);

		Elements[i].Display();

		glPopMatrix();
	}
}

////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////
GLuint Wieza::GetTexture(std::string Filename)
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
