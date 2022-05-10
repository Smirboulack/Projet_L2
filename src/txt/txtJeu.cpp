#include <iostream>
#include <cstring>
//#ifdef _WIN32
//#include <windows.h>
//#else
#include <unistd.h>
//#endif // WIN32
#include "winTxt.h"
#include "txtJeu.h"

#define LEN 40

using namespace std;

void txtAff(WinTXT &win, Jeu &jeu)	
{
	 Terrain& ter = jeu.getTerrain();
	 Personnage& perso = jeu.getPerso();	 
	 Personnage& monst = jeu.getMonstre();
	 /*
	 const Terrain& tero = jeu.getConstTerrain();
	 const Personnage& perso2 = jeu.getConstPersonnage();
	 const Monstre& monsto = jeu.getConstMonstre();
	 */

	char *nom = new char[LEN];
	char *vie = new char[LEN];
	char *armure = new char[LEN];
	char *degat = new char[LEN];
	char *piece = new char[LEN];
	char *portee = new char[LEN];
	char *persox = new char[LEN];
	char *persoy = new char[LEN];

	string n = jeu.getPerso().getNom();
	strcpy(nom, n.c_str());
	string v = to_string(jeu.getPerso().getVie());
	strcpy(vie, v.c_str());
	string a = to_string(jeu.getPerso().getArmure());
	strcpy(armure, a.c_str());
	string deg = to_string(jeu.getPerso().getDegat());
	strcpy(degat, deg.c_str());
	string coin = to_string(jeu.getPerso().getPiece());
	strcpy(piece, coin.c_str());
	string rg = to_string(jeu.getPerso().getPortee());
	strcpy(portee, rg.c_str());
	string persx = to_string(jeu.getPerso().getX());
	strcpy(persox, persx.c_str());
	string persy = to_string(jeu.getPerso().getY());
	strcpy(persoy, persy.c_str());
	
	

	win.clear();

	int xp,xd=0;
	if(perso.getX()>20){xp = perso.getX()-20;}else{xp=0;}
	xd = perso.getX()+25;
	if(xp == perso.getX()+1) {xp = xp++;} 

	 // Affichage des murs,des plateformes et des monstres selon le champ de vision du personnage
	if(xd){

		for(int x=xp;x<xd;++x)
		for(int y=0;y<ter.getDimY();++y)
		win.print(x,y,ter.getXY(x,y));
		if(monst.getX()<=xd && monst.getX()>=xp){
		win.print(monst.getX(),monst.getY(),'M');
		}
	}else{
		for(int x=0;x<ter.getDimX()/2;++x)
		for(int y=0;y<ter.getDimY();++y)
		win.print(x,y,ter.getXY(x,y));
		win.print(monst.getX(),monst.getY(),'M');
	}

	cout <<endl << endl<< "Appuyez sur X pour quitter et retourner au menu" << endl;
	cout <<endl << endl<< jeu.getTerrain().getChoixniv() << endl;
	
    // Affichage du personnage
	win.print(perso.getX(),perso.getY(),'P');

	win.print(9, 0, nom);
	win.print(22, 0, vie);
	win.print(32, 0, armure);
	win.print(42, 0, degat);
	win.print(52, 0, portee);
	win.print(61, 0, piece);
	win.print(83, 0, persox);
	win.print(88, 0, persoy);

	win.draw();
}

void AffFin(WinTXT &win, Jeu &jeu)
{
	/*
	const Terrain &ter = jeu.getConstTerrain();
	const Personnage &perso = jeu.getConstPersonnage();
	const Monstre &monst = jeu.getConstMonstre();
	*/

	char m[]  = "Félicitations !!! Vous avez terminé le niveau !";
	char m2[]  = "Appuyez sur ENTREE touche pour terminer";
	/*char *vie = new char[LEN];
	char *armure = new char[LEN];
	char *degat = new char[LEN];
	char *piece = new char[LEN];
	char *portee = new char[LEN];
	char *persox = new char[LEN];
	char *persoy = new char[LEN];*/
	string msg = "Félicitations !!! Vous avez terminé le niveau !";
	string msg2 = "Appuyez sur ENTREE touche pour terminer";
	

	/*string n = jeu.getPerso().getNom();
	strcpy(nom, n.c_str());
	string v = to_string(jeu.getPerso().getVie());
	strcpy(vie, v.c_str());
	string a = to_string(jeu.getPerso().getArmure());
	strcpy(armure, a.c_str());
	string deg = to_string(jeu.getPerso().getDegat());
	strcpy(degat, deg.c_str());
	string coin = to_string(jeu.getPerso().getPiece());
	strcpy(piece, coin.c_str());
	string rg = to_string(jeu.getPerso().getPortee());
	strcpy(portee, rg.c_str());
	string persx = to_string(jeu.getPerso().getX());
	strcpy(persox, persx.c_str());
	string persy = to_string(jeu.getPerso().getY());
	strcpy(persoy, persy.c_str());*/

	/*strcpy(m, msg.c_str());
	strcpy(m2,msg2.c_str());*/
	

	char c;

	do
	{
		win.clear();
		c = win.getCh();

		win.print(0, 0, m);
		win.print(0, 2, m2);

		win.draw();
		
	}while(c != 13);

	exit(EXIT_SUCCESS);
}

void txtBoucle(Jeu &jeu)
{
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
	WinTXT win(jeu.getConstTerrain().getDimX(), jeu.getConstTerrain().getDimY());

	
	char c;

	do
	{
		txtAff(win, jeu);
		//cout << jeu.getPerso().getVie();
		//cout << jeu.getTerrain().getChoixniv() << endl;

		#ifdef _WIN32
		Sleep(100);
		#else
		usleep(100000);
		#endif // WIN32


		c = win.getCh();

		jeu.actionsAutomatiques();
		jeu.actionClavier(c);
		jeu.ramasserItems();
		jeu.FinDuJeu();

		if(jeu.getFdj()) AffFin(win, jeu);

		if (c == 'x') jeu.setFdj(true);
	} while (!jeu.getFdj());
}
