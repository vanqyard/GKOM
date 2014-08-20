#include "SceneObjects.h"

Rifle::Rifle(std::string str) {
	SDL_Surface *image;
	SDL_RWops *rwop;
	rwop=SDL_RWFromFile(str.c_str(), "rb");
	image=IMG_LoadJPG_RW(rwop);
	
	// Have OpenGL generate a texture object handle for us
	glGenTextures( 1, &texture );	
	// Bind the texture object
	glBindTexture( GL_TEXTURE_2D, texture );

}

//void Rifle::Build() {}

void Rifle::drawImage() {
	// Clear the screen before drawing
	glClear( GL_COLOR_BUFFER_BIT );

	// Bind the texture to which subsequent calls refer to
	glBindTexture( GL_TEXTURE_2D, texture );

	glBegin( GL_QUADS );
	// Top-left vertex (corner)
	glTexCoord2i( 0, 0 );
	glVertex3f( 100, 100, 0 );

	// Bottom-left vertex (corner)
	glTexCoord2i( 1, 0 );
	glVertex3f( 228, 100, 0 );

	// Bottom-right vertex (corner)
	glTexCoord2i( 1, 1 );
	glVertex3f( 228, 228, 0 );

	// Top-right vertex (corner)
	glTexCoord2i( 0, 1 );
	glVertex3f( 100, 228, 0 );
	glEnd();
	
	glLoadIdentity();
	SDL_GL_SwapBuffers();
}
