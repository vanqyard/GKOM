/*
 * Copyright (c) 2009, 2014 University of Michigan, Ann Arbor.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of Michigan, Ann Arbor. The name of the University 
 * may not be used to endorse or promote products derived from this 
 * software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Authors: Manoj Rajagopalan, Sugih Jamin
*/
#include <stdio.h>
#include <GL/gl.h>      // Header File For The OpenGL32 Library
#include <GL/glx.h>     // Header File For The X library for OpenGL
#include <GL/glu.h>     // Header File For The GLu32 Library
#include <GL/glut.h>
#include "SceneObjects.h"

/* ascii codes for various special keys */
#define ESCAPE 27

GLfloat z = -30.0f;       /* depth into the screen */
GLfloat xrot = 0.0f;           /* X Rotation */
GLfloat yrot = 0.0f;           /* Y Rotation */
GLfloat zrot = 0.0f;           /* Z Rotation */
GLdouble width = 1280.0; 
GLdouble height = 800.0;   /* window width and height */
int wd;                   /* GLUT window handle */
//Blok Obj(1.0f,1.0f,1.0f);
//SegmentWiezy Obj;
//Walec Obj(1.0f,1.0f);
//Ramie Obj(3);
//GoraZurawia Obj(4);
ZurawWiezowy Obj(5, 3);

#pragma comment(lib, "DevIL.lib")
#pragma comment(lib, "ILU.lib")
#pragma comment(lib, "ILUT.lib")

/* storage for one texture  */
GLuint texture[10];

/* Image type - contains height, width, and data */
typedef struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
} Image;

int ImageLoad(const char *filename, Image *image) {
    FILE *file;
    unsigned long size;                 // size of the image in bytes.
    unsigned long i;                    // standard counter.
    unsigned short int planes;          // number of planes in image (must be 1) 
    unsigned short int bpp;             // number of bits per pixel (must be 24)
    char temp;                          // temporary color storage for bgr-rgb conversion.

    // make sure the file is there.
    file = fopen(filename, "rb");
    
    // seek through the bmp header, up to the width/height:
    fseek(file, 18, SEEK_CUR);

    // read the width
    i = fread(&image->sizeX, 4, 1, file);
    
    // read the height 
    i = fread(&image->sizeY, 4, 1, file);
    
    // calculate the size (assuming 24 bits or 3 bytes per pixel).
    size = image->sizeX * image->sizeY * 3;

    // read the planes
    fread(&planes, 2, 1, file);
    
    // read the bpp
    i = fread(&bpp, 2, 1, file);
    
    // seek past the rest of the bitmap header.
    fseek(file, 24, SEEK_CUR);
    
    // read the data. 
    image->data = (char *) malloc(size);
    i = fread(image->data, size, 1, file);

    for (i=0;i<size;i+=3) { // reverse all of the colors. (bgr -> rgb)
        temp = image->data[i];
        image->data[i] = image->data[i+2];
        image->data[i+2] = temp;
    }
    
    fclose(file);
    // we're done.
    return 1;
}

// Load Bitmaps And Convert To Textures
void LoadGLTextures(const char* str, int num, GLuint* texture) {	
    // Load Texture
    Image *image1;
    
    // allocate space for texture
    image1 = (Image *) malloc(sizeof(Image));
    ImageLoad(str, image1);

    // Create Texture	
    glGenTextures(10, &texture[num]);
    glBindTexture(GL_TEXTURE_2D, texture[num]);   // 2d texture (x and y size)

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture

    // 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image, 
    // border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);

    free(image1);
}

/* Program initialization NOT OpenGL/GLUT dependent,
   as we haven't created a GLUT window yet */
void InitGL(void)
{   
    //LoadGLTextures("Data\nehe.bmp", 0, texture);				// Load The Texture(s) 
    //LoadGLTextures("Data\NeHe.bmp", 1, texture);				// Load The Texture(s) 
    //LoadGLTextures("Data\white.bmp", 2, texture);				// Load The Texture(s) 
    //LoadGLTextures("Data\crate.bmp", 3, texture);				// Load The Texture(s)     
	
	//glEnable( GL );
 /*
    glLightfv( id, GL_AMBIENT, ambient_col );
    glLightfv( id, GL_DIFFUSE, diffuse_col );
    glLightfv( id, GL_SPECULAR, specular_col );
    glLightfv( id, GL_POSITION, position );
*/	
    glEnable(GL_TEXTURE_2D);			    // Enable Texture Mapping
    //glClearColor(0.0f, 0.0f, 1.0f, 0.0f);	// Clear The Background Color To Blue 
    glClearDepth(1.0);				        // Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LESS);			        // The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST);			    // Enables Depth Testing
    glShadeModel(GL_SMOOTH);			    // Enables Smooth Color Shading
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();				        // Reset The Projection Matrix
    
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window
    //gluOrtho2D(1515.0, 1565.0, -3.0, 15.0);
    
    glMatrixMode(GL_MODELVIEW);
}

