#include "SceneObjects.h"
const GLfloat Yellow[4] = {0.84, 0.64, 0.12, 1.0};
GLuint textures[10];

/*======================================================================
                            UniformObject
======================================================================*/
UniformObject::UniformObject() {}

/*======================================================================
                                Blok
======================================================================*/
////////////////////////////////////////////////////////////////////////
// ctor
////////////////////////////////////////////////////////////////////////
Blok::Blok(GLfloat h, GLfloat w, GLfloat l) {
	Height = h;
	Width = w;
	Length = l;
}
////////////////////////////////////////////////////////////////////////
// display
////////////////////////////////////////////////////////////////////////
void Blok::Display()  {
	const GLfloat halfW = Width / 2.0;
	const GLfloat halfH = Height / 2.0;
	const GLfloat halfL = Length / 2.0;
	GLfloat f = 1.0 / (2 * Length + 2 * Width);
	if(Height > 2 * Width) f = 1.0 / (2 * Length + Height);
 
    // glBindTexture( GL_TEXTURE_2D, TextureId );
    //glColor3f(1,1,0);

	//const GLfloat Yellow[4] = {0.84, 0.64, 0.12, 1.0};
	//glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, Yellow);

	/// geometria
	glBegin(GL_QUADS);

	/// przednia sciana
	glNormal3f(0.0, 0.0, 1.0);

	glTexCoord2f(0.0, f * Length);
	glVertex3f(-halfW, -halfH, halfL);

	glTexCoord2f(0.0, f * (Height+Length));
	glVertex3f(-halfW, halfH, halfL);

	glTexCoord2f(f * Width, f * (Height+Length));
	glVertex3f(halfW, halfH, halfL);

	glTexCoord2f(f * Width, f * Length);
	glVertex3f(halfW, -halfH, halfL);

	/// tylna sciana
	glNormal3f(0.0, 0.0, -1.0);

	glTexCoord2f(f * (2.0*Width+Length), f * Length);
	glVertex3f(-halfW, -halfH, -halfL);

	glTexCoord2f(f * (2.0*Width+Length), f * (Height+Length));
	glVertex3f(-halfW, halfH, -halfL);

	glTexCoord2f(f * (Width+Length), f * (Height+Length));
	glVertex3f(halfW, halfH, -halfL);

	glTexCoord2f(f * (Width+Length), f * Length);
	glVertex3f(halfW, -halfH, -halfL);

	/// lewa sciana
	glNormal3f(-1.0, 0.0, 0.0);

	glTexCoord2f(f * (2.0*Width+Length), f * Length);
	glVertex3f(-halfW, -halfH, -halfL);

	glTexCoord2f(f * (2.0*Width+Length), f * (Height+Length));
	glVertex3f(-halfW, halfH, -halfL);

	glTexCoord2f(1.0, f * (Height+Length));
	glVertex3f(-halfW, halfH, halfL);

	glTexCoord2f(1.0, f * Length);
	glVertex3f(-halfW, -halfH, halfL);

	/// prawa sciana
	glNormal3f(1.0, 0.0, 0.0);

	glTexCoord2f(f * (Width+Length), f * Length);
	glVertex3f(halfW, -halfH, -halfL);

	glTexCoord2f(f * (Width+Length), f * (Height + Length));
	glVertex3f(halfW, halfH, -halfL);

	glTexCoord2f(f * Width, f * (Height + Length));
	glVertex3f(halfW, halfH, halfL);

	glTexCoord2f(f * Width, f * Length);
	glVertex3f(halfW, -halfH, halfL);

	/// gorna sciana
	glNormal3f(0.0, 1.0, 0.0);

	glTexCoord2f(0.0, f * (Height + Length));
	glVertex3f(-halfW, halfH, halfL);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-halfW, halfH, -halfL);

	glTexCoord2f(f * Width, 1.0);
	glVertex3f(halfW, halfH, -halfL);

	glTexCoord2f(f * Width, f * (Height + Length));
	glVertex3f(halfW, halfH, halfL);

	/// dolna sciana
	glNormal3f(0.0, -1.0, 0.0);

	glTexCoord2f(0.0, f * Length);
	glVertex3f(-halfW, -halfH, halfL);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(-halfW, -halfH, -halfL);

	glTexCoord2f(f * Width, 0.0);
	glVertex3f(halfW, -halfH, -halfL);

	glTexCoord2f(f * Width, f * Length);
	glVertex3f(halfW, -halfH, halfL);

	/// koniec geometrii
	glEnd();
}

