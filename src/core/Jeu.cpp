#include "Jeu.h"
#include <ctime>
#include <iostream>
#include <assert.h>

using namespace std;

const int VITESSE = 1;


Jeu::Jeu() : ter(), perso(), monst(360,180,20,20,20,"Monstre")
{
/*
	monstre1x = 29  ; monstre1y= 11 0
monstre2x = 40  ; monstre2y= 11	 1
monstre3x = 5  ; monstre3y= 11	2
monstre4x = 44  ; monstre4y= 16  3
monstre5x = 65  ; monstre5y= 16  4
monstre6x = 19  ; monstre6y= 16  5
monstre7x = 86  ; monstre7y= 16  6
monstre8x = 71  ; monstre8y= 14  7
monstre9x = 54  ; monstre9y= 11  8
monstre10x =  75 ; monstre10y= 11 */

		tabmonstre[0].setX(0 * TAILLE_SPRITE);
		tabmonstre[0].setY(14 * TAILLE_SPRITE);
		tabmonstre[1].setX(40 * TAILLE_SPRITE);
		tabmonstre[1].setY(10 * TAILLE_SPRITE);
		tabmonstre[2].setX(5 * TAILLE_SPRITE);
		tabmonstre[2].setY(10 * TAILLE_SPRITE);
		tabmonstre[3].setX(44 * TAILLE_SPRITE);
		tabmonstre[3].setY(15 * TAILLE_SPRITE);
		tabmonstre[4].setX(44 * TAILLE_SPRITE);
		tabmonstre[4].setY(15 * TAILLE_SPRITE);
		tabmonstre[5].setX(65 * TAILLE_SPRITE);
		tabmonstre[5].setY(15 * TAILLE_SPRITE);
		tabmonstre[6].setX(19 * TAILLE_SPRITE);
		tabmonstre[6].setY(15 * TAILLE_SPRITE);
		tabmonstre[7].setX(83 * TAILLE_SPRITE);
		tabmonstre[7].setY(15 * TAILLE_SPRITE);
		tabmonstre[8].setX(71 * TAILLE_SPRITE);
		tabmonstre[8].setY(13 * TAILLE_SPRITE);
		tabmonstre[9].setX(54 * TAILLE_SPRITE);
		tabmonstre[9].setY(10 * TAILLE_SPRITE);

	ter.ouvrir("./data/Niveau12.txt");

	setFdj(false);
	setVictoire(false);


}

Terrain &Jeu::getTerrain() { return ter; }

Personnage &Jeu::getPerso() { return perso; }

Personnage &Jeu::getMonstre() { return monst; }

Personnage &Jeu::getMonstre(const int &i) {return tabmonstre[i];}

const Terrain &Jeu::getConstTerrain() const { return ter; }

const Personnage &Jeu::getConstPersonnage() const { return perso; }

const Personnage &Jeu::getConstMonstre() const { return monst; }

const Personnage &Jeu::getConstMonstre(const int &i)const{return tabmonstre[i];}

bool Jeu::actionClavier(const int touche)
{
	switch (touche)
	{
	case 'q':
		perso.deplacerVite(VITESSE, touche, ter);
		break;
	case 'd':
		perso.deplacerVite(VITESSE, touche, ter);
		break;
	case 'z':
		perso.sauter(ter);
		break;
	case 's':
		perso.deplacerVite(VITESSE, touche, ter);
		break;
	case 'v':
	cout<<"V appuyé"<<endl;
		attaquer();
		break;
	}


	/*
	if (ter.getXY(perso.getX(),perso.getY())=='.') {
	    ter.mangePastille(perso.getX(),perso.getY());
        return true;
	}*/



	return false;
}

bool Jeu::actionClavier(){
		ter.setVersion(1);
		if(ter.getVersion()==1){
		int x,y;
		//if(perso.getNom() == "mario") 
		//if(perso.getNom() == "mario") 
		x = perso.getX() + TAILLE_SPRITE/2;
		y =  perso.getY() + TAILLE_SPRITE/2;
		int xtMin = x/TAILLE_SPRITE;
		int ytMin = y/TAILLE_SPRITE;
		
		
		//if(ter.getXY(xtMin, ytMin) == '!'){return true;}
		//if(ter.getXY(xtMin, ytMin) == 'O'){return true;}
		//if(ter.getXY(xtMin, ytMin) == '+'){return true;}
		if(ter.getXY(xtMin, ytMin) == '$'){return true;}
		else{
			return false;
		}
}
}

