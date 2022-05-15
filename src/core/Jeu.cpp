#include "Jeu.h"
#include <ctime>
#include <iostream>
#include <assert.h>

using namespace std;

const int VITESSE = 1;


Jeu::Jeu() : ter(), perso()
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
			for(int i = 0;i < NbMonstre;i++){
			perso.attaquer(tabmonstre[i]);
		}
		break;
	}
	return false;
}

void Jeu::actionsAutomatiques()
{

	gravite();
	bougeAutoMonstre(ter);
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
	for(int i = 0; i < NbMonstre;i++){
		tabmonstre[i].gravite(ter);
	}
}

void Jeu::graviteMonstre()
{
	for(int i = 0; i < NbMonstre;i++){
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
		}else if(ter.getXY(xtMin, ytMin) == '='){
			getPerso().subirDegat(2);
		}
		else if(ter.getXY(xtMin,ytMin)=='^'){
			getPerso().subirDegat(1);
		}
		else if(ter.getXY(xtMin, ytMin) == 'F'){
			niveauSuivant();
		}
	}else{

		for (int i=0;i<ter.getDimX();i++){
		for (int j=0;j<ter.getDimY();j++){
			if(ter.getXY(i,j)=='$' && perso.getX()==i && perso.getY()==j){ter.setXY(i,j,' ');perso.setPiece(perso.getPiece()+1);}
			if(ter.getXY(i,j)=='!' && perso.getX()==i && perso.getY()==j){ter.setXY(i,j,' ');perso.setDegat(perso.getDegat()+1);}
			if(ter.getXY(i,j)=='O' && perso.getX()==i && perso.getY()==j){ter.setXY(i,j,' ');perso.setArmure(perso.getArmure()+1);}
			if(ter.getXY(i,j)=='+' && perso.getX()==i && perso.getY()==j){ter.setXY(i,j,' ');perso.setVie(perso.getVie()+1);}
			if(ter.getXY(i,j)=='=' && perso.getX()==i && perso.getY()==j){perso.subirDegat(2);}
			if(ter.getXY(i,j)=='^' && perso.getX()==i && perso.getY()==j){perso.subirDegat(1);}
		}
		}
		}
}