/*======================================================================
                                Wspornik
======================================================================*/
////////////////////////////////////////////////////////////////////////
// ctor
////////////////////////////////////////////////////////////////////////
Wspornik::Wspornik(GLfloat h, GLfloat a) {
	Height = h;
	Width = a;
}
////////////////////////////////////////////////////////////////////////
// display
////////////////////////////////////////////////////////////////////////
void Wspornik::Display()  {
    const GLfloat halfW = Width / 2.0;
	const GLfloat halfH = Height / 2.0;
	const GLfloat t = Width / Height;

    //glBindTexture( GL_TEXTURE_2D, TextureId );
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, Yellow);

	/// geometria
	glBegin(GL_QUADS);

	/// przednia sciana
	glNormal3f(0.0, 0.0, 1.0);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(-halfW, -halfH, halfW);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-halfW, halfH, halfW);

	glTexCoord2f(t, 1.0);
	glVertex3f(halfW, halfH, halfW);

	glTexCoord2f(t, 0.0);
	glVertex3f(halfW, -halfH, halfW);

	/// tylna
	glNormal3f(0.0, 0.0, -1.0);

	glTexCoord2f(3*t, 0.0);
	glVertex3f(-halfW, -halfH, -halfW);

	glTexCoord2f(3*t, 1.0);
	glVertex3f(-halfW, halfH, -halfW);

	glTexCoord2f(2*t, 1.0);
	glVertex3f(halfW, halfH, -halfW);

	glTexCoord2f(2*t, 0.0);
	glVertex3f(halfW, -halfH, -halfW);

	/// lewa
	glNormal3f(-1.0, 0.0, 0.0);

	glTexCoord2f(3*t, 0.0);
	glVertex3f(-halfW, -halfH, -halfW);

	glTexCoord2f(3*t, 1.0);
	glVertex3f(-halfW, halfH, -halfW);

	glTexCoord2f(4*t, 1.0);
	glVertex3f(-halfW, halfH, halfW);

	glTexCoord2f(4*t, 0.0);
	glVertex3f(-halfW, -halfH, halfW);

	/// prawa
	glNormal3f(1.0, 0.0, 0.0);

	glTexCoord2f(2*t, 0.0);
	glVertex3f(halfW, -halfH, -halfW);

	glTexCoord2f(2*t, 1.0);
	glVertex3f(halfW, halfH, -halfW);

	glTexCoord2f(t, 1.0);
	glVertex3f(halfW, halfH, halfW);

	glTexCoord2f(t, 0.0);
	glVertex3f(halfW, -halfH, halfW);

	glEnd();
}

/*======================================================================
                                Walec
======================================================================*/
////////////////////////////////////////////////////////////////////////
// ctor
////////////////////////////////////////////////////////////////////////
Walec::Walec(GLfloat r, GLfloat h, bool c) {
    Radius = r;
    Height = h;
}
////////////////////////////////////////////////////////////////////////
// display
////////////////////////////////////////////////////////////////////////
void Walec::Display()  {
    //GLUquadric* quad = gluNewQuadric();
    //glBindTexture( GL_TEXTURE_2D, textures[0] );


    //glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    //glTranslatef(0.0f, 0.0f, -Radius/2);
    //glTranslatef(0.0f, Height/2, 0.0f);
    //glRotatef( 90.0, 1.0f, 0.0f, 0.0f); // Rotate On The X Axis 
    
    //glColor3f(1,0,0);
    //glBegin(GL_POLYGON);

	//glTranslatef(cylinder->pos[0], cylinder->pos[1], cylinder->pos[2]);
	//glRotatef(cylinder->angle, -1.0, 0, 0);

    GLUquadricObj *Obj = gluNewQuadric();

	gluDisk(Obj, 0.0, Radius, 300, 90);
    gluCylinder(Obj, Radius, Radius, Height, 30, 30);
	
	gluDeleteQuadric(Obj);

    //glEnd();

    glPopMatrix();



}

/*======================================================================
                            SegmentWiezy
======================================================================*/


/// ///////////////////////////////////////////////////////////
/// ///////////////////////////////////////////////////////////
///                    Segment Wiezy
/// ///////////////////////////////////////////////////////////
/// ///////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// konstruktor segmentu wiezy - tworzy elementy skladowe o wymiarach
// odpowiadajacych rzeczywistym
//////////////////////////////////////////////////////////////////////////
SegmentWiezy::SegmentWiezy()
: ElemPionowy(6.28, 0.31), ElemPoziomy(2.05, 0.2), ElemUkosny(2.52, 0.2) {
	//ElemPoziomy.SetAmbient(Yellow[0], Yellow[1], Yellow[2], 1.0);
	//ElemUkosny.SetAmbient(Yellow[0], Yellow[1], Yellow[2], 1.0);
}

//////////////////////////////////////////////////////////////////////////
// pokaz segment wiezy - pozycjonuje wszystko zgodnie z rzeczywistymi
// rozmiarami, punkt odniesienia w geometrycznym srodku segmentu
//////////////////////////////////////////////////////////////////////////
void SegmentWiezy::Display() 
{
	/// pionowe wsporniki
	DisplayPionowe();

	/// dolne poziome
	glPushMatrix();
    
    //glLoadIdentity();				// Reset The View
    //glTranslatef(0.0f, 0.0f, -7.0f);
    
	glTranslatef(0.0, -2.94, 0.0);

	DisplayPoziome();

	glPopMatrix();

	/// gorne poziome
	glPushMatrix();
	glTranslatef(0.0, 2.94, 0.0);

	DisplayPoziome();

	glPopMatrix();

	/// "srodkowe" poziome
	glPushMatrix();
	glTranslatef(0.0, 1.47, 0.0);

	DisplayPoziome();

	glPopMatrix();

	/// przednie ukosne
	glPushMatrix();
	glTranslatef(0.0, 0.0, 1.07);

	DisplayUkosne();

	glPopMatrix();

	/// tylne ukosne
	glPushMatrix();
	glTranslatef(0.0, 0.0, -1.07);
	glRotatef(180.0, 0.0, 1.0, 0.0);

	DisplayUkosne();

	glPopMatrix();

	/// lewe ukosne
	glPushMatrix();
	glTranslatef(-1.07, 0.0, 0.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);

	DisplayUkosne();

	glPopMatrix();

	/// prawe ukosne
	glPushMatrix();
	glTranslatef(1.07, 0.0, 0.0);
	glRotatef(90.0, 0.0, -1.0, 0.0);

	DisplayUkosne();

	glPopMatrix();
}

