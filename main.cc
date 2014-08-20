#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
//#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "SceneObjects.h"

const int screenX = 1200;
const int screenY = 600;
GLfloat fraction = 2.0f;
/*
GLfloat ambient[] =  { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat diffuse[] =  { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat specular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat position[] = { 5.0f, 5.0f, 5.0f, 1.0f };
*/ 
GLfloat ambient[] =  { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat diffuse[] =  { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat position[] = { 0.0f, 0.0f, 0.0f, 1.0f };
//GLfloat position[] = { 0.0f, -10.0f, -10.0f, 1.0f };
float angle_rot = .0f;
// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f,ly=0.0f;
// XZ position of the camera
float x=0.0f,z=5.0f,y=1.0f;
// obiekty w scenie
std::vector<UniformObject*> SceneObjects;

/**
 * @struct position2d
 * @brief pozycja dwuwymiarowa
 */
struct position2d
{
    /**
     * @brief domyslny konstr.
     * inicjalizuje wsp. wartosciami zerowymi
     */
    position2d( void ) : x( 0 ), y( 0 ) { }

    /// wspolrzedna x
    int x;

    /// wspolrzedna y
    int y;

} mousePosition;

void initOpenGL( int width, int height )
{
    glMatrixMode( GL_PROJECTION );
    gluPerspective( 45.0f, width / ( GLfloat ) height, 0.1f, 100.0f );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //włączenie testowania bufora głębokości
    glEnable( GL_DEPTH_TEST );

    //sposób rasteryzacji wielokątów
    glPolygonMode( GL_FRONT, GL_FILL );

    //włączenie liczenia oświetlenia
	glEnable( GL_LIGHTING );
}

void initSDL( int scrWidth, int scrHeight )
{
    // zaincjalizowanie części biblioteki odpowiadającej za wyświetlanie
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        throw std::runtime_error( "Can't initialize SDL\n" );
    }

    // ustawienie ilości bitów dla każdego z kolorów
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );

    // ustawienie ilości bitów dla specjalnych buforów
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 24 );
    SDL_GL_SetAttribute( SDL_GL_STENCIL_SIZE, 8 );

    // włączenie podwójnego buforowania
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, true );
    SDL_GL_SetAttribute( SDL_GL_SWAP_CONTROL, 1 );

    // stworzenie okna aplikacji z kontekstem OpenGL'a
    if ( SDL_SetVideoMode( scrWidth, scrHeight, 24, SDL_OPENGL ) == 0 )
    {
        throw std::runtime_error(
            std::string( "Unable to set video mode: " ).append(
            	std::string( SDL_GetError() ) ) );
    }
}

bool processInput( void )
{
    SDL_Event event;													// zmienna pomocnicza
	
    if ( SDL_PollEvent( &event ) ) {									// czy są jakieś czekające na przetworzenie zdarzenia ?
        switch( event.type ) {											// sprawdzenie typu zdarzenia		
            case SDL_QUIT: return false;								// wyjście z aplikacji
            case SDL_KEYDOWN:											// użytkownik nacisnął któryś z klawiszy na klawiaturze
            {
                switch( event.key.keysym.sym ) {
					case( SDLK_ESCAPE ): 
						return false;
					case( SDLK_a ): 
						std::cout << "left" << std::endl;						
						angle -= 0.1f;
						lx = sin(angle);
						lz = -cos(angle);
						break;
					case( SDLK_d ): 
						std::cout << "right" << std::endl;	
						angle += 0.1f;
						lx = sin(angle);
						lz = -cos(angle);
						break;
					case( SDLK_w ): 
						std::cout << "up" << std::endl;
						x += lx * fraction;
						z += lz * fraction;
						break;
					case( SDLK_s ): 
						std::cout << "down" << std::endl;
						x -= lx * fraction;
						z -= lz * fraction;
						break;
					default: break;
				}
			}            
            case SDL_MOUSEMOTION:
            {
				int Origin_x = mousePosition.x;
				int Origin_y = mousePosition.y;
				
                SDL_GetMouseState( &mousePosition.x, &mousePosition.y );
                
                int delta_x = Origin_x - mousePosition.x;
                int delta_y = Origin_y - mousePosition.y;
                
                //std::cout << delta_x << " " 
				//			<< delta_y << std::endl;
                /*
                poprawna implementacja:
                if(delta_x > 0 && delta_y > 0)
                if(delta_x < 0 && delta_y < 0)
                if(delta_x > 0 && delta_y < 0)
                if(delta_x < 0 && delta_y > 0)
                
                */
                if(delta_x > 0) {
					angle -= 0.01f*abs(delta_x);
					lx = sin(angle);
					lz = -cos(angle);
					break;
				}
                
				if(delta_x < 0) {
					angle += 0.01f*abs(delta_x);
					lx = sin(angle);
					lz = -cos(angle);
					break;
				}
				/*
				if(delta_y > 0) {
					angle -= 0.001f*abs(delta_y);
					lx = sin(angle);
					ly = -cos(angle);
					break;
				}
				
				if(delta_y < 0) {
					angle += 0.001f*abs(delta_y);
					lx = sin(angle);
					ly = -cos(angle);
					break;
				}	
				*/      
                break;
                
                //deltaAngle = (x - xOrigin) * 0.1f;					// update deltaAngle x
                
                // update camera's direction
				//lx = sin(angle + deltaAngle);
				//lz = -cos(angle + deltaAngle);
				
				//std::cout << deltaAngle << " " << lx << " " << lz << " " << std::endl;
				/*
                switch() {
					
				}*/
             }   
        }
    }
    return true;
}

