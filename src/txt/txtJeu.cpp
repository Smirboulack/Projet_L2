#include <iostream>
//#ifdef _WIN32
//#include <windows.h>
//#else
#include <unistd.h>
//#endif // WIN32
#include "winTxt.h"
#include "../core/Jeu.h"
#include "txtJeu.h"

#define LEN 10

using namespace std;


void txtAff(WinTXT & win, Jeu & jeu) {
	const Terrain& ter = jeu.getConstTerrain();
	const Personnage& perso = jeu.getConstPersonnage();
	const Monstre& monst = jeu.getConstMonstre();

	char * nom = new char [LEN];
	char * vie = new char [LEN];
	char * armure = new char[LEN];
	char * degat = new char[LEN];
	char * piece = new char[LEN];
	char * portee = new char[LEN];
	char * persox = new char[LEN];
	char * persoy = new char[LEN];

	string n = jeu.getPerso().getNom();
	strcpy(nom,n.c_str());
	string v = to_string(jeu.getPerso().getVie());
	strcpy(vie,v.c_str());
	string a = to_string(jeu.getPerso().getArmure());
	strcpy(armure,a.c_str());
	string deg = to_string(jeu.getPerso().getDegat());
	strcpy(degat,deg.c_str());
	string coin = to_string(jeu.getPerso().getPiece());
	strcpy(piece,coin.c_str());
	string rg = to_string(jeu.getPerso().getPortee());
	strcpy(portee,rg.c_str());
	string persx = to_string(jeu.getPerso().getX());
	strcpy(persox,persx.c_str());
	string persy = to_string(jeu.getPerso().getY());
	strcpy(persoy,persy.c_str());

	win.clear();

    // Affichage des murs et des plateformes
	for(int x=0;x<ter.getDimX();++x)
		for(int y=0;y<ter.getDimY();++y)
			win.print(x,y,ter.getXY(x,y));

    // Affichage du personnage
	win.print(perso.getX(),perso.getY(),'P');
	// Affichage du Monstre
	win.print(monst.getX(),monst.getY(),'M');

	win.print(9,0,nom);
	win.print(22,0, vie);
	win.print(32,0, armure);
	win.print(42,0, degat);
	win.print(52,0, portee);
	win.print(61,0, piece);
	win.print(83,0,persox);
	win.print(88,0,persoy);

	win.draw();
}


void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getConstTerrain().getDimX(),jeu.getConstTerrain().getDimY());

	bool ok = true;
	char c;

	do {
	    txtAff(win,jeu);
		 cout<<jeu.getPerso().getVie();

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		c = win.getCh();


		jeu.actionsAutomatiques();
        jeu.actionClavier(c,jeu.getTemps());
		jeu.ramasserItems();


		if(c=='x') ok = false;
	} while (ok);

}