////////////////////////////////////////////////////////////////////////
// pokazuje poziome wsporniki
////////////////////////////////////////////////////////////////////////
void SegmentWiezy::DisplayPionowe() 
{
	//glBindTexture(GL_TEXTURE_2D, pTexWspornik->GetName());

	/// lewy przedni
	glPushMatrix();
	glTranslatef(-1.07, 0.0, 1.07);
	glRotatef(-90.0, 0.0, 1.0, 0.0);

	ElemPionowy.Display();

	glPopMatrix();

	/// prawy przedni
	glPushMatrix();
	glTranslatef(1.07, 0.0, 1.07);

	ElemPionowy.Display();

	glPopMatrix();

	/// lewy tylny
	glPushMatrix();
	glTranslatef(-1.07, 0.0, -1.07);
	glRotatef(180.0, 0.0, 1.0, 0.0);

	ElemPionowy.Display();

	glPopMatrix();

	// prawy tylny
	glPushMatrix();
	glTranslatef(1.07, 0.0, -1.07);
	glRotatef(90.0, 0.0, 1.0, 0.0);

	ElemPionowy.Display();

	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
}

////////////////////////////////////////////////////////////////////////
// pokazuje poziome wsporniki jednego poziomu
////////////////////////////////////////////////////////////////////////
void SegmentWiezy::DisplayPoziome() 
{
	/// przedni
	glPushMatrix();
	glTranslatef(0.0, 0.0, 1.07);
	glRotatef(90.0, 0.0, 0.0, 1.0);

	ElemPoziomy.Display();

	glPopMatrix();

	/// tylny
	glPushMatrix();
	glTranslatef(0.0, 0.0, -1.07);
	glRotatef(90.0, 0.0, 0.0, 1.0);

	ElemPoziomy.Display();

	glPopMatrix();

	/// lewy
	glPushMatrix();
	glTranslatef(-1.07, 0.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);

	ElemPoziomy.Display();

	glPopMatrix();

	/// prawy
	glPushMatrix();
	glTranslatef(1.07, 0.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);

	ElemPoziomy.Display();

	glPopMatrix();
}

////////////////////////////////////////////////////////////////////////
// pokaz ukosne jednej sciany
////////////////////////////////////////////////////////////////////////
void SegmentWiezy::DisplayUkosne() 
{
	/// 1. wspornik od dolu
	glPushMatrix();
	glTranslatef(0.0, 0.735 - 2.94, 0.0);
    glRotatef(-54.3, 0.0, 0.0, 1.0);

	ElemUkosny.Display();

	glPopMatrix();

	/// 2. wspornik od dolu
	glPushMatrix();
	glTranslatef(0.0, 0.735 - 1.47, 0.0);
    glRotatef(-54.3, 0.0, 0.0, -1.0);

	ElemUkosny.Display();

	glPopMatrix();

	/// 3. wspornik od dolu
	glPushMatrix();
	glTranslatef(0.0, 0.735, 0.0);
    glRotatef(-54.3, 0.0, 0.0, 1.0);

	ElemUkosny.Display();

	glPopMatrix();

	/// 4. wspornik od dolu
	glPushMatrix();
	glTranslatef(0.0, 0.735 + 1.47, 0.0);
    glRotatef(-54.3, 0.0, 0.0, -1.0);

	ElemUkosny.Display();

	glPopMatrix();
}
/*======================================================================
                            SegmentRamienia
======================================================================*/
////////////////////////////////////////////////////////////////////////
// konstruktor segmentu ramienia
////////////////////////////////////////////////////////////////////////
SegmentRamienia::SegmentRamienia()
: WzdluznyDolny(12.28, 0.31), WzdluznyGorny(0.15, 12.28, 2), 
UkosnyGlowny(0.1, 2.1, 2), Koncowy(2.0, 0.2), Poziomy(1.55, 0.15) {
}
////////////////////////////////////////////////////////////////////////
// pokaz segment ramienia
////////////////////////////////////////////////////////////////////////
void SegmentRamienia::Display()  {
	/// sa 2 wsporniki dolne...

	/// ustaw pierwszy...
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.815);
    glTranslatef(WzdluznyDolny.GetHeight()/2, 0.0, 0.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);

	WzdluznyDolny.Display();

	glPopMatrix();

	/// ustaw drugi...
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.815);
    glTranslatef(WzdluznyDolny.GetHeight()/2, 0.0, 0.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);

	WzdluznyDolny.Display();

	glPopMatrix();

	/// teraz wspornik gorny...

	glPushMatrix();
	glTranslatef(-1.8, 1.86, 0.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);

	WzdluznyGorny.Display();

	glPopMatrix();

	/// teraz ukosne
    glPushMatrix();
    glTranslatef(0.0, 0.0, -0.9);
    glRotatef(-65.0, 1.0, 0.0, 0.0);
        
    DisplayUkosne();

	glPopMatrix();

	/// teraz ukosne w druga strone 
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.9);
    glRotatef(-115.0, 1.0, 0.0, 0.0);
        
    DisplayUkosne();

	glPopMatrix();

	/// i wsporniki poziome
    glPushMatrix();
    glTranslatef(WzdluznyDolny.GetHeight()/2, 0.0, 0.0);
    
	DisplayPoziome();
	glPopMatrix();
}
////////////////////////////////////////////////////////////////////////
// pokazuje jeden rzad ukosnych wspornikow
////////////////////////////////////////////////////////////////////////
void SegmentRamienia::DisplayUkosne()  {
	/// ukosne w jedna strone
	glPushMatrix();

	// petla renderowania ukosnych wspornikow
	for(int i = 0; i < 7; i++) {
		glPushMatrix();
		UkosnyGlowny.Display();

		glPopMatrix();

		glTranslatef(1.74, 0.0, 0.0);
	}

	glPopMatrix();
}
////////////////////////////////////////////////////////////////////////
// pokazuje poziome wsporniki
////////////////////////////////////////////////////////////////////////
void SegmentRamienia::DisplayPoziome()  {
	glPushMatrix();
	glTranslatef(-6.04, 0.0, 0.0);

	for(int i = 0; i < 7; i++) {
		glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);

		Poziomy.Display();

		glPopMatrix();

		glTranslatef(1.74, 0.0, 0.0);
	}

	glPopMatrix();
}

