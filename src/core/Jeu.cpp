#include "Jeu.h"
const int VITESSE = 3;

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
		perso.deplacerVite(VITESSE, touche, ter);
		break;
	case 'd':
		perso.deplacerVite(VITESSE, touche, ter);
		break;
	case 'z':
		dsaut = tps;
		perso.deplacerVite(VITESSE, touche, ter);
		break;
	case 's':
		perso.deplacerVite(VITESSE, touche, ter);
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

	fsaut = dsaut+12;
	if(fsaut < temps)
	{
		gravite();
	}
	gravite();
	//monst.bougeAutoMonstre(ter);
}

void Jeu::gravite()
{
	perso.deplacerVite(VITESSE, 's', ter);
}

int Jeu::getTemps()
{
	return temps;
}
