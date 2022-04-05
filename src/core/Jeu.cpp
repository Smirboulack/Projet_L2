#include "Jeu.h"

Jeu::Jeu() : ter(), perso(), monst(), itemss()
{
	temps = 0;
}

Terrain &Jeu::getTerrain() { return ter; }

Personnage &Jeu::getPerso() { return perso; }

const Terrain &Jeu::getConstTerrain() const { return ter; }

const Personnage &Jeu::getConstPersonnage() const { return perso; }

const Monstre &Jeu::getConstMonstre() const { return monst; }

const Items &Jeu::getConstItems() const { return itemss; }

//int Jeu::getNombreMonstre() const { return 1; }

bool Jeu::actionClavier(const int touche, int tps)
{
	switch (touche)
	{
	case 'q':
		perso.deplacer(touche, ter);
		break;
	case 'd':
		perso.deplacer(touche, ter);
		break;
	case 'z':
		dsaut = tps;
		perso.deplacer(touche, ter);
		break;
	case 's':
		perso.deplacer(touche, ter);
		break;
	}
	/*
	if (ter.getXY(perso.getX(),perso.getY())=='.') {
	    ter.mangePastille(perso.getX(),perso.getY());
        return true;
	}*/



	return false;
}

void Jeu::actionsAutomatiques()
{
	//fan.verspersoman(ter,perso);
	//monstre.bougeAuto(ter);
	temps++;

	fsaut = dsaut+2;
	if(fsaut < temps)
	{
		gravite();
	}
	monst.bougeAutoMonstre(ter);
}

void Jeu::gravite()
{
	perso.deplacer('s', ter);
}

int Jeu::getTemps()
{
	return temps;
}