/*======================================================================
                            SegmentRamienia
======================================================================*/
////////////////////////////////////////////////////////////////////////
// konstruje podstawe zurawia, zgodnie z jej rozmiarami
////////////////////////////////////////////////////////////////////////
PodstawaWiezy::PodstawaWiezy()
: Nozka(1.33, 0.60), Podloga(0.48, 10.7, 10.7), Ciezar(2.1, 6.34, 4.07),
Podpora(7.4, 0.31) {
}

////////////////////////////////////////////////////////////////////////
// renderuje obiekt - pokazuje podstawe wiezy
////////////////////////////////////////////////////////////////////////
void PodstawaWiezy::Display() 
{
	/// najpierw nozki...
	DisplayNozki();

	/// teraz podloga...
	glPushMatrix();
	glTranslatef(0.0, 0.24 + Nozka.GetHeight(), 0.0);

	Podloga.Display();

	glPopMatrix();

	/// teraz pierwszy segment wiezy...
	glPushMatrix();
	glTranslatef(0.0, Segment.GetHeight() / 2 + 2.22, 0.0);

	Segment.Display();

	glPopMatrix();

	/// teraz obciazniki...
	DisplayCiezary();

	/// teraz podpory...
	DisplayPodpory();
}

////////////////////////////////////////////////////////////////////////
// nozki podstawy
////////////////////////////////////////////////////////////////////////
void PodstawaWiezy::DisplayNozki() 
{
	const GLfloat halfH = Nozka.GetHeight() / 2;

	/// lewa przednia
	glPushMatrix();
	glTranslatef(-5.0, halfH, -5.0);

	Nozka.Display();

	glPopMatrix();

	/// prawa przednia
	glPushMatrix();
	glTranslatef(5.0, halfH, -5.0);

	Nozka.Display();

	glPopMatrix();

	/// lewa tylna
	glPushMatrix();
	glTranslatef(-5.0, halfH, 5.0);

	Nozka.Display();

	glPopMatrix();

	/// prawa tylna
	glPushMatrix();
	glTranslatef(5.0, halfH, 5.0);

	Nozka.Display();

	glPopMatrix();
}

////////////////////////////////////////////////////////////////////////
// pokazuje jeden z 4 ciezarow
////////////////////////////////////////////////////////////////////////
void PodstawaWiezy::DisplayCiezary() 
{
	const GLfloat ymove = Ciezar.GetHeight() / 2 + 1.8;
	const GLfloat halfL = Ciezar.GetLength() / 2;

	/// przod
	glPushMatrix();
	glTranslatef(0.0, ymove, -halfL - 1.225);

	Ciezar.Display();

	glPopMatrix();

	/// tyl
	glPushMatrix();
	glTranslatef(0.0, ymove, halfL + 1.225);

	Ciezar.Display();

	glPopMatrix();

	/// z lewej
	glPushMatrix();
	glTranslatef(halfL + 1.225, ymove, 0.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);

	Ciezar.Display();

	glPopMatrix();

	/// z prawej
	glPushMatrix();
	glTranslatef(-halfL - 1.225, ymove, 0.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);

	Ciezar.Display();

	glPopMatrix();
}

////////////////////////////////////////////////////////////////////////
// pokazuje jeden z 4 ciezarow
////////////////////////////////////////////////////////////////////////
void PodstawaWiezy::DisplayPodpory() 
{
	/// lewa z przodu
	glPushMatrix();
	glTranslatef(-1.74 - 1.1, 2.565 + 1.8, 1.74 + 1.1);
	glRotatef(45.0, 0.0, 1.0, 0.0);
	glRotatef(-44.0, 0.0, 0.0, 1.0);

	Podpora.Display();

	glPopMatrix();

	/// prawa z przodu
	glPushMatrix();
	glTranslatef(1.74 + 1.1, 2.565 + 1.8, 1.74 + 1.1);
	glRotatef(135.0, 0.0, 1.0, 0.0);
	glRotatef(-44.0, 0.0, 0.0, 1.0);

	Podpora.Display();

	glPopMatrix();

	/// lewa z tylu
	glPushMatrix();
	glTranslatef(-1.74 - 1.1, 2.565 + 1.8, -1.74 - 1.1);
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	glRotatef(-44.0, 0.0, 0.0, 1.0);

	Podpora.Display();

	glPopMatrix();

	/// prawa z tylu
	glPushMatrix();
	glTranslatef(1.74 + 1.1, 2.565 + 1.8, -1.74 - 1.1);
	glRotatef(-135.0, 0.0, 1.0, 0.0);
	glRotatef(-44.0, 0.0, 0.0, 1.0);

	Podpora.Display();

	glPopMatrix();
}

/*======================================================================
                            SegmentRamienia
======================================================================*/
////////////////////////////////////////////////////////////////////////
// pokaz ramie, punkt odniesienia na dole, na poczatku ramienia
////////////////////////////////////////////////////////////////////////
TylneRamie::TylneRamie()
: GlownyWspornik(0.8, 13.22, 0.4), UkosnyWspornik(0.5, 1.7, 0.3), KoncowyWspornik(0.8, 8.3, 0.4),
Poprzeczny(0.9, 0.8, 2.5), Ciezar(5.2, 3.0, 1.65), Tyl(0.8, 3.0, 1.65), Tablica(1.0, 5.0, 0.05) {
}

