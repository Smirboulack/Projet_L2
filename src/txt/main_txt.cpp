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
	int personalisation;
	cout << "Commencer la personnalisation du personnage oui(1) non(0) ? " << endl;
	cin >> personalisation;
	if(personalisation==0){
	//	jeu.getTerrain().setChoixniv(1);
		termClear();
		txtBoucle(jeu);
   		termClear();
	}else{
		string nomperso;
		bool sexepers;
		cout << "Entrez le nom du personnage" << endl;
    	cin >> nomperso;
		cout << "Selectionner le sexe du personnage Masculin(0) Feminin(1)" << endl;
		do{cin>>sexepers;}while(sexepers!=0 && sexepers!=1);
	   	jeu.getPerso().setNom(nomperso);
		jeu.getPerso().setSexe(sexepers);

		termClear();
		txtBoucle(jeu);
   		termClear();

	}
    
}

void ChoixDuNiveau(Jeu &jeu)
{
    int choixniv;
    cout << "Veuillez choisir le niveau parmis les 5 niveaux disponible " << endl;
	cout << " choix du niveau : ";cin >> choixniv; cout << endl;
    jeu.getTerrain().setChoixniv(choixniv);


	int personalisation;
	cout << "Commencer la personnalisation du personnage oui(1) non(0) ? " << endl;
	cin >> personalisation;

	if(personalisation==0){
		termClear();
		txtBoucle(jeu);
   		termClear();
	}else{
		string nomperso;
		bool sexepers;
		cout << "Entrez le nom du personnage" << endl;
    	cin >> nomperso;
		cout << "Selectionner le sexe du personnage Masculin(0) Feminin(1)" << endl;
		do{cin>>sexepers;}while(sexepers!=0 && sexepers!=1);
	   	jeu.getPerso().setNom(nomperso);
		jeu.getPerso().setSexe(sexepers);
		termClear();
		txtBoucle(jeu);
   		termClear();

	}
}

void Parametrage(Jeu &jeu){
	cout << "Quitter paramètrages (0) ? "  << endl;
	int p;
	cin>>p;
	if(p==0){fflush(stdout);}

}

void QuitterJeu()
{	
	cout << endl << "Aurevoir champion !" << endl; 
	exit(EXIT_SUCCESS);
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
			case MENU_Choix2 : ChoixDuNiveau(jeu); break;
			case MENU_Choix3 : Parametrage(jeu); break;
			case MENU_Quit: QuitterJeu(); break;
			default: printf("Choix non traité par le programme\n");
		}
		fflush(stdout);
	} while(cm!=MENU_Quit);
	

	return 0;
}