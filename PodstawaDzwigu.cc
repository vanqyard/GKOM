#include "SceneObjects.h"

////////////////////////////////////////////////////////////////////////
// Konstruje podstawe zurawia, zgodnie z jej rozmiarami
////////////////////////////////////////////////////////////////////////
PodstawaDzwigu::PodstawaDzwigu()
: Nozka(1.33, 0.60), Podloga(0.48, 10.7, 10.7), Ciezar(2.1, 6.34, 4.07),
Podpora(7.4, 0.31)
{
	//Podpora.SetColor(Zolty[0], Zolty[1], Zolty[2], 1.0);
	//Podloga.SetColor(Zolty[0], Zolty[1], Zolty[2], 1.0);
	//Nozka.SetColor(0.4, 0.4, 0.4, 1.0);
	//Ciezar.SetTexture(pTexCiezar1->GetName());
}

////////////////////////////////////////////////////////////////////////
// Buduje Podstawe Wiezy pamięci na stosie
////////////////////////////////////////////////////////////////////////
void PodstawaDzwigu::Build() {
	Segment.Build();
	Nozka.Build();
	Podloga.Build();
	Ciezar.Build();
	Podpora.Build();
}

////////////////////////////////////////////////////////////////////////
// Renderuje obiekt - pokazuje podstawe wiezy
////////////////////////////////////////////////////////////////////////
void PodstawaDzwigu::Display()
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
// Nozki podstawy
////////////////////////////////////////////////////////////////////////
void PodstawaDzwigu::DisplayNozki()
{
	const GLfloat halfH = Nozka.GetHeight() / 2;

	// lewa przednia
	glPushMatrix();
	glTranslatef(-5.0, halfH, -5.0);

	Nozka.Display();

	glPopMatrix();

	// prawa przednia
	glPushMatrix();
	glTranslatef(5.0, halfH, -5.0);

	Nozka.Display();

	glPopMatrix();

	// lewa tylna
	glPushMatrix();
	glTranslatef(-5.0, halfH, 5.0);

	Nozka.Display();

	glPopMatrix();

	// prawa tylna
	glPushMatrix();
	glTranslatef(5.0, halfH, 5.0);

	Nozka.Display();

	glPopMatrix();
}

////////////////////////////////////////////////////////////////////////
// Pokazuje jeden z 4 ciezarow
////////////////////////////////////////////////////////////////////////
void PodstawaDzwigu::DisplayCiezary()
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
void PodstawaDzwigu::DisplayPodpory()
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

GLuint PodstawaDzwigu::GetTexture(std::string Filename)
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