////////////////////////////////////////////////////////////////////////
// pokaz tylne ramie, punkt odniesienia na dole, na poczatku ramienia
////////////////////////////////////////////////////////////////////////
void TylneRamie::Display()  {
	/// glowne wsporniki
	glPushMatrix();
	glTranslatef(GlownyWspornik.GetWidth() / 2.0, GlownyWspornik.GetHeight() / 2.0, 0.0);

	DisplayCzesc1();

	glTranslatef(GlownyWspornik.GetWidth() / 2.0, 0.0, 0.0);

	Poprzeczny.Display();

	glTranslatef(KoncowyWspornik.GetWidth() / 2.0, 0.0, 0.0);

	DisplayCzesc2();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-Tablica.GetWidth() / 2.0 + 8.0, 0.8, 0.9);
	Tablica.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-Tablica.GetWidth() / 2.0 + 8.0, 0.8, -0.9);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	Tablica.Display();
	glPopMatrix();
    
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3f(-1.0, 6.0, 0.0);
    glVertex3f(14.0, 0.5, 0.0);
    glEnd();
    glPopMatrix();
}

////////////////////////////////////////////////////////////////////////
// pokaz pierwsza czesc ramienia
////////////////////////////////////////////////////////////////////////
void TylneRamie::DisplayCzesc1()  {
	/// 1. wspornik
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.685);

	GlownyWspornik.Display();

	glPopMatrix();

	/// 2. wspornik
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.685);

	GlownyWspornik.Display();

	glPopMatrix();

	/// wsporniki ukosne
	glPushMatrix();
	glTranslatef(-GlownyWspornik.GetWidth() / 2 + 1.0, 0.0, 0.0);

	for(int i = 0; i < 4; i++)
	{
		glPushMatrix();
		glRotatef(45.0, 0.0, 1.0, 0.0);

		UkosnyWspornik.Display();

		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.6, 0.0, 0.0);
		glRotatef(-45.0, 0.0, 1.0, 0.0);

		UkosnyWspornik.Display();

		glPopMatrix();

		glTranslatef(3.2, 0.0, 0.0);
	}

	glPopMatrix();
}

////////////////////////////////////////////////////////////////////////
// pokaz druga czesc ramienia
////////////////////////////////////////////////////////////////////////
void TylneRamie::DisplayCzesc2()  {

	/// 1. wspornik
	glPushMatrix();
	glTranslatef(0.0, 0.0, 1.025);

	KoncowyWspornik.Display();

	glPopMatrix();

	/// 2. wspornik
	glPushMatrix();
	glTranslatef(0.0, 0.0, -1.025);

	KoncowyWspornik.Display();

	glPopMatrix();

	/// ciezar...
	glPushMatrix();
	glTranslatef(0.0, -0.4, 0.0);

	Ciezar.Display();

	glPopMatrix();

	/// podloga tylu
	glPushMatrix();
	glTranslatef(3.0, 0.0, 0.0);

	Tyl.Display();

	glPopMatrix();
}

/*======================================================================
                            SegmentRamienia
======================================================================*/
////////////////////////////////////////////////////////////////////////
// utworz budke
////////////////////////////////////////////////////////////////////////
Kabina::Kabina() {
}

////////////////////////////////////////////////////////////////////////
// pokaz obiekt - budka operatora dzwigu
////////////////////////////////////////////////////////////////////////
void Kabina::Display()  {
	const GLfloat f = 1.0 / 5.4;

	//glBindTexture(GL_TEXTURE_2D, TextureId);

	glBegin(GL_QUADS);

	// podloga
	glNormal3f(0.0, -1.0, 0.0);

	glTexCoord2f(1.5 * f, 1.5 * f);
	glVertex3f(-1.0, 0.0, 0.75);

	glTexCoord2f(1.5 * f, 0.0);
	glVertex3f(-1.0, 0.0, -0.75);

	glTexCoord2f(3.5 * f, 0.0);
	glVertex3f(1.0, 0.0, -0.75);

	glTexCoord2f(3.5 * f, 1.5 * f);
	glVertex3f(1.0, 0.0, 0.75);

	// tylna sciana
	glNormal3f(-1.0, 0.0, 0.0);

	glTexCoord2f(0.0, 1.5 * f);
	glVertex3f(-1.0, 0.0, -0.75);

	glTexCoord2f(0.0, 3.7 * f);
	glVertex3f(-1.0, 2.2, -0.75);

	glTexCoord2f(1.5 * f, 3.7 * f);
	glVertex3f(-1.0, 2.2, 0.75);

	glTexCoord2f(1.5 * f, 1.5 * f);
	glVertex3f(-1.0, 0.0, 0.75);

	// dach
	glNormal3f(0.0, 1.0, 0.0);

	glTexCoord2f(1.5 * f, 1.5 * f);
	glVertex3f(-1.0, 2.2, 0.75);

	glTexCoord2f(1.5 * f, 0.0);
	glVertex3f(-1.0, 2.2, -0.75);

	glTexCoord2f(3.5 * f, 0.0);
	glVertex3f(1.4, 2.2, -0.75);

	glTexCoord2f(3.5 * f, 1.5 * f);
	glVertex3f(1.4, 2.2, 0.75);

	// przednia sciana
	glNormal3f(0.98, -0.2, 0.0);

	glTexCoord2f(3.9 * f, 1.5 * f);
	glVertex3f(1.0, 0.0, 0.75);

	glTexCoord2f(3.9 * f, 3.7 * f);
	glVertex3f(1.4, 2.2, 0.75);

	glTexCoord2f(5.4 * f, 3.7 * f);
	glVertex3f(1.4, 2.2, -0.75);

	glTexCoord2f(5.4 * f, 1.5 * f);
	glVertex3f(1.0, 0.0, -0.75);

	// prawa sciana
	glNormal3f(0.0, 0.0, 1.0);

	glTexCoord2f(1.5 * f, 1.5 * f);
	glVertex3f(-1.0, 0.0, 0.75);

	glTexCoord2f(1.5 * f, 3.7 * f);
	glVertex3f(-1.0, 2.2, 0.75);

	glTexCoord2f(3.9 * f, 3.7 * f);
	glVertex3f(1.4, 2.2, 0.75);

	glTexCoord2f(3.5 * f, 1.5 * f);
	glVertex3f(1.0, 0.0, 0.75);

	// lewa sciana
	glNormal3f(0.0, 0.0, -1.0);

	glTexCoord2f(1.5 * f, 1.5 * f);
	glVertex3f(-1.0, 0.0, -0.75);

	glTexCoord2f(1.5 * f, 3.7 * f);
	glVertex3f(-1.0, 2.2, -0.75);

	glTexCoord2f(3.9 * f, 3.7 * f);
	glVertex3f(1.4, 2.2, -0.75);

	glTexCoord2f(3.5 * f, 1.5 * f);
	glVertex3f(1.0, 0.0, -0.75);

	glEnd();

	//glBindTexture(GL_TEXTURE_2D, 0);
}

