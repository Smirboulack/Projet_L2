#include "Jeu.h"
#include <ctime>
#include <iostream>
#include <assert.h>

using namespace std;

const int VITESSE = 1;


Jeu::Jeu() : ter(), perso(), monst(360,180,20,20,20,"Monstre")
{
	Fdj = false;
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
			for(int i = 0;i < 10;i++){
			perso.attack(tabmonstre[i]);
		}
		
		break;
	}
	return false;
}

void Jeu::actionsAutomatiques()
{

	gravite();
	monst.bougeAutoMonstre(ter);
	for (int i=0;i<10;i++){tabmonstre[i].bougeAutoMonstre(ter);}
	FinDuJeu();
	PersoSubirDegat();
	ramasserItems();
}

void Jeu::FinDuJeu()
{
	if(getPerso().getVie()==0) setFdj(true);
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
		int x = perso.getX() + TAILLE_SPRITE/2;
		int y =  perso.getY() + TAILLE_SPRITE/2;
		int xtMin = x/TAILLE_SPRITE;
		int ytMin = y/TAILLE_SPRITE;
		/*cout << "x : " << xtMin << endl;
		cout << "y : " << ytMin << endl;
		cout << "terXY : " << ter.getXY(xtMin,ytMin) << endl;*/
		if(ter.getXY(xtMin, ytMin) == '$'){
			ter.setXY(xtMin, ytMin, ' ');
			perso.setPiece(perso.getPiece()+1);
		}else if(ter.getXY(xtMin, ytMin) == '!'){
			if(!getPerso().getArme())
			{
				getPerso().setArme(true);
			}else
			{
				getPerso().setDegat(getPerso().getDegat()+1);
			}
			ter.setXY(xtMin, ytMin, ' ');
		}else if(ter.getXY(xtMin, ytMin) == 'O'){
			ter.setXY(xtMin, ytMin, ' ');
			perso.setArmure(perso.getArmure()+1);
		}else if(ter.getXY(xtMin, ytMin) == '+'){
			ter.setXY(xtMin, ytMin, ' ');
			perso.setVie(perso.getVie()+1);
		}else if(ter.getXY(xtMin, ytMin) == 'F'){
			niveauSuivant();
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
	for(int i=0; i<10; i++)
	{
		if(getPerso().getX()==getMonstre(i).getX() && getPerso().getY()==getMonstre(i).getY())
		{
			if(getPerso().getArmure()>0) 
			{
				getPerso().setArmure(getPerso().getArmure()-1);
			}else getPerso().subirDegat(2);
			
		}

		if(getPerso().getY() >= getTerrain().getDimY())
		{
			getPerso().setMort(true);
		}
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
void Jeu::niveauSuivant(){

	ter.setChoixniv(ter.getChoixniv()+1);
	if(ter.loadMap("./data/Niveau" + std::to_string(ter.getChoixniv()) + ".txt")){
		setFdj(true);
	}
	perso.setX(20);
	perso.setY(20);
}

void Jeu::setFdj(bool fdj){
	Fdj = fdj;
}

bool Jeu::getFdj(){
	return Fdj;
}

void Jeu::initMonstre()
{
	if(getTerrain().getVersion()==1)
	{
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
	}
	else
	{
		tabmonstre[0].setX(0 );
	tabmonstre[0].setY(14 );
	tabmonstre[1].setX(40 );
	tabmonstre[1].setY(10 );
	tabmonstre[2].setX(5 );
	tabmonstre[2].setY(10 );
	tabmonstre[3].setX(44 );
	tabmonstre[3].setY(15 );
	tabmonstre[4].setX(44 );
	tabmonstre[4].setY(15 );
	tabmonstre[5].setX(65 );
	tabmonstre[5].setY(15 );
	tabmonstre[6].setX(19 );
	tabmonstre[6].setY(15 );
	tabmonstre[7].setX(83 );
	tabmonstre[7].setY(15 );
	tabmonstre[8].setX(71 );
	tabmonstre[8].setY(13 );
	tabmonstre[9].setX(54 );
	tabmonstre[9].setY(10 );
	}
	
}
