#include <cstdio>
#include "Menu.h"

#include <iostream>

const int MENU_MAX = 5;

void menuAff()
{

std::cout<<"****************************************************"<<std::endl;
std::cout<<"*                                                  *"<<std::endl;
std::cout<<"*           BIENVENUE DANS ULTIMATE-LIKFAS         *"<<std::endl;
std::cout<<"*                      ****                        *"<<std::endl;
std::cout<<"*                      ****                        *"<<std::endl;
std::cout<<"*                    ********                      *"<<std::endl;
std::cout<<"*                    * MENU *                      *"<<std::endl;
std::cout<<"*                    ********                      *"<<std::endl;
std::cout<<"*                                                  *"<<std::endl;
std::cout<<"****************************************************"<<std::endl;


	
	printf("\nMenu\n");
	printf("1 : Commencer la partie\n");
	printf("2 : Choix du niveau\n");
	printf("3 : Paramètres\n");
	printf("4 : Quitter le jeu\n");
	printf("Votre choix?\n");
	fflush(stdout);
}

ChoixMenu menuQuestion()
{
	ChoixMenu cm;
	int i;
	char dum[32];
	bool ok=false;
	do
	{
		if (scanf("%d",&i)!=1) scanf("%s",dum);
		cm=((ChoixMenu)(i));
		if ((cm<0) || (cm>=MENU_MAX)) 
			printf("Erreur choix menu\n");
		else ok=true;
		fflush(stdout);
	} while(!ok);
	printf("\n"); fflush(stdout);
	return cm;
}