/*======================================================================
                            WozekDzwigu
======================================================================*/
////////////////////////////////////////////////////////////////////////
// konstruuje wozek dzwigu
////////////////////////////////////////////////////////////////////////
WozekDzwigu::WozekDzwigu()
: Czesc1(0.5, 1.5, 0.2), Czesc2(0.4, 0.15, 1.5), Kolko(0.25, 0.2)
{
	glPushMatrix();
	glTranslatef(0.0, -Czesc1.GetHeight() / 2.0, 0.0);

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.6);
	Czesc1.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.6);
	Czesc1.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -Czesc2.GetHeight() / 2.0, 0.0);

	glPushMatrix();
	glTranslatef(-0.3, 0.0, 0.0);
	Czesc2.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 0.0, 0.0);
	Czesc2.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.3, -0.15, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	Kolko.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, -0.15, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	Kolko.Display();
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}

////////////////////////////////////////////////////////////////////////
// pokaz obiekt
////////////////////////////////////////////////////////////////////////
void WozekDzwigu::Display() 
{
    glPushMatrix();
	glTranslatef(0.0, -Czesc1.GetHeight() / 2.0, 0.0);

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.6);
	Czesc1.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.6);
	Czesc1.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -Czesc2.GetHeight() / 2.0, 0.0);

	glPushMatrix();
	glTranslatef(-0.3, 0.0, 0.0);
	Czesc2.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 0.0, 0.0);
	Czesc2.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.3, -0.15, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	Kolko.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, -0.15, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	Kolko.Display();
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}


/*======================================================================
                                Wieza
======================================================================*/
////////////////////////////////////////////////////////////////////////
// kostrukcja wiezy
////////////////////////////////////////////////////////////////////////
Wieza::Wieza(int Ile) : IleSegmentow(Ile) {
}

////////////////////////////////////////////////////////////////////////
// pokaz wieze
////////////////////////////////////////////////////////////////////////
void Wieza::Display()  {
    glPushMatrix();

    //Element.Display();
    
    for(int i=0; i!=IleSegmentow; i++) {
        Element.Display();
        glTranslatef(0.0f, Element.GetHeight(), 0.0f);
    }
        
    glPopMatrix();    
}

/*======================================================================
                                Ramie
======================================================================*/
////////////////////////////////////////////////////////////////////////
// ctor
////////////////////////////////////////////////////////////////////////
Ramie::Ramie(int Ile) : IleSegmentow(Ile) {
}

////////////////////////////////////////////////////////////////////////
// pokaz wieze
////////////////////////////////////////////////////////////////////////
void Ramie::Display()  {
    glPushMatrix();
    
    for(int i=0; i!=IleSegmentow; i++) {
        Element.Display();
        glTranslatef(Element.GetWidth(), 0.0f, 0.0f);
    }
        
    glPopMatrix();    
}

/*======================================================================
                                GoraZurawia
======================================================================*/
////////////////////////////////////////////////////////////////////////
// konstrukcja z podaniem ilosci segmentow ramienia nosnego
////////////////////////////////////////////////////////////////////////
GoraZurawia::GoraZurawia(int n) : RamieZurawia(n), Lozysko(1.8, 0.8), 
Rurka(0.11, 1.0), Rura(0.15, 5.0) {
}

