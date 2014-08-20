#include "SceneObjects.h"

////////////////////////////////////////////////////////////////////////
// Konstruktor segmentu wiezy - tworzy elementy skladowe o wymiarach
// odpowiadajacych rzeczywistym
////////////////////////////////////////////////////////////////////////
SegmentWiezy::SegmentWiezy()
: ElemPionowy(6.28, 0.31), ElemPoziomy(2.05, 0.2), ElemUkosny(2.52, 0.2)
{
	//ElemPoziomy.SetColor(Zolty[0], Zolty[1], Zolty[2], 1.0);
	//ElemUkosny.SetColor(Zolty[0], Zolty[1], Zolty[2], 1.0);
}

////////////////////////////////////////////////////////////////////////
// Buduje SegmentWiezy w pamięci na stosie
////////////////////////////////////////////////////////////////////////
void SegmentWiezy::Build()
{
	ElemPionowy.Build();
	ElemPoziomy.Build();
	ElemUkosny.Build();
}

////////////////////////////////////////////////////////////////////////
// Pokaz segment wiezy - pozycjonuje wszystko zgodnie z rzeczywistymi
// rozmiarami, punkt odniesienia w geometrycznym srodku segmentu
////////////////////////////////////////////////////////////////////////
void SegmentWiezy::Display()
{
	/// pionowe wsporniki
	DisplayPionowe();

	/// dolne poziome
	glPushMatrix();
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
// Pokazuje poziome wsporniki
////////////////////////////////////////////////////////////////////////
void SegmentWiezy::DisplayPionowe()
{
	//glBindTexture(GL_TEXTURE_2D, pTexWspornik->GetName());

	// lewy przedni
	glPushMatrix();
	glTranslatef(-1.07, 0.0, 1.07);
	glRotatef(-90.0, 0.0, 1.0, 0.0);

	ElemPionowy.Display();

	glPopMatrix();

	// prawy przedni
	glPushMatrix();
	glTranslatef(1.07, 0.0, 1.07);

	ElemPionowy.Display();

	glPopMatrix();

	// lewy tylny
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
// Pokazuje poziome wsporniki jednego poziomu
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
// Pokaz ukosne jednej sciany
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

GLuint SegmentWiezy::GetTexture(std::string Filename)
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
				//| SOIL_FLAG_INVERT_Y
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
