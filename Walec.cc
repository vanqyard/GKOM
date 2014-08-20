#include "SceneObjects.h"

Walec::Walec(GLfloat h, GLfloat r, GLuint l, bool c)
{
	Height = h;
	Radius = r;
	Level = l + 1;	// poziomy: 1, 2, 3,...
	isComplete = c;
}

void Walec::Display() {
	glVertexPointer( 3, GL_FLOAT, sizeof( std::vector<vector2f>::value_type ), &mem[ 0 ] );
    glNormalPointer( GL_FLOAT, sizeof( std::vector<vector2f>::value_type ), &mem[ 0 ].normal );
    //glBindTexture(GL_TEXTURE_2D, 0);
    //glTexCoordPointer( 2, GL_FLOAT, sizeof( std::vector<vector2f>::value_type ), &memtex[0] );	
	//glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, Yellow);
	glDrawArrays( GL_QUADS, 0, mem.size() );
}

void Walec::Build() {
	const GLfloat halfH = Height / 2;
	const GLfloat sinval = sin(M_PI_4 / Level);
	const GLfloat cosval = cos(M_PI_4 / Level);
	const GLfloat d = Radius * sinval;
	const GLfloat x = Radius * cosval;
	const GLuint wallCount = 4 * Level;
	const GLfloat alfa = 360.0 / wallCount;
	const GLfloat t = 1.0 / static_cast<GLfloat>(wallCount);

	// material
	//glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, Color);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);

	//if(isTextured) glBindTexture(GL_TEXTURE_2D, TextureId);

	glPushMatrix();

	// petla tworzenia scianek
	for(int i = 0; i < wallCount; i++)
	{

		/// geometria
		//glBegin(GL_QUADS);

		///glNormal3f(-sinval, 0.0, cosval);

		memtex.push_back(vector2f(static_cast<GLfloat>(i) * t, 0.0f));	///glTexCoord2f(static_cast<GLfloat>(i) * t, 0.0);
		mem.push_back(vertex3f( vector3f( -d, -halfH, x ),				///glNormal3f(-sinval, 0.0, cosval);
								vector3f( -sinval, 0.0, cosval ) ) );	///glVertex3f(-d, -halfH, x);
		memtex.push_back(vector2f(static_cast<GLfloat>(i) * t, 1.0f));	///glTexCoord2f(static_cast<GLfloat>(i) * t, 1.0);
		mem.push_back(vertex3f( vector3f( -d, halfH, x ),				///glNormal3f(-sinval, 0.0, cosval);
								vector3f( -sinval, 0.0, cosval ) ) );	///glVertex3f(-d, halfH, x);

		///glNormal3f(sinval, 0.0, cosval);

		memtex.push_back(vector2f(static_cast<GLfloat>(i + 1) * t, 1.0f));	///glTexCoord2f(static_cast<GLfloat>(i + 1) * t, 1.0);
		mem.push_back(vertex3f( vector3f( d, halfH, x ),				///glNormal3f(sinval, 0.0, cosval);
								vector3f( sinval, 0.0, cosval ) ) );	///glVertex3f(d, halfH, x);
		memtex.push_back(vector2f(static_cast<GLfloat>(i + 1) * t, 0.0f));	///glTexCoord2f(static_cast<GLfloat>(i + 1) * t, 0.0);
		mem.push_back(vertex3f( vector3f( d, -halfH, x ),				///glNormal3f(-sinval, 0.0, cosval);
								vector3f( sinval, 0.0, cosval ) ) );	///glVertex3f(d, -halfH, x);

		// koniec geometrii
		//glEnd();
/*
		if(isComplete)
		{
			/// dorob rowniez podtawy
			glBegin(GL_TRIANGLES);

			glTexCoord2f(0.0, 0.0);

			/// gorna
			glNormal3f(0.0, 1.0, 0.0);
			glVertex3f(-d, halfH, x);
			glVertex3f(0.0, halfH, 0.0);
			glVertex3f(d, halfH, x);

			/// dolna
			glNormal3f(0.0, -1.0, 0.0);
			glVertex3f(-d, -halfH, x);
			glVertex3f(0.0, -halfH, 0.0);
			glVertex3f(d, -halfH, x);

			glEnd();
		}
*/
		//glRotatef(alfa, 0.0, 1.0, 0.0);

	}// for

	glPopMatrix();
}
