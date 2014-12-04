#include <iostream>
#include <GL/glut.h>    // Header File For The GLUT Library 
#include <cmath>

class UniformObject {
    int objId;
    static int objCounter;
public:
    UniformObject();
    ///virtual void Display() = 0;
};

////////////////////////////////////////////////////////////////////////
// prostopadloscian, o zadanej wysokosci, szerokosci i dlugosci
////////////////////////////////////////////////////////////////////////
class Blok : public UniformObject {
	GLfloat Height;
	GLfloat Width;
	GLfloat Length;
public:
	Blok(GLfloat h, GLfloat w, GLfloat l);
	void Display() ;
    
	GLfloat GetHeight()  { return Height; }
	GLfloat GetLength()  { return Length; }
	GLfloat GetWidth()  { return Width; }
};

////////////////////////////////////////////////////////////////////////
// wspornik - prostopadloscian bez podstaw
////////////////////////////////////////////////////////////////////////
class Wspornik : public UniformObject {
    GLfloat Width;
    GLfloat Height;    
public:
    Wspornik(GLfloat h, GLfloat a);
    void Display() ;
    
    GLfloat GetHeight()  { return Height; }
    GLfloat GetWidth()  { return Width; }
};

////////////////////////////////////////////////////////////////////////
// walec, o zadanej wysokosci, promieniu, ilosci szczegolow + czy ma
// podstawy
////////////////////////////////////////////////////////////////////////
class Walec : public UniformObject {
	GLfloat Height;
	GLfloat Radius;
	bool complete;
public:
	Walec(GLfloat h, GLfloat r, bool c = false);
	void Display() ;

	GLfloat GetHeight()  { return Height; }
	GLfloat GetWidth()  { return 2 * Radius; }
    void SetHeight(GLfloat h) { Height = h; }
};

////////////////////////////////////////////////////////////////////////
// segment wiezy
////////////////////////////////////////////////////////////////////////
class SegmentWiezy : public UniformObject {
	Wspornik ElemPionowy;
	Wspornik ElemPoziomy;
	Wspornik ElemUkosny;

	void DisplayPoziome() ;	// pokazuje poziome wsporniki jednego poziomu
	void DisplayPionowe() ;	// pokaz pionowe
	void DisplayUkosne() ;	// pokaz ukosne jednej sciany
public:
	SegmentWiezy();
	void Display() ;

	GLfloat GetHeight()  { return ElemPionowy.GetHeight(); }    
	GLfloat GetWidth()  { return ElemPoziomy.GetWidth(); }    
};

////////////////////////////////////////////////////////////////////////
// segment ramienia nosnego
////////////////////////////////////////////////////////////////////////
class SegmentRamienia : public UniformObject {
protected:
	Wspornik WzdluznyDolny;
	Walec WzdluznyGorny;
	Walec UkosnyGlowny;
	Wspornik Koncowy;
	Wspornik Poziomy;
    
	void DisplayUkosne() ;		// pokazuje jeden rzad ukosnych wspornikow
	void DisplayPoziome() ;	    // pokazuje poziome wsporniki
public:
	SegmentRamienia();
    virtual void Display() ;
    
	GLfloat GetHeight()  { return 1.86; }
	GLfloat GetWidth()  { return 12.28; }
};

////////////////////////////////////////////////////////////////////////
// podstawa wiezy zurawia
////////////////////////////////////////////////////////////////////////
class PodstawaWiezy : public UniformObject {
	SegmentWiezy Segment;
	Wspornik Nozka;
	Blok Podloga;
	Blok Ciezar;
	Wspornik Podpora;

	void DisplayNozki() ;
	void DisplayCiezary() ;
	void DisplayPodpory() ;
public:
	PodstawaWiezy();
	void Display() ;
	GLfloat GetHeight()  { return 8.5; }
};

////////////////////////////////////////////////////////////////////////
// cale tylne ramie
////////////////////////////////////////////////////////////////////////
class TylneRamie : public UniformObject {
	Blok GlownyWspornik;
	Blok UkosnyWspornik;
	Blok KoncowyWspornik;
	Blok Poprzeczny;
	Blok Ciezar;
	Blok Tyl;
	Blok Tablica;

