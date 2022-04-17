#include "winTxt.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "txtJeu.h"
#include "../core/Jeu.h"
#include "../core/Menu.h"

using namespace std;

void CommencerPartie(Jeu &jeu)
{
    string nomperso;
	cout << "Entrez le nom du personnage" << endl;
    cin >> nomperso;
    jeu.getPerso().setNom(nomperso);

    termClear();
	txtBoucle(jeu);
    termClear();
}

void ChoixDuNiveau()
{
    int choixniv;
    cout << "Veuillez choisir le niveau parmis les 5 niveaux disponible " << endl;
    cin >> choixniv; cout << endl;
	fflush(stdout);
}

void QuitterJeu()
{
	exit(EXIT_SUCCESS);
}

void truc4()
{
	printf("truc4\n");
	fflush(stdout);
}


int main ( int argc, char** argv ) {

    ChoixMenu cm;
    srand((unsigned int)time(NULL));
    Jeu jeu;
	do
	{
		menuAff();
		cm = menuQuestion();
		switch(cm)
		{
			case MENU_Choix1 : CommencerPartie(jeu); break;
			case MENU_Choix2 : ChoixDuNiveau(); break;
			case MENU_Quit: QuitterJeu(); break;
			default: printf("Choix non traité par le programme\n");
		}
		fflush(stdout);
	} while(cm!=MENU_Quit);

    
    
    
	return 0;
}