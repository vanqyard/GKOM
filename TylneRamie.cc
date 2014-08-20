#include "SceneObjects.h"

TylneRamie::TylneRamie()
: GlownyWspornik(0.8, 13.22, 0.4), UkosnyWspornik(0.5, 1.7, 0.3), KoncowyWspornik(0.8, 8.3, 0.4),
Poprzeczny(0.9, 0.8, 2.5), Ciezar(3.2, 3.0, 1.65), Tyl(0.8, 3.0, 1.65), Tablica(1.0, 5.0, 0.05)
{}

void TylneRamie::Build()
{
	GlownyWspornik.Build();
	UkosnyWspornik.Build();
	KoncowyWspornik.Build();
	Poprzeczny.Build();
	Ciezar.Build();
	Tyl.Build();
	Tablica.Build();
}

void TylneRamie::Display()
{
	/// glowne wsporniki
	glPushMatrix();
	glTranslatef(GlownyWspornik.GetWidth() / 2.0, GlownyWspornik.GetHeight() / 2.0, 0.0);

	/// 1. wpornik
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.685);

	GlownyWspornik.Display();

	glPopMatrix();

	/// 2. wpornik
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

	glTranslatef(GlownyWspornik.GetWidth() / 2.0, 0.0, 0.0);

	Poprzeczny.Display();

	glTranslatef(KoncowyWspornik.GetWidth() / 2.0, 0.0, 0.0);

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

	glPushMatrix();
	glTranslatef(0.0, 0.7, 0.0);
	glRotatef(90.0, 0.0, 0.0, 1.0);

	//Walec1.Display();

	glPopMatrix();


	glTranslatef(1.0, 0.9, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);

	//Walec1.Display();


	glPopMatrix();
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
}