	void DisplayCzesc1() ;
	void DisplayCzesc2() ;

public:
	TylneRamie();
	void Display() ;
	GLfloat GetHeight()  { return 0.92; }
};

////////////////////////////////////////////////////////////////////////
// budka operatora
////////////////////////////////////////////////////////////////////////
class Kabina : public UniformObject {
public:
	Kabina();
	void Display() ;
    GLfloat GetHeight()  { return 2.2; }
};

////////////////////////////////////////////////////////////////////////
// wozek, jezdzacy po ramieniu
////////////////////////////////////////////////////////////////////////
class WozekDzwigu : public UniformObject {
	Blok Czesc1;
	Blok Czesc2;
	Walec Kolko;
    
public:
	WozekDzwigu();
	void Display() ;
	GLfloat GetHeight()  { return 1.2; }
};

////////////////////////////////////////////////////////////////////////
// Wieza
////////////////////////////////////////////////////////////////////////
class Wieza {
    int IleSegmentow;
    SegmentWiezy Element;
    
public:
    Wieza(int Ile);
    void Display() ;
    GLfloat GetHeight()  { return IleSegmentow * Element.GetHeight(); }
};

////////////////////////////////////////////////////////////////////////
// Ramie
////////////////////////////////////////////////////////////////////////
class Ramie {
    int IleSegmentow;
    SegmentRamienia Element;
    
public:
    Ramie(int Ile);
    void Display() ;
    GLfloat GetLength() { return IleSegmentow * Element.GetWidth(); }
};

////////////////////////////////////////////////////////////////////////
// dolna czesc zurawia
////////////////////////////////////////////////////////////////////////
class DolZurawia : public UniformObject {
	int IleSegmentow;			    // ilosc segmentow
    SegmentWiezy Segment;
	Wieza WiezaZurawia;
    //Walec Lozysko;					// lozysko obrotowe (?) - laczy z gora
	PodstawaWiezy Podstawa;
public:
	DolZurawia(int n);
	void Display() ;
    GLfloat GetHeight()  { return IleSegmentow * Segment.GetHeight() + Podstawa.GetHeight(); }
};

////////////////////////////////////////////////////////////////////////
// gora zurawia
////////////////////////////////////////////////////////////////////////
class GoraZurawia {
    SegmentWiezy Segment;       // najwyzszy segment
	TylneRamie PrzeciwRamie;
    Ramie RamieZurawia;
	Kabina Budka;
    
	Walec Lozysko;
	Walec Rurka;        // do szczytu wiezy
	Walec Rura;         // do szczytu wiezy
    
	void DisplayRury() ;
	void DisplayZigZag() ;
	void DisplayLiny() ;
public:
	GoraZurawia(int n);
	void Display();
	GLfloat GetHeight()  { return 10.0; }
};


////////////////////////////////////////////////////////////////////////
// Caly zuraw
////////////////////////////////////////////////////////////////////////
class ZurawWiezowy : public UniformObject {
    DolZurawia Dol;
	GoraZurawia Gora;
	WozekDzwigu Wozek;
    Walec Magnes;

protected:
    GLfloat xrot;  // X Rotation - obrot ramienia
    GLfloat xpos;  // X Position - przesuniecie wozka
    GLfloat ypos;  // Y Position - wysokosc liny

public:
	ZurawWiezowy(int segw, int segr);
	void Display() ;
    
	//GLfloat GetHeight() const { return Dol.GetHeight() + Gora.GetHeight(); }
	//static void InitTextures();
	//static void FreeTextures();

    void RamieLeft() { xrot+=0.1f; };
    void RamieRight() { xrot-=0.1f; };
    void WozekForward() { if(xpos<30.0) xpos+=0.1f; };
    void WozekBackward() { if(xpos>0.0) xpos-=0.1f; };
    void LinaUp() { if(ypos>-8.0) ypos-=0.1f; };
    void LinaDown() { if(ypos<20.0) ypos+=0.1f; };
};

////////////////////////////////////////////////////////////////////////
// Skybox
////////////////////////////////////////////////////////////////////////
class Skybox : public UniformObject {
    GLfloat Radius;
public:
    /* Skybox textures : top, bottom, left, right, back, front */
    GLuint skyboxTextures[6];

    Skybox(GLfloat r);
    void Display() ;
};
