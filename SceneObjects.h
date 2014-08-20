#include <vector>
#include <string>
#include <cmath>
#include <functional>
#include <algorithm>
#include <assert.h>
#include <GL/gl.h>
#include <SOIL/SOIL.h>
#include <SDL/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "OpenGl.h"

////////////////////////////////////////////////////////////////////////
// UniformObject - klasa bazowa dla wszystkic widocznych
// obiektów w scenie
////////////////////////////////////////////////////////////////////////
class UniformObject 
{

protected:
	std::vector<vertex3f> mem;
	std::vector<vector2f> memtex;
	int selfId;
	GLuint texId;

public:
	virtual void Display()=0;	// pure
	virtual void Build()=0;		// pure
	
};

////////////////////////////////////////////////////////////////////////
// Prostopadloscian, o podstawie kwadratu, bez "dachu" i "podlogi"
////////////////////////////////////////////////////////////////////////
class Wspornik : public UniformObject 
{
	GLfloat Height;
	GLfloat Width;
	//GLfloat Length;
	
public:

	// Konstruuj z wysokosci i dlugosci krawedzi podstawy
	Wspornik(GLfloat h, GLfloat a);

	// Renderuje obiekt - pokazuje
	void Display();
	void Build();
	
	// Pobierz wlasciwosci
	GLfloat GetHeight() const { return Height; }
	GLfloat GetWidth() const { return Width; }
	
	// Wczytanie tekstury
	GLuint GetTexture(std::string Filename);
};

////////////////////////////////////////////////////////////////////////
// Skybox
////////////////////////////////////////////////////////////////////////
class Skybox : public UniformObject 
{
	class Wall 
	{
		std::string Filename;
		std::vector<vertex3f> mem;
		std::vector<vector2f> memtex;
		GLuint texId;
	};

	GLfloat Radius;
	std::vector<Wall> Walls;
	
	std::vector<vertex3f> mem_front;
	std::vector<vector2f> memtex_front;
	GLuint texId_front;
	
	std::vector<vertex3f> mem_left;
	std::vector<vector2f> memtex_left;
	GLuint texId_left;
	
	std::vector<vertex3f> mem_back;
	std::vector<vector2f> memtex_back;
	GLuint texId_back;
	
	std::vector<vertex3f> mem_top;
	std::vector<vector2f> memtex_top;
	GLuint texId_top;
	
	std::vector<vertex3f> mem_bottom;
	std::vector<vector2f> memtex_bottom;
	GLuint texId_bottom;
	
	std::vector<vertex3f> mem_right;
	std::vector<vector2f> memtex_right;
	GLuint texId_right;

	std::string Filename_front;
	std::string Filename_back;
	std::string Filename_left;
	std::string Filename_right;
	std::string Filename_top;
	std::string Filename_bottom;

public:

	// Konstruuj z wysokosci i dlugosci krawedzi podstawy
	Skybox(GLfloat r);

	// Renderuje obiekt - pokazuje
	void Display();
	void Build();
	
	// Wczytanie tekstury
	GLuint GetTexture(std::string F);
	void AttachTextureFilenames(	
		const std::string& PosFrontFilename,
        const std::string& NegBackFilename,
        const std::string& PosLeftFilename,
        const std::string& NegRightFilename,
        const std::string& PosTopFilename,
        const std::string& NegBottomFilename );

};

////////////////////////////////////////////////////////////////////////
// Budka operatora
////////////////////////////////////////////////////////////////////////
class Kabina : public UniformObject 
{
public:

	Kabina();

	// pokaz obiekt
	void Display();
	void Build();

	// wysokosc
	GLfloat GetHeight() { return 2.2; }
	
	// Wczytanie tekstury
	GLuint GetTexture(std::string Filename);
};

////////////////////////////////////////////////////////////////////////
// Szescian
////////////////////////////////////////////////////////////////////////
class Cube : public UniformObject 
{
	GLfloat width;
	
public:

	// Konstruuj z wysokosci i dlugosci krawedzi podstawy
	Cube(GLfloat a);
	~Cube();
	
	// Renderuje obiekt - pokazuje
	void Display();
	void Build();
	
	// Pobierz wlasciwosci
	GLfloat GetHeight() const { return width; }
	GLfloat GetWidth() const { return width; }
	
	// Wczytanie tekstury
	GLuint GetTexture(std::string Filename);
};

////////////////////////////////////////////////////////////////////////
// Segment wiezy
////////////////////////////////////////////////////////////////////////
class SegmentWiezy : public UniformObject 
{
	Wspornik ElemPionowy;
	Wspornik ElemPoziomy;
	Wspornik ElemUkosny;

	void DisplayPoziome();	// pokazuje poziome wsporniki jednego poziomu
	void DisplayPionowe();	// pokaz pionowe
	void DisplayUkosne();	// pokaz ukosne jednej sciany

public:

	SegmentWiezy();

	// pokaz obiekt
	void Display();
	void Build();
	
	// wysokosc elementu
	GLfloat GetHeight() const { return ElemPionowy.GetHeight(); }
	
	// Wczytanie tekstury
	GLuint GetTexture(std::string Filename);
};

////////////////////////////////////////////////////////////////////////
// Prostopadloscian, o zadanej wysokosci, szerokosci i dlugosci
////////////////////////////////////////////////////////////////////////
class Blok : public UniformObject 
{
	GLfloat width;
	
	GLfloat Height;
	GLfloat Width;
	GLfloat Length;

public:

	Blok(GLfloat h, GLfloat w, GLfloat l);

	// Renderuje obiekt - pokazuje
	void Display();
	void Build();
	
	// Pobierz wlasciwosci
	GLfloat GetHeight() const { return Height; }
	GLfloat GetLength() const { return Length; }
	GLfloat GetWidth() const { return Width; }
	