////////////////////////////////////////////////////////////////////////
// display
////////////////////////////////////////////////////////////////////////
void GoraZurawia::Display() {
    
    glPushMatrix();
	glTranslatef(0.0, 4.5, 0.0);
         
    /// pokaz ramie
	glPushMatrix();
	glTranslatef(1.2, 0.0, 0.0);
	RamieZurawia.Display();
	glPopMatrix();
    
    /// tylna czesc ramienia
	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glTranslatef(1.1, 0.0, 0.0);
	PrzeciwRamie.Display();
	glPopMatrix();

	glPopMatrix();
    
    /// najwyzszy segment
	glPushMatrix();
	glTranslatef(0.0, Segment.GetHeight() / 2.0, 0.0);
	Segment.Display();
	glPopMatrix();
    
    /// kabina
	glPushMatrix();
	glTranslatef(1.2, 2.0, 1.9);
	Budka.Display();
	glPopMatrix();

    /// lozysko
	glPushMatrix();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	Lozysko.Display();
	glPopMatrix();

	DisplayRury();

	glPushMatrix();
	DisplayZigZag();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	DisplayZigZag();
	glPopMatrix();

	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0);
	DisplayZigZag();
	glPopMatrix();

	glPushMatrix();
	glRotatef(270.0, 0.0, 1.0, 0.0);
	DisplayZigZag();
	glPopMatrix();
    
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3f(0.0, 10.5, 0.0);
    glVertex3f(28.0, 6.5, 0.0);

    glEnd();

    glPopMatrix();
}


//////////////////////////////////////////////////////////////////////////
// pokaz rury tworzace wsporniki szczytu
//////////////////////////////////////////////////////////////////////////
void GoraZurawia::DisplayRury() 
{
	glPushMatrix();
	glTranslatef(0.0, Rura.GetHeight() / 2 + Segment.GetHeight() - 0.2, 0.0);
    glTranslatef(0.0, 2.0, 0.0);
	
	glPushMatrix();
	glTranslatef(0.5, 0.0, 0.5);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	//glRotatef(-10.0, 1.0, 0.0, 1.0);
    Rura.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0.0, 0.5);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	//glRotatef(-10.0, 1.0, 1.0, 1.0);
    Rura.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0.0, -0.5);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	Rura.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0.0, -0.5);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	Rura.Display();
	glPopMatrix();

	glPopMatrix();
}

//////////////////////////////////////////////////////////////////////////
// pokaz kratownice szczytu
//////////////////////////////////////////////////////////////////////////
void GoraZurawia::DisplayZigZag() 
{
	glPushMatrix();
	glTranslatef(0.0, Segment.GetHeight() + 0.6, 1.0);
	glRotatef(-9.0, 1.0, 0.0, 0.0);
	
	glPushMatrix();
	glTranslatef(-1.2, 0.0, 0.0);
	glRotatef(120.0, 1.0, 1.0, 1.0);                          //glRotatef(-55.0, 0.0, 0.0, 1.0);
	Rurka.SetHeight(2.4);
	Rurka.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0, 1.2, 0.0);
	glRotatef(120.0, 1.0, 1.0, 1.0);                          //glRotatef(-55.0, 0.0, 0.0, 1.0);
	Rurka.SetHeight(1.9);
	Rurka.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.8, 2.2, 0.0);
	glRotatef(120.0, 1.0, 1.0, 1.0);                          //glRotatef(-55.0, 0.0, 0.0, 1.0);
	Rurka.SetHeight(1.5);
	Rurka.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.7, 3.0, 0.0);
	glRotatef(120.0, 1.0, 1.0, 1.0);                          //glRotatef(-55.0, 0.0, 0.0, 1.0);
	Rurka.SetHeight(1.2);
	Rurka.Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6, 3.7, 0.0);
	glRotatef(120.0, 1.0, 1.0, 1.0);                          //glRotatef(-55.0, 0.0, 0.0, 1.0);
	Rurka.SetHeight(1.0);
	Rurka.Display();
	glPopMatrix();
	
	glPopMatrix();
}

/*======================================================================
                                DolZurawia
======================================================================*/
////////////////////////////////////////////////////////////////////////
// konstrukcja
////////////////////////////////////////////////////////////////////////
DolZurawia::DolZurawia(int n) : Segment(), WiezaZurawia(n) {
}

////////////////////////////////////////////////////////////////////////
// pokaz dol zurawia - podstawe, wieze z segmentow i cos pod czesci
// ruchoma (?)
// punkt odniesienia - srodek dolnej podstawy calej figury
////////////////////////////////////////////////////////////////////////
void DolZurawia::Display()  {
    const GLfloat SegmentH = Segment.GetHeight();

	/// pokaz podstawe...
	glPushMatrix();
    glTranslatef(0.0, - WiezaZurawia.GetHeight() - 3.5, 0.0);
    Podstawa.Display();
    
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -WiezaZurawia.GetHeight() + 2.4, 0.0);
    WiezaZurawia.Display();
	glPopMatrix();
    
	// pokaz lacznik
	//glTranslatef(0.0, Lacznik.GetHeight() / 2 - SegmentH / 2, 0.0);

	//Lacznik.Display();
}

/*======================================================================
                            Zuraw Wiezowy
======================================================================*/
//////////////////////////////////////////////////////////////////////////
// ctor
//////////////////////////////////////////////////////////////////////////
ZurawWiezowy::ZurawWiezowy(int segw, int segr)
: Dol(segw), Gora(segr), Wozek(), Magnes(2.0f,0.8f) {
}

//////////////////////////////////////////////////////////////////////////
// display
//////////////////////////////////////////////////////////////////////////
void ZurawWiezowy::Display()  {
	glPushMatrix();
    glRotatef( xrot, 0.0f, 1.0f, 0.0f); /* Rotate On The X Axis */
    Gora.Display();

        glPushMatrix();
        glTranslatef(4.4, 4.4, 0.0);
        glTranslatef(xpos, 0.0, 0.0);
        Wozek.Display();

            glPushMatrix();
            glBegin(GL_LINES);
            glVertex3f(0.0, 0.0, 0.0);
            glVertex3f(0.0, -10.0-ypos, 0.0);
            glEnd();       
            glPopMatrix();
        
        glTranslatef(0.0, -10.0-ypos, 0.0); 
		glRotatef( 90.0, 1.0f, .0f, .0f);
		Magnes.Display();
        
        glPopMatrix();
        
	glPopMatrix();

	glPushMatrix();
	Dol.Display();

	//glTranslatef(0.0, -2*Dol.GetHeight() - 2.0, 0.0);
	
	glPopMatrix();
}








