void Jeu::attaquer()
{
	for(int i=0; i<10; i++)
	{
		if ( (getPerso().getX() - getMonstre(i).getX()  <= 70 && getPerso().getX() - getMonstre(i).getX() >= 0 &&
			 ((getPerso().getY() - getMonstre(i).getY()  <= 0  && getPerso().getY() - getMonstre(i).getY()  >= -70) ||
			  getPerso().getY() - getMonstre(i).getY()  >= 0  && getPerso().getY() - getMonstre(i).getY()  <= 70)) ||
			 (getPerso().getX() - getMonstre(i).getX()  <= 0  && getPerso().getX() - getMonstre(i).getX() >= -70 &&
			 ((getPerso().getY() - getMonstre(i).getY()  <= 0  && getPerso().getY() - getMonstre(i).getY()  >= -70) ||
			  getPerso().getY() - getMonstre(i).getY()  >= 0  && getPerso().getY() - getMonstre(i).getY()  <= 70))
			 )
		  {
			  cout<<"##############################################################"<<endl;
			  getMonstre(i).setMort(true);
		  }
	}
}

void Jeu::actionsAutomatiques()
{

	gravite();
	monst.bougeAutoMonstre(ter);
	for (int i=0;i<10;i++){tabmonstre[i].bougeAutoMonstre(ter);}
	PersoSubirDegat();
	ramasserItems();
	FinDuJeu();
}

void Jeu::gravite()
{
	perso.gravite(ter);
	for(int i = 0; i < 10;i++){
		tabmonstre[i].gravite(ter);
	}
}

void Jeu::ramasserItems(){

	if(ter.getVersion()==1){
		int x,y;
		if(perso.getNom() == "mario") x = perso.getX() + TAILLE_SPRITE/2;
		if(perso.getNom() == "mario") y =  perso.getY() + TAILLE_SPRITE/2;
		int xtMin = x/TAILLE_SPRITE;
		int ytMin = y/TAILLE_SPRITE;
		/*cout << "x : " << xtMin << endl;
		cout << "y : " << ytMin << endl;
		cout << "terXY : " << ter.getXY(xtMin,ytMin) << endl;*/
		if(ter.getXY(xtMin, ytMin) == '$'){
			ter.setXY(xtMin, ytMin, ' ');
			perso.setPiece(perso.getPiece()+1);
		}
		if(ter.getXY(xtMin, ytMin) == '!'){
			ter.setXY(xtMin, ytMin, ' ');
			perso.setDegat(perso.getDegat()+1);
		}
		if(ter.getXY(xtMin, ytMin) == 'O'){
			ter.setXY(xtMin, ytMin, ' ');
			perso.setArmure(perso.getArmure()+1);
		}
		if(ter.getXY(xtMin, ytMin) == '+'){
			ter.setXY(xtMin, ytMin, ' ');
			perso.setVie(perso.getVie()+1);
		}
	}else{

		for (int i=0;i<ter.getDimX();i++){
		for (int j=0;j<ter.getDimY();j++){
			if(ter.getXY(i,j)=='$' && perso.getX()==i && perso.getY()==j){ter.setXY(i,j,' ');perso.setPiece(perso.getPiece()+1);}
			if(ter.getXY(i,j)=='!' && perso.getX()==i && perso.getY()==j){ter.setXY(i,j,' ');perso.setDegat(perso.getDegat()+1);}
			if(ter.getXY(i,j)=='O' && perso.getX()==i && perso.getY()==j){ter.setXY(i,j,' ');perso.setArmure(perso.getArmure()+1);}
			if(ter.getXY(i,j)=='+' && perso.getX()==i && perso.getY()==j){ter.setXY(i,j,' ');perso.setVie(perso.getVie()+1);}
		}
		}
		}
}

void Jeu::PersoSubirDegat()
{
	if(getPerso().getX()==getMonstre().getX() && getPerso().getY()==getMonstre().getY())
	{
		getPerso().subirDegat(4);
	}

	if(getPerso().getY() >= getTerrain().getDimY())
	{
		getPerso().setMort(true);
	}
}

int Jeu::getStatus() const{

	return perso.getStatus();
}
int Jeu::getStatusO() const{

	return perso.getStatusO();
}
int Jeu::getSens() const{
	return perso.getSens();
}
int Jeu::getSensO() const{

	return perso.getSensO();
}


void Jeu::FinDuJeu()
{
	/*getPerso().estMort(getTerrain());
	if(getPerso().getMort()) fdj = getPerso().getMort();*/
	if(getTerrain().getXY((getPerso().getX() + TAILLE_SPRITE/2)/TAILLE_SPRITE , (getPerso().getY()+TAILLE_SPRITE/2)/TAILLE_SPRITE) == 'F') setVictoire(true);
}

bool Jeu::getFdj() const
{
	return fdj;
}

void Jeu::setFdj(bool b)
{
	fdj = b;
}

bool Jeu::getVictoire() const
{
	return victoire;
}

void Jeu::setVictoire(bool b)
{
	victoire = b;
}