	GLuint GetTexture(std::string Filename);
};

class Walec : public UniformObject 
{
	GLfloat Height;
	GLfloat Radius;
	GLuint Level;
	bool isComplete;	// czy ma podstawy

public:

	Walec(GLfloat h, GLfloat r, GLuint l = 0, bool c = false);

	// renderuje obiekt - pokazuje
	void Display();
	void Build();
	
	// pobierz wysokosc
	GLfloat GetHeight() const { return Height; }

	// zmien wysokosc
	void SetHeight(GLfloat h) { Height = h; }

	// zmien par. dotyczacy generowania podstaw
	void SetComplete(bool c) { isComplete = c; }
};

////////////////////////////////////////////////////////////////////////
// Wieza
//				 ___
//				|\ /|
//				| X	|
//				|/_\|
//				|\ /|
//				| X	|
//				|/_\|
//				|\ /|
//				| X	|
//				|/_\|
////////////////////////////////////////////////////////////////////////
class Wieza : public UniformObject 
{
	GLuint NumberOfElements;
	std::vector<SegmentWiezy> Elements;

public:

	Wieza(GLuint noe);

	// pokaz obiekt
	void Display();
	void Build();
	
	// wysokosc elementu
	GLfloat GetHeight() const { return NumberOfElements*Elements[0].GetHeight(); }
	
	// Wczytanie tekstury
	GLuint GetTexture(std::string Filename);
};

////////////////////////////////////////////////////////////////////////
// Ramie		
//
//	  ___	__--|------______
//   |___|--	|			 ------______
//	|_____|------------------------------------|
//	 |___|	  |	  |
//			  |	  |
////////////////////////////////////////////////////////////////////////
class PrzednieRamie : public UniformObject 
{
	GLuint NumberOfElements;
	std::vector<SegmentWiezy> Elements;
	//Blok Ciezar;
	//Walec Lozysko;
	
public:
	PrzednieRamie(GLuint noe);

	// pokaz obiekt
	void Display();
	void Build();
	
	// wysokosc elementu
	GLfloat GetHeight() const { return (Elements[0].GetHeight()); }
	
	// Wczytanie tekstury
	GLuint GetTexture(std::string Filename);
};

class TylneRamie : public UniformObject
{
	Blok GlownyWspornik;
	Blok UkosnyWspornik;
	Blok KoncowyWspornik;
	Blok Poprzeczny;
	Blok Ciezar;
	Blok Tyl;
	Blok Tablica;

public:

	TylneRamie();

	// pokaz obiekt
	void Display();
	void Build();
	
	// wysokosc elementu
	GLfloat GetHeight() const { return GlownyWspornik.GetHeight(); }	/// !!!!!!!!!!!!!!!!!!
	
	// Wczytanie tekstury
	GLuint GetTexture(std::string Filename);
};

class Sfera : public UniformObject 
{
	GLfloat radius;
	size_t slices;
	size_t sides;

	vector3f spherical_2_car( GLfloat radius, GLfloat theta, GLfloat phi );
public:
		
	Sfera(GLfloat r, size_t scs, size_t sds);
	void Build();
	void Display();

	GLuint GetTexture(std::string Filename);
};

class PodstawaDzwigu : public UniformObject 
{
	SegmentWiezy Segment;
	Wspornik Nozka;
	Blok Podloga;
	Blok Ciezar;
	Wspornik Podpora;

	void DisplayNozki();
	void DisplayCiezary();
	void DisplayPodpory();
	
public:

	PodstawaDzwigu();

	// renderuje obiekt - pokazuje
	void Display();
	void Build();
	
	// pobierz wlasciwosci
	GLfloat GetHeight() const { return 8.5; }	
	
	GLuint GetTexture(std::string Filename);
};

class WozekDzwigu : public UniformObject 
{
	Walec Kolko1;
	Walec Kolko2;
	Walec Kolko3;
	Walec Kolko4;
	Blok Wozek;
	
	
	
};

class LinaZMagnesem : public UniformObject 
{
	Walec Magnes;
	Wspornik Lina;
	
	
};

class Drabina : public UniformObject 
{
	
};

////////////////////////////////////////////////////////////////////////
//
//				  ?????? 
//				??????????
//				??    ????
//					 ?????
//				   ?????
//                 ???
//
//				   ???
//
////////////////////////////////////////////////////////////////////////
class Garbage : public UniformObject 
{
	
};

////////////////////////////////////////////////////////////////////////
//  Tasmociag													
//														  ______	
// 														 |		|
//				_________________________________________|		|
//				O___O___O___O___O___O___O___O___O___O___O|		|
//				|		|		|		|		|		||		|
//
////////////////////////////////////////////////////////////////////////
class ConveyorBelt : public UniformObject 
{
	//std::vector<Plane> Tasma;
	std::vector<Walec> WalkiTasmociagu;
	
public:

	ConveyorBelt();
	
	// renderuje obiekt
	void Display();
	void Build();	
	
	// pobierz wlasciwosci
	GLfloat GetHeight() const { return 8.5; }	
	
	GLuint GetTexture(std::string Filename);
};

class ZurawWiezowy {
	PrzednieRamie pramie;
	TylneRamie tramie;
	Wieza wieza;
	Kabina kabina;
	PodstawaDzwigu podstawa;
	GLfloat height;
	GLfloat length;
public:
	ZurawWiezowy(GLuint height, GLuint length) : pramie(length), wieza(height) {}
	
	void Display();
	void Build();
	
	// pobierz wlasciwosci
	GLfloat GetHeight() const { return 8.5; }	
	
	GLuint GetTexture(std::string Filename);
};

class Rifle {
	GLuint texture;
	
public:

	Rifle(std::string str);
	void drawImage();
	
};
