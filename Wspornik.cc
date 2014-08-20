#include "SceneObjects.h"
const GLfloat Yellow[4] = {0.84, 0.64, 0.12, 1.0};

////////////////////////////////////////////////////////////////////////
// Konstrukcja
////////////////////////////////////////////////////////////////////////
Wspornik::Wspornik(GLfloat h, GLfloat a)
{
	Height = h;
	Width = a;
}

////////////////////////////////////////////////////////////////////////
// Renderuje Wspornik - czyli prostopadloscian
// punkt odniesienia w jej srodku geomterycznym
////////////////////////////////////////////////////////////////////////
void Wspornik::Display()	
{
	const GLfloat halfW = Width / 2.0;
	const GLfloat halfH = Height / 2.0;
	const GLfloat t = Width / Height;
	
	glVertexPointer( 3, GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem[ 0 ] );
    glNormalPointer( GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem[ 0 ].normal );
    glBindTexture(GL_TEXTURE_2D, 0);
    //glTexCoordPointer( 2, GL_FLOAT, sizeof( std::vector<vector2f>::value_type ), &memtex[0] );	
	//glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, Yellow);
	glDrawArrays( GL_QUADS, 0, mem.size() );
}

////////////////////////////////////////////////////////////////////////
// Buduje Wspornik w pamięci na stosie
////////////////////////////////////////////////////////////////////////
void Wspornik::Build() 
{
	const GLfloat halfW = Width / 2.0;
	const GLfloat halfH = Height / 2.0;
	const GLfloat t = Width / Height;
	
    //rezerwacja pamięci
    mem.reserve( 4 * 4 * sizeof( std::vector<vertex3f>::value_type ) );
    
	// przednia sciana
    mem.push_back(
        vertex3f( vector3f(-halfW, -halfH, halfW),
                  vector3f( 0.0f, 0.0f, 1.0f ) ) );
    mem.push_back(
        vertex3f( vector3f(-halfW, halfH, halfW),
                  vector3f( 0.0f, 0.0f, 1.0f ) ) );                  
	mem.push_back(
        vertex3f( vector3f(halfW, halfH, halfW),
                  vector3f( 0.0f, 0.0f, 1.0f ) ) );  
	mem.push_back(
        vertex3f( vector3f(halfW, -halfH, halfW),
                  vector3f( 0.0f, 0.0f, 1.0f ) ) );    
    
    // tylna sciana
    mem.push_back(
        vertex3f( vector3f(-halfW, -halfH, -halfW),
                  vector3f( 0.0f, 0.0f, -1.0f ) ) );
    mem.push_back(
        vertex3f( vector3f(-halfW, halfH, -halfW),
                  vector3f( 0.0f, 0.0f, -1.0f ) ) );                  
	mem.push_back(
        vertex3f( vector3f(halfW, halfH, -halfW),
                  vector3f( 0.0f, 0.0f, -1.0f ) ) );  
	mem.push_back(
        vertex3f( vector3f(halfW, -halfH, -halfW),
                  vector3f( 0.0f, 0.0f, -1.0f ) ) );
    
    // lewa sciana
    mem.push_back(
        vertex3f( vector3f(-halfW, -halfH, -halfW),
                  vector3f( -1.0f, 0.0f, 0.0f ) ) );
    mem.push_back(
        vertex3f( vector3f(-halfW, halfH, -halfW),
                  vector3f( -1.0f, 0.0f, 0.0f ) ) );                  
	mem.push_back(
        vertex3f( vector3f(-halfW, halfH, halfW),
                  vector3f( -1.0f, 0.0f, 0.0f ) ) );  
	mem.push_back(
        vertex3f( vector3f(-halfW, -halfH, halfW),
                  vector3f( -1.0f, 0.0f, 0.0f ) ) );
                      
    // prawa sciana
    mem.push_back(
        vertex3f( vector3f(halfW, -halfH, -halfW),
                  vector3f( 1.0f, 0.0f, 0.0f ) ) );
    mem.push_back(
        vertex3f( vector3f(halfW, halfH, -halfW),
                  vector3f( 1.0f, 0.0f, 0.0f ) ) );                  
	mem.push_back(
        vertex3f( vector3f(halfW, halfH, halfW),
                  vector3f( 1.0f, 0.0f, 0.0f ) ) );  
	mem.push_back(
        vertex3f( vector3f(halfW, -halfH, halfW),
                  vector3f( 1.0f, 0.0f, 0.0f ) ) );	
	
	memtex.push_back(vector2f(0 , 0));
	memtex.push_back(vector2f(0 , 1));
	memtex.push_back(vector2f(1 , 0));
	memtex.push_back(vector2f(1 , 1));

	memtex.push_back(vector2f(0 , 0));
	memtex.push_back(vector2f(0 , 1));
	memtex.push_back(vector2f(1 , 0));
	memtex.push_back(vector2f(1 , 1));

	memtex.push_back(vector2f(0 , 0));
	memtex.push_back(vector2f(0 , 1));
	memtex.push_back(vector2f(1 , 0));
	memtex.push_back(vector2f(1 , 1));

	memtex.push_back(vector2f(0 , 0));
	memtex.push_back(vector2f(0 , 1));
	memtex.push_back(vector2f(1 , 0));
	memtex.push_back(vector2f(1 , 1));

}

GLuint Wspornik::GetTexture(std::string Filename)
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
