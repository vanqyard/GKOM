#include "SceneObjects.h"
const GLfloat Yellow[4] = {0.84, 0.64, 0.12, 1.0};

Cube::Cube(GLfloat width) {
	this->width = width;
}

Cube::~Cube() {
	mem.clear();
	mem.shrink_to_fit();
}

void Cube::Display()
{
	glVertexPointer( 3, GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem[ 0 ] );
    glNormalPointer( GL_FLOAT, sizeof( std::vector<vertex3f>::value_type ), &mem[ 0 ].normal );
    glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, texId );
    glTexCoordPointer( 2, GL_FLOAT, sizeof( std::vector<vector2f>::value_type ), &memtex[0] );
	//glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, Yellow);
	glDrawArrays( GL_QUADS, 0, mem.size() );
}

void Cube::Build() 
{
	/* rezerwacja pamięci */
	mem.reserve( 6 * 4 * sizeof( std::vector<vertex3f>::value_type ) );

	//zapamiętanie wartości pomocniczych
	GLfloat min = -width * 0.5f;										// 0.5f jako polowa dlugosci boku width
	GLfloat max = -min;													// liczba przeciwna do min jako lustrzane odbicie punktu min wzgledem osi				
    
	//przednia sciana
	mem.push_back(vertex3f( vector3f( min, max, max ),
							vector3f( .0f, .0f, 1.0f ) ) );
	mem.push_back(vertex3f( vector3f( min, min, max ),
							vector3f( .0f, .0f, 1.0f ) ) );
	mem.push_back(vertex3f( vector3f( max, min, max ),
							vector3f( .0f, .0f, 1.0f ) ) );
	mem.push_back(vertex3f( vector3f( max, max, max ),
							vector3f( .0f, .0f, 1.0f ) ) );

	//tylnia sciana
	mem.push_back(vertex3f( vector3f( max, max, min ),
							vector3f( .0f, .0f, -1.0f ) ) );
	mem.push_back(vertex3f( vector3f( max, min, min ),
							vector3f( .0f, .0f, -1.0f ) ) );
	mem.push_back(vertex3f( vector3f( min, min, min ),
							vector3f( .0f, .0f, -1.0f ) ) );
	mem.push_back(vertex3f( vector3f( min, max, min ),
							vector3f( .0f, .0f, -1.0f ) ) );

	//prawa sciana	
	mem.push_back(vertex3f( vector3f( max, max, max ),
							vector3f( 1.0f, .0f, .0f ) ) );
	mem.push_back(vertex3f( vector3f( max, min, max ),
							vector3f( 1.0f, .0f, .0f ) ) );
	mem.push_back(vertex3f( vector3f( max, min, min ),
							vector3f( 1.0f, .0f, .0f ) ) );
	mem.push_back(vertex3f( vector3f( max, max, min ),
							vector3f( 1.0f, .0f, .0f ) ) );

	//lewa sciana
	mem.push_back(vertex3f( vector3f( min, max, min ),
							vector3f( -1.0f, .0f, .0f ) ) );
	mem.push_back(vertex3f( vector3f( min, min, min ),
							vector3f( -1.0f, .0f, .0f ) ) );
	mem.push_back(vertex3f( vector3f( min, min, max ),
							vector3f( -1.0f, .0f, .0f ) ) );
	mem.push_back(vertex3f( vector3f( min, max, max ),
							vector3f( -1.0f, .0f, .0f ) ) );

	//gorna sciana	
	mem.push_back(vertex3f( vector3f( min, max, min ),
							vector3f( .0f, 1.0f, .0f ) ) );
	mem.push_back(vertex3f( vector3f( min, max, max ),
							vector3f( .0f, 1.0f, .0f ) ) );
	mem.push_back(vertex3f( vector3f( max, max, max ),
							vector3f( .0f, 1.0f, .0f ) ) );
	mem.push_back(vertex3f( vector3f( max, max, min ),
							vector3f( .0f, 1.0f, .0f ) ) );

	//dolna sciana
	mem.push_back(vertex3f( vector3f( min, min, max ),
							vector3f( .0f, -1.0f, .0f ) ) );
	mem.push_back(vertex3f( vector3f( min, min, min ),
							vector3f( .0f, -1.0f, .0f ) ) );
	mem.push_back(vertex3f( vector3f( max, min, min ),
							vector3f( .0f, -1.0f, .0f ) ) );
	mem.push_back(vertex3f( vector3f( max, min, max ),
							vector3f( .0f, -1.0f, .0f ) ) );

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

	memtex.push_back(vector2f(0 , 0));
	memtex.push_back(vector2f(0 , 1));
	memtex.push_back(vector2f(1 , 0));
	memtex.push_back(vector2f(1 , 1));

	memtex.push_back(vector2f(0 , 0));
	memtex.push_back(vector2f(0 , 1));
	memtex.push_back(vector2f(1 , 0));
	memtex.push_back(vector2f(1 , 1));
}

GLuint Cube::GetTexture(std::string Filename)
{
	glGenTextures(1, &texId);
	glBindTexture(GL_TEXTURE_2D, texId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);		//glGenerateMipmap(GL_TEXTURE_2D);
	// Black/white checkerboard
	float pixels[] = {
		0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,   0.0f, 0.0f, 0.0f
	};
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);
	int width=512, height=512;	
	unsigned char* image =
				SOIL_load_image("img.png", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
				GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	float vertices[] = {
	//  Position      Color             Texcoords
    -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Top-left
     0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // Bottom-right
    -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f  // Bottom-left
    
    
    
    
    
};


}
