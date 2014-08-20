#include "SceneObjects.h"

Skybox::Skybox(GLfloat r) {
	Radius = r;
}

void Skybox::Display() {	

	glVertexPointer( 3, GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem_front[ 0 ] );
    glNormalPointer( GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem_front[ 0 ].normal );
    glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, texId_front );
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexCoordPointer( 2, GL_FLOAT, sizeof( std::vector<vector2f>::value_type ), &memtex_front[ 0 ] );
    glDrawArrays( GL_QUADS, 0, mem_front.size() );

    glVertexPointer( 3, GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem_left[ 0 ] );
    glNormalPointer( GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem_left[ 0 ].normal );
	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, texId_left );
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexCoordPointer( 2, GL_FLOAT, sizeof( std::vector<vector2f>::value_type ), &memtex_left[ 0 ] );
    glDrawArrays( GL_QUADS, 0, mem_left.size() );
    
    glVertexPointer( 3, GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem_right[ 0 ] );
    glNormalPointer( GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem_right[ 0 ].normal );
	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, texId_right );


	glTexCoordPointer( 2, GL_FLOAT, sizeof( std::vector<vector2f>::value_type ), &memtex_right[ 0 ] );
    glDrawArrays( GL_QUADS, 0, mem_right.size() );

	glVertexPointer( 3, GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem_back[ 0 ] );
    glNormalPointer( GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem_back[ 0 ].normal );
	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, texId_back );
	
	glTexCoordPointer( 2, GL_FLOAT, sizeof( std::vector<vector2f>::value_type ), &memtex_back[ 0 ] );
    glDrawArrays( GL_QUADS, 0, mem_back.size() );
	
    glVertexPointer( 3, GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem_top[ 0 ] );
    glNormalPointer( GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem_top[ 0 ].normal );
	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, texId_top );
	
	glTexCoordPointer( 2, GL_FLOAT, sizeof( std::vector<vector2f>::value_type ), &memtex_top[ 0 ] );
    glDrawArrays( GL_QUADS, 0, mem_top.size() );
    
    glVertexPointer( 3, GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem_bottom[ 0 ] );
    glNormalPointer( GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem_bottom[ 0 ].normal );
	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, texId_bottom );
	
	glTexCoordPointer( 2, GL_FLOAT, sizeof( std::vector<vector2f>::value_type ), &memtex_bottom[ 0 ] );
    glDrawArrays( GL_QUADS, 0, mem_bottom.size() );
    
}

