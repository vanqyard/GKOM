#include "SceneObjects.h"
const GLfloat Yellow[4] = {0.84, 0.64, 0.12, 1.0};
const GLfloat Green[4] = {0.2, 0.61, 0.18, 1.0};
const GLfloat Red[4] = {0.82, 0.11, 0.13, 1.0};
const GLfloat Lemon[4] = {0.72, 0.96, 0.03, 1.0};

Sfera::Sfera(GLfloat r, size_t scs, size_t sds) {
	radius = r;
	slices = scs;
	sides = sds;
}

void Sfera::Display() {
	glVertexPointer( 3, GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem[ 0 ] );
    glNormalPointer( GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem[ 0 ].normal );
    //glEnable( GL_TEXTURE_2D );
	//glBindTexture( GL_TEXTURE_2D, texId );
    //glTexCoordPointer( 2, GL_FLOAT, sizeof( std::vector<vector2f>::value_type ), &memtex[0] );
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, /*Yellow*/ Lemon);
	glDrawArrays( GL_QUADS, 0, mem.size() );	
}

vector3f Sfera::spherical_2_car( GLfloat radius, GLfloat theta, GLfloat phi )
{
    //warunki wstępne
    assert( radius > 0 );
    assert( theta >= 0 && theta <= T_PI + EPSILON );
    assert( phi >= 0 && phi <= PI + EPSILON );

    return vector3f(radius * sin( theta ) * sin( phi )
						, radius * cos( phi )
						, radius * sin( phi ) * cos( theta ) );
}

void Sfera::Build() {
    //warunki wstępne
    assert( radius > 0 );
	mem.reserve( slices * sides * 4 );

    for( size_t i = 0; i < slices; ++i )
    {
        GLfloat dslices = i / static_cast< GLfloat >( slices );
        GLfloat dslices_pp = ( i + 1 ) / static_cast< GLfloat >( slices );

        GLfloat phi = PI * dslices;
        GLfloat phi_pp = PI * dslices_pp;

        for( size_t j = 0; j < sides; ++j )
        {
            GLfloat dsides = j /
                static_cast< GLfloat >( sides );
            GLfloat dsides_pp = ( j + 1 ) /
                static_cast< GLfloat >( sides );

            GLfloat theta = T_PI * dsides;
            GLfloat theta_pp = T_PI * dsides_pp;

            mem.push_back(
                vertex3f( spherical_2_car( radius, theta, phi ),
                          spherical_2_car( radius
                            , theta, phi ).normalize() ) );

            mem.push_back(
                vertex3f( spherical_2_car( radius, theta, phi_pp ),
                          spherical_2_car( radius
                            , theta, phi_pp ).normalize() ) );

            mem.push_back(
                vertex3f( spherical_2_car( radius, theta_pp, phi_pp ),
                          spherical_2_car( radius
                            , theta_pp, phi_pp ).normalize() ) );

            mem.push_back(
                vertex3f( spherical_2_car( radius, theta_pp, phi ),
                          spherical_2_car( radius
                            , theta_pp, phi ).normalize() ) );
        }
    }
    
	memtex.push_back(vector2f(0 , 0));
	memtex.push_back(vector2f(1 , 1));
}

GLuint Sfera::GetTexture(std::string Filename)
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