void Jeu::PersoSubirDegat()
{
	for(int i=0; i<NbMonstre; i++)
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

void Jeu::setFdj(bool fdj){
	this->Fdj = fdj;
}

bool Jeu::getFdj(){
	return Fdj;
}

void Jeu::initMonstre()
{
	if (getTerrain().getVersion() == 1)
	{
		tabmonstre[0].setX(15 * TAILLE_SPRITE);
		tabmonstre[0].setY(3 * TAILLE_SPRITE);
		tabmonstre[1].setX(17 * TAILLE_SPRITE);
		tabmonstre[1].setY(3 * TAILLE_SPRITE);
		tabmonstre[2].setX(18 * TAILLE_SPRITE);
		tabmonstre[2].setY(3 * TAILLE_SPRITE);
		tabmonstre[3].setX(22 * TAILLE_SPRITE);
		tabmonstre[3].setY(3 * TAILLE_SPRITE);
		tabmonstre[4].setX(30 * TAILLE_SPRITE);
		tabmonstre[4].setY(3 * TAILLE_SPRITE);
		tabmonstre[5].setX(41 * TAILLE_SPRITE);
		tabmonstre[5].setY(3 * TAILLE_SPRITE);
		tabmonstre[6].setX(65 * TAILLE_SPRITE);
		tabmonstre[6].setY(6 * TAILLE_SPRITE);
		tabmonstre[7].setX(73 * TAILLE_SPRITE);
		tabmonstre[7].setY(3 * TAILLE_SPRITE);
		tabmonstre[8].setX(71 * TAILLE_SPRITE);
		tabmonstre[8].setY(3 * TAILLE_SPRITE);
		tabmonstre[9].setX(85 * TAILLE_SPRITE);
		tabmonstre[9].setY(3 * TAILLE_SPRITE);

		tabmonstre[10].setX(86 * TAILLE_SPRITE);
		tabmonstre[10].setY(3 * TAILLE_SPRITE);
		tabmonstre[11].setX(88 * TAILLE_SPRITE);
		tabmonstre[11].setY(3 * TAILLE_SPRITE);
		tabmonstre[12].setX(90 * TAILLE_SPRITE);
		tabmonstre[12].setY(3 * TAILLE_SPRITE);
		tabmonstre[13].setX(122 * TAILLE_SPRITE);
		tabmonstre[13].setY(3 * TAILLE_SPRITE);
		tabmonstre[14].setX(13 * TAILLE_SPRITE);
		tabmonstre[14].setY(3 * TAILLE_SPRITE);
		tabmonstre[15].setX(144 * TAILLE_SPRITE);
		tabmonstre[15].setY(3 * TAILLE_SPRITE);
		tabmonstre[16].setX(150 * TAILLE_SPRITE);
		tabmonstre[16].setY(3 * TAILLE_SPRITE);
		tabmonstre[17].setX(155 * TAILLE_SPRITE);
		tabmonstre[17].setY(3 * TAILLE_SPRITE);
		tabmonstre[18].setX(157 * TAILLE_SPRITE);
		tabmonstre[18].setY(3 * TAILLE_SPRITE);

		for (int i = 0; i < NbMonstre; i++)
		{
			tabmonstre[i].setVie(55);
		}
	}
	else
	{

		tabmonstre[0].setX(15);
		tabmonstre[0].setY(14);
		tabmonstre[1].setX(17);
		tabmonstre[1].setY(14);
		tabmonstre[2].setX(18);
		tabmonstre[2].setY(14);
		tabmonstre[3].setX(22);
		tabmonstre[3].setY(14);
		tabmonstre[4].setX(30);
		tabmonstre[4].setY(14);
		tabmonstre[5].setX(41);
		tabmonstre[5].setY(14);
		tabmonstre[6].setX(65);
		tabmonstre[6].setY(6);
		tabmonstre[7].setX(73);
		tabmonstre[7].setY(14);
		tabmonstre[8].setX(71);
		tabmonstre[8].setY(14);
		tabmonstre[9].setX(85);
		tabmonstre[9].setY(14);

		tabmonstre[10].setX(86);
		tabmonstre[10].setY(14);
		tabmonstre[11].setX(88);
		tabmonstre[11].setY(14);
		tabmonstre[12].setX(90);
		tabmonstre[12].setY(14);
		tabmonstre[13].setX(122);
		tabmonstre[13].setY(14);
		tabmonstre[14].setX(13);
		tabmonstre[14].setY(14);
		tabmonstre[15].setX(144);
		tabmonstre[15].setY(14);
		tabmonstre[16].setX(150);
		tabmonstre[16].setY(14);
		tabmonstre[17].setX(155);
		tabmonstre[17].setY(14);
		tabmonstre[18].setX(157);
		tabmonstre[18].setY(14);
	}

}
/*
void Jeu::bougeAutoMonstre(Terrain & ter){
	  srand((int)time(0));
		for(int i = 0;i < NbMonstre;i++){
			if(rand()%100 < 50){
		    tabmonstre[i].deplacerMonstre('d',ter);
		  }else{
		    tabmonstre[i].deplacerMonstre('q', ter);
		  }
		}
}*/

void Jeu::bougeAutoMonstre(Terrain & ter){
	  srand((int)time(0));
		for(int i = 0;i < NbMonstre;i++){
			if(rand()%100 < 50){
		    tabmonstre[i].deplacer('d',ter);
		  }else{
		    tabmonstre[i].deplacer('q', ter);
		  }
		}
}



void Jeu::niveauSuivant(){

	ter.setChoixniv(ter.getChoixniv()+1);
	if(ter.loadMap("./data/Niveau" + std::to_string(ter.getChoixniv()) + ".txt")){
		setFdj(true);
	}
	perso.setX(20);
	perso.setY(20);
	initMonstre();
}
