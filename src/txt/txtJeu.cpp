#include <iostream>
//#ifdef _WIN32
//#include <windows.h>
//#else
#include <unistd.h>
//#endif // WIN32
#include "winTxt.h"
#include "../core/Jeu.h"

using namespace std;


void txtAff(WinTXT & win, Jeu & jeu) {
	const Terrain& ter = jeu.getConstTerrain();
	const Personnage& perso = jeu.getConstPersonnage();
	const Monstre& monst = jeu.getConstMonstre();
	const Items& items = jeu.getConstItems();

	win.clear();

    // Affichage des murs et des plateformes
	for(int x=0;x<ter.getDimX();++x)
		for(int y=0;y<ter.getDimY();++y)
			win.print(x,y,ter.getXY(x,y));

    // Affichage du personnage
	win.print(perso.getX(),perso.getY(),'P');
	// Affichage du Monstre
	win.print(monst.getX(),monst.getY(),'M');
	// Affichage des items
	for (unsigned int i=0;i<items.getnbitems();i++){
		/*
		win.print(items.getarmex(),items.getarmey(),items.getchararme());
		win.print(items.getpiecex(),items.getpiecey(),items.getcharpiece());
		win.print(items.getarmurex(),items.getarmurey(),items.getchararmure());
		win.print(items.getviex(),items.getviey(),items.getcharvie());
		*/
		win.print(items.getarmex(),items.getarmey(),items.getchararme());
		win.print(items.getpiecex(),items.getpiecey(),items.getcharpiece());
		win.print(items.getarmurex(),items.getarmurey(),items.getchararmure());
		win.print(items.getviex(),items.getviey(),items.getcharvie());
	}
	

	win.draw();
}


void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getConstTerrain().getDimX(),jeu.getConstTerrain().getDimY());

	bool ok = true;
	const Items& items = jeu.getConstItems();
	unsigned int nombre=items.getnbitems();
	char c;

	do {
	    txtAff(win,jeu);
		 cout <<nombre;

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		c = win.getCh();

		
		jeu.actionsAutomatiques(c);
        
        jeu.actionClavier(c,jeu.getTemps());


		if(c=='x') ok = false;
	} while (ok);

}