int 
main( int argc, char * argv[] )
{ 
	initSDL( screenX, screenY );
    initOpenGL( screenX, screenY );
    
	glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_NORMAL_ARRAY );
    glEnableClientState( GL_COLOR_ARRAY );
    glEnableClientState( GL_TEXTURE_COORD_ARRAY );

    Skybox skybox(40.0f);
    //Rifle r("./data/gun-fps.jpg");
    
    //Cube c(2.0f);
    //SegmentWiezy c;
    //Blok e(5.0f, 1.0f, 3.0f);
    Kabina kabina;
    Wieza wieza(3);
    PrzednieRamie pramie(5);
    TylneRamie tramie;
    Blok lacznik1(0.5, 4.0, 3.0);
    Blok lacznik2(5.0, 1.0, 3.0);
    //Sfera e(2.0f,15,15);
    //PodstawaDzwigu c;
    //Walec w(10.0f, 10.0f, 100, 0);
    //TylneRamie w;
	
    skybox.AttachTextureFilenames(
		"./data/skybox1/front.png",
		"./data/skybox1/back.png",
		"./data/skybox1/right.png",
		"./data/skybox1/left.png",
		"./data/skybox1/top.png",		
		"./data/skybox1/bottom.png"		
	);
	kabina.GetTexture("./data/kabina.png");
	
    skybox.Build();
	pramie.Build();
	tramie.Build();
	wieza.Build();
	kabina.Build();
	lacznik1.Build();
	lacznik2.Build();
	
	/*
	for(UniformObject* uo : SceneObjects) {
		uo->Build();
	}
	*/
	
	try { 
		while(processInput()) {
		
			glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
			glMatrixMode( GL_MODELVIEW );
			glLoadIdentity();	
		
				glPushMatrix();
		
				gluLookAt(		x, 	  y, 	z,
								x+lx, y+ly, z+lz,
								0.0f, 1.0f, 0.0f	);
			
				glEnable( GL_LIGHT0 );

				glLightfv( GL_LIGHT0, GL_AMBIENT, ambient );
				glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse );
				glLightfv( GL_LIGHT0, GL_SPECULAR, specular );
				glLightfv( GL_LIGHT0, GL_POSITION, position );

					glPushMatrix();
					
						glPushMatrix();
						glTranslatef(8.5f, 5.0f, 0.0);
						pramie.Display();
						glPopMatrix();
						
						glPushMatrix();
						glTranslatef(-17.0f, 5.0f, 0.0);
						tramie.Display();			
						glPopMatrix();
			
						glPushMatrix();
						glTranslatef(5.0f, -12.0f, 0.0);
						wieza.Display();
						glPopMatrix();			

						glPushMatrix();
						glTranslatef(5.0f, 4.0f, -2.0);
						kabina.Display();
						glPopMatrix();	
								
						glPushMatrix();
						glTranslatef(5.0f, 4.0f, 0.0);
						lacznik1.Display();
						glPopMatrix();			

						glPushMatrix();
						glTranslatef(5.0f, 6.5f, 0.0);
						lacznik2.Display();
						glPopMatrix();			
					
			
			
			
			
			
			
					skybox.Display();
					
					glPopMatrix();
			
			glPopMatrix();

			SDL_GL_SwapBuffers();
		}
	}
    catch( const std::exception& e )
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
	
	SDL_Quit();
    return 0;
}
