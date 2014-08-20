#include "SceneObjects.h"

////////////////////////////////////////////////////////////////////////
// Utworz budke
////////////////////////////////////////////////////////////////////////
Kabina::Kabina()
{
	//SetTexture(pTexKabina->GetName());
}

////////////////////////////////////////////////////////////////////////
// Pokaz obiekt - budka operatora dzwigu
////////////////////////////////////////////////////////////////////////
void Kabina::Display()
{
	glVertexPointer( 3, GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem[ 0 ] );
    glNormalPointer( GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem[ 0 ].normal );
    glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, texId );
    glTexCoordPointer( 2, GL_FLOAT, sizeof( std::vector<vector2f>::value_type ), &memtex[0] );
	glDrawArrays( GL_QUADS, 0, mem.size() );
}

////////////////////////////////////////////////////////////////////////
// Buduje Kabine w pamięci na stosie
////////////////////////////////////////////////////////////////////////
void Kabina::Build()
{
	const GLfloat f = 1.0 / 5.4;
	
	//rezerwacja pamięci
    mem.reserve( 6 * 4 * sizeof( std::vector<vertex3f>::value_type ) );
    
	// podloga
    mem.push_back(
        vertex3f( vector3f(-1.0, 0.0, 0.75),
                  vector3f(0.0, -1.0, 0.0) ) );
    mem.push_back(
        vertex3f( vector3f(-1.0, 0.0, -0.75),
                  vector3f(0.0, -1.0, 0.0) ) );                  
	mem.push_back(
        vertex3f( vector3f(1.0, 0.0, -0.75),
		          vector3f(0.0, -1.0, 0.0) ) );  
	mem.push_back(
        vertex3f( vector3f(1.0, 0.0, 0.75),
                  vector3f(0.0, -1.0, 0.0) ) );    

	// lewa sciana
	mem.push_back(
        vertex3f( vector3f(-1.0, 0.0, -0.75),
		          vector3f(0.0, 0.0, -1.0) ) );
    mem.push_back(
        vertex3f( vector3f(-1.0, 2.2, -0.75),
                  vector3f(0.0, 0.0, -1.0) ) );                  
	mem.push_back(
        vertex3f( vector3f(1.4, 2.2, -0.75),
                  vector3f(0.0, 0.0, -1.0) ) );  
	mem.push_back(
        vertex3f( vector3f(1.0, 0.0, -0.75),
                  vector3f(0.0, 0.0, -1.0) ) );

	// tylna sciana
	mem.push_back(
        vertex3f( vector3f(-1.0, 0.0, -0.75),
                  vector3f(-1.0, 0.0, 0.0) ) );
    mem.push_back(
        vertex3f( vector3f(-1.0, 2.2, -0.75),
                  vector3f(-1.0, 0.0, 0.0) ) );
	mem.push_back(
        vertex3f( vector3f(-1.0, 2.2, 0.75),
                  vector3f(-1.0, 0.0, 0.0) ) ); 
    mem.push_back(
        vertex3f( vector3f(-1.0, 0.0, 0.75),
                  vector3f(-1.0, 0.0, 0.0) ) ); 

	// gorna sciana
	mem.push_back(
        vertex3f( vector3f(-1.0, 2.2, 0.75),
                  vector3f(0.0, 1.0, 0.0) ) );
    mem.push_back(
        vertex3f( vector3f(-1.0, 2.2, -0.75),
                  vector3f(0.0, 1.0, 0.0) ) );
	mem.push_back(
        vertex3f( vector3f(1.4, 2.2, -0.75),
                  vector3f(0.0, 1.0, 0.0) ) );  
	mem.push_back(
        vertex3f( vector3f(1.4, 2.2, 0.75),
                  vector3f(0.0, 1.0, 0.0) ) );

	// przednia sciana
	mem.push_back(
        vertex3f( vector3f(1.0, 0.0, 0.75),
                  vector3f(0.98, -0.2, 0.0) ) );
    mem.push_back(
        vertex3f( vector3f(1.4, 2.2, 0.75),
                  vector3f(0.98, -0.2, 0.0) ) );                  
	mem.push_back(
        vertex3f( vector3f(1.4, 2.2, -0.75),
                  vector3f(0.98, -0.2, 0.0) ) );  
	mem.push_back(
        vertex3f( vector3f(1.0, 0.0, -0.75),
                  vector3f(0.98, -0.2, 0.0) ) );
                  
	// prawa sciana
	mem.push_back(
        vertex3f( vector3f(-1.0, 0.0, 0.75),
                 vector3f(0.0, 0.0, 1.0) ) );
    mem.push_back(
        vertex3f( vector3f(-1.0, 2.2, 0.75),
                 vector3f(0.0, 0.0, 1.0) ) );                  
	mem.push_back(
        vertex3f( vector3f(1.4, 2.2, 0.75),
                 vector3f(0.0, 0.0, 1.0) ) );  
	mem.push_back(
        vertex3f( vector3f(1.0, 0.0, 0.75),
                 vector3f(0.0, 0.0, 1.0) ) );

	memtex.push_back(vector2f(1.5 * f, 1.5 * f));
	memtex.push_back(vector2f(1.5 * f, 0.0));
	memtex.push_back(vector2f(3.5 * f, 0.0));
	memtex.push_back(vector2f(3.5 * f, 1.5 * f));
	
	memtex.push_back(vector2f(1.5 * f, 1.5 * f));
	memtex.push_back(vector2f(1.5 * f, 3.7 * f));
	memtex.push_back(vector2f(3.9 * f, 3.7 * f));
	memtex.push_back(vector2f(3.5 * f, 1.5 * f));

	memtex.push_back(vector2f(0.0, 1.5 * f));
	memtex.push_back(vector2f(0.0, 3.7 * f));
	memtex.push_back(vector2f(1.5 * f, 3.7 * f));
	memtex.push_back(vector2f(1.5 * f, 1.5 * f));

	memtex.push_back(vector2f(1.5 * f, 1.5 * f));
	memtex.push_back(vector2f(1.5 * f, 0.0));
	memtex.push_back(vector2f(3.5 * f, 0.0));
	memtex.push_back(vector2f(3.5 * f, 1.5 * f));

	memtex.push_back(vector2f(3.9 * f, 1.5 * f));
	memtex.push_back(vector2f(3.9 * f, 3.7 * f));
	memtex.push_back(vector2f(5.4 * f, 3.7 * f));
	memtex.push_back(vector2f(5.4 * f, 1.5 * f));

	memtex.push_back(vector2f(1.5 * f, 1.5 * f));
	memtex.push_back(vector2f(1.5 * f, 3.7 * f));
	memtex.push_back(vector2f(3.9 * f, 3.7 * f));
	memtex.push_back(vector2f(3.5 * f, 1.5 * f));                 
}

GLuint Kabina::GetTexture(std::string Filename)
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