/* Callback functions for GLUT */
/* Draw the window - this is where all the GL actions are */
void DisplayFunction(void)
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	// Clear The Screen And The Depth Buffer

    glPushMatrix();
    
    //glLoadIdentity();
    
	glTranslatef(0.0f, 0.0f, z);
    
    glRotatef( xrot, 1.0f, 0.0f, 0.0f); // Rotate On The X Axis 
    glRotatef( yrot, 0.0f, 1.0f, 0.0f); // Rotate On The Y Axis 
    glRotatef( zrot, 0.0f, 0.0f, 1.0f); // Rotate On The Z Axis
       
        glBindTexture(GL_TEXTURE_2D, texture[0]);   // choose the texture to use.

        Obj.Display();
    
    glPopMatrix();
    
    // swap the buffers to display, since double buffering is used.
    glutSwapBuffers();
}

/* Called when window is resized,
   also when window is first created,
   before the first call to display(). */
void Reshape(int w, int h) {
	if (height==0) {									// Prevent A Divide By Zero By
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();
}

void keyFunc(unsigned char key, int x, int y) {
    
	switch(key) {
    case 'q':
    case ESCAPE:
        glutDestroyWindow(wd); 
        exit(0);
        break;
		
    case 'W':    
    case 'w':    
        Obj.WozekForward();
        break;
    case 'S':    
    case 's':    
        Obj.WozekBackward();
        break;
    case 'D':    
    case 'd':    
        Obj.RamieRight();
        break;
    case 'A':    
    case 'a':    
        Obj.RamieLeft();
        break;
    case 'O':    
    case 'o':    
        Obj.LinaUp();
        break;
    case 'L':    
    case 'l':    
        Obj.LinaDown();
        break;        
    
	}
}

/* The function called whenever a normal key is pressed. */
void specialKeyPressed(int key, int x, int y) {
	
    switch (key) {  
    case GLUT_KEY_PAGE_UP: // tilt up
        //std::cout << "pg up " << z << std::endl;
        z+=0.5f;
        break;
    
    case GLUT_KEY_PAGE_DOWN: // tilt down
        //std::cout << "pg down" << z << std::endl;
        z-=0.5f;
        break;

    case GLUT_KEY_UP: // walk forward (bob head)
        //std::cout << "up " << xrot << std::endl;
        xrot+=0.5f;
        break;
        
    case GLUT_KEY_DOWN: // walk back (bob head)
        //std::cout << "down " << xrot << std::endl;
        xrot-=0.5f;
        break;

    case GLUT_KEY_LEFT: // look left
        //std::cout << "left " << yrot << std::endl;
        yrot+=0.5f;
        break;
    
    case GLUT_KEY_RIGHT: // look right
        //std::cout << "right " << yrot << std::endl;
        yrot-=0.5f;
        break;

    default:
        printf ("Special key %d pressed. No action there yet.\n", key);
        break;
    }
}

int
main(int argc, char *argv[]) {
    /* perform initialization NOT OpenGL/GLUT dependent,
     as we haven't created a GLUT window yet */
    InitGL();

    /* initialize GLUT, let it extract command-line 
     GLUT options that you may provide 
     - NOTE THE '&' BEFORE argc */
    glutInit(&argc, argv);

    /* specify the display to be single 
     buffered and color as RGBA values */
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);

    /* set the initial window size */
    glutInitWindowSize((int) width, (int) height);

    /* create the window and store the handle to it */
    wd = glutCreateWindow("Experiment with line drawing" /* title */ );

    /* --- register callbacks with GLUT --- */

    /* Even if there are no events, redraw our gl scene. */
    glutIdleFunc(&DisplayFunction);
    
    /* register function to handle window resizes */
    glutReshapeFunc(Reshape);

    /* Register the function called when the keyboard is pressed. */
    //glutKeyboardFunc(&keyPressed);
    glutKeyboardFunc(&keyFunc);
    
    /* Register the function called when special keys (arrows, page down, etc) are pressed. */
    glutSpecialFunc(&specialKeyPressed);
    
    /* register function that draws in the window */
    glutDisplayFunc(DisplayFunction);

    /* init GL */
    glClearColor(.0, .0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    //glLineWidth(3.0);





    /* start the GLUT main loop */
    glutMainLoop();

    return 0;
}