/*======================================================================
                                Skybox
======================================================================*/
////////////////////////////////////////////////////////////////////////
// konstrukcja skyboxa
////////////////////////////////////////////////////////////////////////
Skybox::Skybox(GLfloat r) : Radius(r) {
}

////////////////////////////////////////////////////////////////////////
// pokaz obiekt
////////////////////////////////////////////////////////////////////////    
void Skybox::Display()  {
    /* Top Face */
    /* Typical Texture Generation Using Data From The Bitmap */
    glBindTexture( GL_TEXTURE_2D, skyboxTextures[0] );
    glBegin(GL_QUADS);
        /* Top Left Of The Texture and Quad */
        glTexCoord2f( 1.0f, 1.0f ); glVertex3f( -Radius,  Radius, -Radius );
        /* Bottom Left Of The Texture and Quad */
        glTexCoord2f( 1.0f, 0.0f ); glVertex3f( -Radius,  Radius,  Radius );
        /* Bottom Right Of The Texture and Quad */
        glTexCoord2f( 0.0f, 0.0f ); glVertex3f(  Radius,  Radius,  Radius );
        /* Top Right Of The Texture and Quad */
        glTexCoord2f( 0.0f, 1.0f ); glVertex3f(  Radius,  Radius, -Radius );
    glEnd();

    /* Bottom Face */
    /* Typical Texture Generation Using Data From The Bitmap */
    glBindTexture( GL_TEXTURE_2D, skyboxTextures[1] );
    glBegin(GL_QUADS);
        /* Top Right Of The Texture and Quad */
        glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -Radius, -Radius, -Radius );
        /* Top Left Of The Texture and Quad */
        glTexCoord2f( 1.0f, 1.0f ); glVertex3f(  Radius, -Radius, -Radius );
        /* Bottom Left Of The Texture and Quad */
        glTexCoord2f( 1.0f, 0.0f ); glVertex3f(  Radius, -Radius,  Radius );
        /* Bottom Right Of The Texture and Quad */
        glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -Radius, -Radius,  Radius );
    glEnd();

    /* Front Face */
    /* Typical Texture Generation Using Data From The Bitmap */
    glBindTexture( GL_TEXTURE_2D, skyboxTextures[2] );
    glBegin(GL_QUADS);
        /* Bottom Left Of The Texture and Quad */
        glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -Radius, -Radius, Radius );
        /* Bottom Right Of The Texture and Quad */
        glTexCoord2f( 1.0f, 1.0f ); glVertex3f(  Radius, -Radius, Radius );
        /* Top Right Of The Texture and Quad */
        glTexCoord2f( 1.0f, 0.0f ); glVertex3f(  Radius,  Radius, Radius );
        /* Top Left Of The Texture and Quad */
        glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -Radius,  Radius, Radius );
    glEnd( ); 
            
    /* Back Face */
    /* Typical Texture Generation Using Data From The Bitmap */
    glBindTexture( GL_TEXTURE_2D, skyboxTextures[3] );
    glBegin(GL_QUADS);
        /* Bottom Right Of The Texture and Quad */
        glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -Radius, -Radius, -Radius );
        /* Top Right Of The Texture and Quad */
        glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -Radius,  Radius, -Radius );
        /* Top Left Of The Texture and Quad */
        glTexCoord2f( 1.0f, 1.0f ); glVertex3f(  Radius,  Radius, -Radius );
        /* Bottom Left Of The Texture and Quad */
        glTexCoord2f( 1.0f, 0.0f ); glVertex3f(  Radius, -Radius, -Radius );
    glEnd( ); 
        
    /* Left Face */
    /* Typical Texture Generation Using Data From The Bitmap */
    glBindTexture( GL_TEXTURE_2D, skyboxTextures[4] );
    glBegin(GL_QUADS);
        /* Bottom Left Of The Texture and Quad */
        glTexCoord2f( 1.0f, 0.0f ); glVertex3f( -Radius, -Radius, -Radius );
        /* Bottom Right Of The Texture and Quad */
        glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -Radius, -Radius,  Radius );
        /* Top Right Of The Texture and Quad */
        glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -Radius,  Radius,  Radius );
        /* Top Left Of The Texture and Quad */
        glTexCoord2f( 1.0f, 1.0f ); glVertex3f( -Radius,  Radius, -Radius );
    glEnd( ); 
         
    /* Right face */
    /* Typical Texture Generation Using Data From The Bitmap */
    glBindTexture( GL_TEXTURE_2D, skyboxTextures[5] );
    glBegin(GL_QUADS);
        /* Bottom Right Of The Texture and Quad */
        glTexCoord2f( 0.0f, 0.0f ); glVertex3f( Radius, -Radius, -Radius );
        /* Top Right Of The Texture and Quad */
        glTexCoord2f( 0.0f, 1.0f ); glVertex3f( Radius,  Radius, -Radius );
        /* Top Left Of The Texture and Quad */
        glTexCoord2f( 1.0f, 1.0f ); glVertex3f( Radius,  Radius,  Radius );
        /* Bottom Left Of The Texture and Quad */
        glTexCoord2f( 1.0f, 0.0f ); glVertex3f( Radius, -Radius,  Radius );
    glEnd();      
}
