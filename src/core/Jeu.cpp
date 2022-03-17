#include "Jeu.h"

/*
Jeu::Jeu () : ter(), pac(), fan() {
	ter.mangePastille(pac.getX(),pac.getY());
}

*/

void Menu::truc1()
{
	printf("truc1\n");
	fflush(stdout);
}

void Menu::truc2()
{
	printf("truc2\n");
	fflush(stdout);
}

void Menu::truc3()
{
	printf("truc3\n");
	fflush(stdout);
}

void Menu::truc4()
{
	printf("truc4\n");
	fflush(stdout);
}


void Jeu::genereMenu () {

    ChoixMenu cm;
    do{
        menuAff ();
        menuAff();
		cm = menuQuestion();
		switch(cm)
		{
			case MENU_Choix1 : truc1(); break;
			case MENU_Choix2 : truc2(); break;
			case MENU_Choix3 : truc3(); break;
			case MENU_Choix4 : truc4(); break;
			case MENU_Quit: break;
			default: printf("Choix non traité par le programme\n");
		}
		fflush(stdout);

    }while(cm!=MENU_Quit);

}

Terrain& Jeu::getTerrain () { return ter; }

Personnage& Jeu::getPerso () {	return pac; }

const Terrain& Jeu::getConstTerrain () const { return ter; }

const Personnage& Jeu::getConstPersonnage () const { return pac; }

// const Monstre& Jeu::getConstFantome () const { return fan; }

int Jeu::getNombreMonstre() const { return 1; }

/*

bool Jeu::actionClavier (const char touche) {
	switch(touche) {
		case 'g' :
				pac.gauche(ter);
				break;
		case 'd' :
				pac.droite(ter);
				break;
		case 'h' :
				pac.haut(ter);
				break;
		case 'b' :
				pac.bas(ter);
				break;
	}
	if (ter.getXY(pac.getX(),pac.getY())=='.') {
	    ter.mangePastille(pac.getX(),pac.getY());
        return true;
	}
	return false;
}

void Jeu::actionsAutomatiques () {
    //fan.versPacman(ter,pac);
    fan.bougeAuto(ter);
}
*/