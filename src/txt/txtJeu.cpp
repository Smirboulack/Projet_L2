#include <iostream>
//#ifdef _WIN32
//#include <windows.h>
//#else
#include <unistd.h>
//#endif // WIN32
#include "winTxt.h"
#include "../core/Jeu.h"


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
	win.print(items.getarmex(),items.getarmey(),items.getchararme());
	win.print(items.getpiecex(),items.getpiecey(),items.getcharpiece());
	win.print(items.getarmurex(),items.getarmurey(),items.getchararmure());
	win.print(items.getviex(),items.getviey(),items.getcharvie());

	win.draw();
}


void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getConstTerrain().getDimX(),jeu.getConstTerrain().getDimY());

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		jeu.actionsAutomatiques();

		c = win.getCh();
        
        switch (c) {
			case 'z':
				jeu.getPerso().deplacer('z',jeu.getConstTerrain());
				break;
			case 'q':
				jeu.getPerso().deplacer('q',jeu.getConstTerrain());
				break;
			case 's':
				jeu.getPerso().deplacer('s',jeu.getConstTerrain());
				break;
			case 'd':
				jeu.getPerso().deplacer('d',jeu.getConstTerrain());
				break;
			case 'x':
				ok = false;
				break;
		}

	} while (ok);

}