void Skybox::Build() {
	/* rezerwacja pamięci */
	mem_front.reserve( 4 * sizeof( std::vector<vertex3f>::value_type ) );
	memtex_front.reserve( 4 * sizeof( vector2f ) );
	
	mem_left.reserve( 4 * sizeof( std::vector<vertex3f>::value_type ) );
	memtex_left.reserve( 4 * sizeof( vector2f ) );
	
	mem_right.reserve( 4 * sizeof( std::vector<vertex3f>::value_type ) );
	memtex_right.reserve( 4 * sizeof( vector2f ) );
	
	mem_back.reserve( 4 * sizeof( std::vector<vertex3f>::value_type ) );
	memtex_back.reserve( 4 * sizeof( vector2f ) );
	
	mem_top.reserve( 4 * sizeof( std::vector<vertex3f>::value_type ) );
	memtex_top.reserve( 4 * sizeof( vector2f ) );
	
	mem_bottom.reserve( 4 * sizeof( std::vector<vertex3f>::value_type ) );
	memtex_bottom.reserve( 4 * sizeof( vector2f ) );
	
	//przednia sciana		
	mem_front.push_back(vertex3f( vector3f( Radius, -Radius, -Radius ),
							vector3f( .0f, .0f, 1.0f ) ) );
	mem_front.push_back(vertex3f( vector3f( -Radius, -Radius, -Radius ),
							vector3f( .0f, .0f, 1.0f ) ) );
	mem_front.push_back(vertex3f( vector3f( -Radius, Radius, -Radius ),
							vector3f( .0f, .0f, 1.0f ) ) );
	mem_front.push_back(vertex3f( vector3f( Radius, Radius, -Radius ),
							vector3f( .0f, .0f, 1.0f ) ) );
	
	texId_front = GetTexture(Filename_front);	
	
	memtex_front.push_back(vector2f(0 , 0));
	memtex_front.push_back(vector2f(1 , 0));
	memtex_front.push_back(vector2f(1 , 1));
	memtex_front.push_back(vector2f(0 , 1));
	
	//lewa sciana
	mem_left.push_back(vertex3f( vector3f( Radius, -Radius, Radius ),
							vector3f( -1.0f, .0f, .0f ) ) );
	mem_left.push_back(vertex3f( vector3f( Radius, -Radius, -Radius ),
							vector3f( -1.0f, .0f, .0f ) ) );
	mem_left.push_back(vertex3f( vector3f( Radius, Radius, -Radius ),
							vector3f( -1.0f, .0f, .0f ) ) );
	mem_left.push_back(vertex3f( vector3f( Radius, Radius, Radius ),
							vector3f( -1.0f, .0f, .0f ) ) );
	
	texId_left = GetTexture(Filename_left);
	
	memtex_left.push_back(vector2f(0 , 0));
	memtex_left.push_back(vector2f(1 , 0));
	memtex_left.push_back(vector2f(1 , 1));
	memtex_left.push_back(vector2f(0 , 1));
	
	//prawa sciana
	GetTexture(Filename_right);
	mem_right.push_back(vertex3f( vector3f( -Radius, -Radius, -Radius ),
							vector3f( 1.0f, .0f, .0f ) ) );
	mem_right.push_back(vertex3f( vector3f( -Radius, -Radius, Radius ),
							vector3f( 1.0f, .0f, .0f ) ) );
	mem_right.push_back(vertex3f( vector3f( -Radius, Radius, Radius ),
							vector3f( 1.0f, .0f, .0f ) ) );
	mem_right.push_back(vertex3f( vector3f( -Radius, Radius, -Radius ),
							vector3f( 1.0f, .0f, .0f ) ) );

	texId_right = GetTexture(Filename_right);

	memtex_right.push_back(vector2f(0 , 0));
	memtex_right.push_back(vector2f(1 , 0));
	memtex_right.push_back(vector2f(1 , 1));
	memtex_right.push_back(vector2f(0 , 1));

	//tylnia sciana
	GetTexture(Filename_back);
	mem_back.push_back(vertex3f( vector3f( -Radius, -Radius, Radius ),
							vector3f( .0f, .0f, -1.0f ) ) );
	mem_back.push_back(vertex3f( vector3f( Radius, -Radius, Radius ),
							vector3f( .0f, .0f, -1.0f ) ) );
	mem_back.push_back(vertex3f( vector3f( Radius, Radius, Radius ),
							vector3f( .0f, .0f, -1.0f ) ) );
	mem_back.push_back(vertex3f( vector3f( -Radius, Radius, Radius ),
							vector3f( .0f, .0f, -1.0f ) ) );
	
	texId_back = GetTexture(Filename_back);
	
	memtex_back.push_back(vector2f(0 , 0));
	memtex_back.push_back(vector2f(1 , 0));
	memtex_back.push_back(vector2f(1 , 1));
	memtex_back.push_back(vector2f(0 , 1));

	//gorna sciana
	mem_top.push_back(vertex3f( vector3f( -Radius, Radius, -Radius ),
							vector3f( .0f, -1.0f, .0f ) ) );
	mem_top.push_back(vertex3f( vector3f( -Radius, Radius, Radius ),
							vector3f( .0f, -1.0f, .0f ) ) );
	mem_top.push_back(vertex3f( vector3f( Radius, Radius, Radius ),
							vector3f( .0f, -1.0f, .0f ) ) );
	mem_top.push_back(vertex3f( vector3f( Radius, Radius, -Radius ),
							vector3f( .0f, -1.0f, .0f ) ) );
	
	texId_top = GetTexture(Filename_top);
	
	memtex_top.push_back(vector2f(0 , 1));
	memtex_top.push_back(vector2f(0 , 0));
	memtex_top.push_back(vector2f(1 , 0));
	memtex_top.push_back(vector2f(1 , 1));
	
	//dolna sciana
	mem_bottom.push_back(vertex3f( vector3f( -Radius, -Radius, -Radius ),
							vector3f( .0f, 1.0f, .0f ) ) );
	mem_bottom.push_back(vertex3f( vector3f( -Radius, -Radius, Radius ),
							vector3f( .0f, 1.0f, .0f ) ) );
	mem_bottom.push_back(vertex3f( vector3f( Radius, -Radius, Radius ),
							vector3f( .0f, 1.0f, .0f ) ) );
	mem_bottom.push_back(vertex3f( vector3f( Radius, -Radius, -Radius ),
							vector3f( .0f, 1.0f, .0f ) ) );
	
	texId_bottom = GetTexture(Filename_bottom);
	
	memtex_bottom.push_back(vector2f(0 , 0));
	memtex_bottom.push_back(vector2f(0 , 1));
	memtex_bottom.push_back(vector2f(1 , 1));
	memtex_bottom.push_back(vector2f(1 , 0));
}

GLuint Skybox::GetTexture(std::string Filename)
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
		//glEnable( GL_TEXTURE_2D );
		//glBindTexture( GL_TEXTURE_2D, texId );
		
		return texId;
	}
	else
		return 1;
}

void Skybox::AttachTextureFilenames(	
		const std::string& PosFrontFilename,
        const std::string& NegBackFilename,
        const std::string& PosLeftFilename,
        const std::string& NegRightFilename,
        const std::string& PosTopFilename,
        const std::string& NegBottomFilename )
{
	Filename_front = PosFrontFilename;
	Filename_back = NegBackFilename;
	Filename_left = PosLeftFilename;
	Filename_right = NegRightFilename;
	Filename_top = PosTopFilename;
	Filename_bottom = NegBottomFilename;
}
