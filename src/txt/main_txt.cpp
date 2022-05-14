#include <iostream>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "txtJeu.h"
#include "winTxt.h"
#include "../core/Menu.h"
#include "../core/Jeu.h"


using namespace std;

void CommencerPartie(Jeu &jeu)
{
	int personalisation;
	cout << "Commencer la personnalisation du personnage oui(1) non(0) ? " << endl;
	cin >> personalisation;
	if (personalisation == 0)
	{
		//	jeu.getTerrain().setChoixniv(1);
		termClear();
		txtBoucle(jeu);
		termClear();
	}
	else
	{
		string nomperso;
		int sexepers;
		cout << "Entrez le nom du personnage (entre 5 et 15 caractères maximum)" << endl;
		cin >> nomperso;
		if (nomperso.empty() == true || nomperso.length() <= 5 || nomperso.length() >= 15)
		{
			do
			{
				cout << "Erreur veuillez choisir un pseudo valide ! " << endl;
				cin >> nomperso;
			} while (nomperso.empty() == true || nomperso.length() <= 5 || nomperso.length() >= 15);
		}
		cout << "Selectionner le sexe du personnage Masculin(0) Feminin(1)" << endl;
		cin >> sexepers;
		if (sexepers != 0 && sexepers != 1)
		{
			do
			{
				cout << "Erreur veuillez choisir une entrée valide '0' ou '1'" << endl;
				cin >> sexepers;
				if(sexepers==1 ||sexepers ==0)break;
			} while (sexepers != 0 && sexepers != 1);
		}

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
	cout << "1 2 3 4 5 " << endl;
	cout << " choix du niveau : " << endl;
	cin>>choixniv;
	
	if(choixniv!=1 && choixniv!=2 && choixniv!=3 && choixniv!=4 && choixniv!=5){
		do{
		cout << "Veuillez saisir une entrée valide " << endl;
		cin >> choixniv;
		}while(choixniv!=1 && choixniv!=2 && choixniv!=3 && choixniv!=4 && choixniv!=5);
	}
		
		jeu.getTerrain().setChoixniv(choixniv);
  		jeu.getTerrain().loadMap("./data/Niveau" + std::to_string(jeu.getTerrain().getChoixniv()) + ".txt");
		  
		cout << "Choix du niveau pris en compte ! " <<endl;
		usleep(2000000);
	
	system("clear");
	fflush(stdout);

}

void Personnalisation(Jeu &jeu)
{
	cout << "PERSONNALISATION DU PERSONNAGE" << endl<< endl;
	cout << "1 Changer le nom du personnage" << endl;
	cout << "2 Changer le sexe du personnage" << endl << endl << endl;

	cout << "3 Retour à l'ecran titre" << endl;

	int x;
	string nomperso;
	bool sexepers;
	do
	{
		cin >> x;
		switch (x)
		{
		case 1:
		{
			system("clear");
			cout << "Entrez le nom du personnage (entre 5 et 15 caractères maximum)" << endl;
			cin >> nomperso;
			if (nomperso.empty() == true || nomperso.length() <= 5 || nomperso.length() >= 15)
			{
				do
				{
					cout << "Erreur veuillez choisir un pseudo valide ! " << endl;
					cin >> nomperso;
				} while (nomperso.empty() == true || nomperso.length() <= 5 || nomperso.length() >= 15);
			}
			jeu.getPerso().setNom(nomperso);
		}
		break;
		case 2:
		{
			system("clear");
			cout << "Selectionner le sexe du personnage Masculin(0) Feminin(1)" << endl;
			if (sexepers != 0 || sexepers != 1)
			{
				do
				{
					cout << "Erreur veuillez choisir une entrée valide '0' ou '1'" << endl;
					cin >> sexepers;
				} while (sexepers != 0 && sexepers != 1);
			}
			jeu.getPerso().setSexe(sexepers);
		}

		break;
		case 3:
			system("clear");
			break;
		case 4:
		{
			system("clear");
			int nivactuel = jeu.getTerrain().getChoixniv();
			jeu.getTerrain().setChoixniv(0);
			jeu.getTerrain().setChoixniv(nivactuel);
		}
		break;
		default:
			printf("Choix non traité par le programme\n");
		}
		fflush(stdout);
	} while (x != 3);

	//	if (x==6){ system("clear"); fflush(stdout);}
}

void Difficulte(Jeu &jeu)
{
	cout << "1. Definir le nombre de monstres" << endl;
	cout << "2. Recommencer le niveau" << endl
		 << endl
		 << endl;
	cout << "3 Retour à l'ecran titre" << endl;
	int x;
	do
	{
		cin >> x;
		switch (x)
		{
		case 1:
			system("clear");
			break;
		case 2:{
			system("clear");
			int nivactuel = jeu.getTerrain().getChoixniv();
			jeu.getTerrain().setChoixniv(0);
			jeu.getTerrain().setChoixniv(nivactuel);
			cout << "Niveau réinitialisé ! " << endl;
		}
			
			
		  		/*
		  	cout << "Appuyer sur une touche pour continuer " << endl;
			int ent; cin >>ent;
			*/
			break;
		case 3:
			system("clear");
			break;
		default:
			printf("Choix non traité par le programme\n");
		}
		fflush(stdout);
	} while (x != 3);
}

void GestionAudio(Jeu &jeu) {}

void QuitterJeu()
{
	cout << endl
		 << "Aurevoir champion !" << endl;
	exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{

	ChoixMenu cm;
	ChoixMenuOptions cmo;
	srand((unsigned int)time(NULL));
	Jeu jeu;
	bool typemenu = false;
	do
	{
		if (!typemenu)
		{

			menuAff();
			cm = menuQuestion();
			switch (cm)
			{
			case MENU_Choix1:
				system("clear");
				CommencerPartie(jeu);
				break;
			case MENU_Choix2:
				system("clear");
				ChoixDuNiveau(jeu);
				break;
			case MENU_Choix3:
				system("clear");
				typemenu = true;
				break;
			case MENU_Quit:
				system("clear");
				QuitterJeu();
				break;
			default:
				printf("Choix non traité par le programme\n");
			}
			fflush(stdout);
		}
		else
		{

			menuoAff();
			cmo = menuoQuestion();
			switch (cmo)
			{
			case MENUO_Choix1:
				system("clear");
				Personnalisation(jeu);
				break;
			case MENUO_Choix2:
				system("clear");
				Difficulte(jeu);
				break;
			case MENUO_Choix3:
				system("clear");
				GestionAudio(jeu);
				break;
			case MENUO_Choix4:
				system("clear");
				typemenu = false;
				break;
			case MENUO_Quit:
				system("clear");
				QuitterJeu();
				break;
			default:
				printf("Choix non traité par le programme\n");
			}
			fflush(stdout);
		}

	} while (cm != MENU_Quit);

	system("clear");
	return 0;
}