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
	 Terrain terconst = jeu.getConstTerrain();
	 Personnage& perso = jeu.getPerso();
	 
	 Personnage Tmonst[18];
	 for (int i=0;i<NbMonstre;i++){ Tmonst[i] = jeu.getConstMonstre(i);}

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
		for(int i=0;i<NbMonstre;i++){
			if(Tmonst[i].getX()<=xd && Tmonst[i].getX()>=xp){
		win.print(Tmonst[i].getX(),Tmonst[i].getY(),'M');
		}
		}

	}else{
		for(int x=0;x<ter.getDimX()/2;++x)
		for(int y=0;y<ter.getDimY();++y)
		win.print(x,y,ter.getXY(x,y));
		for(int i=0;i<NbMonstre;i++){win.print(Tmonst[i].getX(),Tmonst[i].getY(),'M');}

	}

	cout << endl << endl<<"PSEUDO: "<<perso.getNom()<<" Vie:"<<perso.getVie()<<" Armure:"
	<<perso.getArmure()<<" Degats:"<<perso.getDegat()<<" Portee:"<<perso.getPortee()<<" Piece:"<<perso.getPiece()
	<<" positionPerso: {x:"<<perso.getX()<<",y:"<<perso.getY()<<"}"<< endl;

	cout <<endl<< "Appuyez sur X pour quitter et retourner au menu" << endl;
	//cout <<endl << endl<< jeu.getTerrain().getChoixniv() << endl;


    // Affichage du personnage
	win.print(perso.getX(),perso.getY(),'P');

	win.draw();
}

void AffFin(WinTXT &win, Jeu &jeu)
{


	char m[]  = "Félicitations !!! Vous avez terminé le niveau !";
	char m2[]  = "Appuyez sur ENTREE touche pour terminer";

	string msg = "Félicitations !!! Vous avez terminé le niveau !";
	string msg2 = "Appuyez sur ENTREE touche pour terminer";

	char c;

	do
	{
		win.clear();
		c = win.getCh();

		win.print(0, 0, m);
		win.print(0, 2, m2);

		win.draw();

	}while(c != 13);

	system("clear");
	exit(EXIT_SUCCESS);
}

void txtBoucle(Jeu &jeu)
{
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
	WinTXT win(jeu.getConstTerrain().getDimX(), jeu.getConstTerrain().getDimY());
	jeu.initMonstre();

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

		//if(jeu.getFdj()) AffFin(win, jeu);

		if (c == 'x') {
			jeu.setFdj(true);
			//fflush(stdout);
			}

	} while (!jeu.getFdj());

}
