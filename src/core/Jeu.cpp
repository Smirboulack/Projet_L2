#include "Jeu.h"


Jeu::Jeu () : ter(), perso() , monst(){
}




Terrain& Jeu::getTerrain () { return ter; }

Personnage& Jeu::getPerso () {	return perso; }

const Terrain& Jeu::getConstTerrain () const { return ter; }

const Personnage& Jeu::getConstPersonnage () const { return perso; }

 const Monstre& Jeu::getConstMonstre () const { return monst; }

//int Jeu::getNombreMonstre() const { return 1; }



bool Jeu::actionClavier (const char touche) {
	switch(touche) {
		case 'q' :
				perso.deplacer(touche);
				break;
		case 'd' :
				perso.deplacer(touche);
				break;
		case 'z' :
				perso.deplacer(touche);
				break;
		case 's' :
				perso.deplacer(touche);
				break;
	}
	/*
	if (ter.getXY(perso.getX(),perso.getY())=='.') {
	    ter.mangePastille(perso.getX(),perso.getY());
        return true;
	}*/
	return false;
}

void Jeu::actionsAutomatiques () {
    //fan.verspersoman(ter,perso);
  //  monstre.bougeAuto(ter);
}

