#include "Jeu.h"
#include <ctime>
#include <iostream>
#include <assert.h>

using namespace std;

const int VITESSE = 1;
const int VITESSE_SAUTER = 6;
const int VITESSE_ACCELEREE = 20;

Jeu::Jeu() : ter(), perso(), monst()
{
	temps = 0;
	vitesse_gravite = VITESSE_ACCELEREE;
}

Terrain &Jeu::getTerrain() { return ter; }

Personnage &Jeu::getPerso() { return perso; }

Monstre &Jeu::getMonstre() { return monst; }

const Terrain &Jeu::getConstTerrain() const { return ter; }

const Personnage &Jeu::getConstPersonnage() const { return perso; }

const Monstre &Jeu::getConstMonstre() const { return monst; }

bool Jeu::actionClavier(const int touche, int tps)
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
		/*
		if(!ter.estPositionPersoVide(perso.getX(),perso.getY()+1)){
			dsaut = tps;
			perso.deplacerVite(VITESSE+100, touche, ter);
		}*/
		if(VITESSE_SAUTER-(vitesse_gravite/VITESSE_ACCELEREE) > 0){
			perso.deplacerVite(VITESSE_SAUTER-(vitesse_gravite/VITESSE_ACCELEREE), touche, ter);
		}else{
			perso.deplacerVite(-(VITESSE_SAUTER-(vitesse_gravite/VITESSE_ACCELEREE)), 's', ter);
		}
		vitesse_gravite++;
		break;
	case 's':
		perso.deplacerVite(VITESSE, touche, ter);
		break;
	}
	/*
	if (ter.getXY(perso.getX(),perso.getY())=='.') {
	    ter.mangePastille(perso.getX(),perso.getY());
        return true;
	}*/



	return false;
}

void Jeu::actionsAutomatiques()
{
	//fan.verspersoman(ter,perso);
	//monstre.bougeAuto(ter);
	
	temps++;
	fsaut = dsaut+12;
	if(fsaut < temps)
	{
		gravite();
	}
	
	gravite();
	monst.bougeAutoMonstre(ter);
}

void Jeu::gravite()
{
	if(perso.deplacerVite(vitesse_gravite/VITESSE_ACCELEREE, 's', ter)){
		vitesse_gravite++;
	}else{
		vitesse_gravite = VITESSE_ACCELEREE;
	}
	//cout << vitesse_gravite/VITESSE_ACCELEREE << endl;
}

void Jeu::ramasserItems(){
	
	for (int i=0;i<ter.getDimX();i++){
		for (int j=0;j<ter.getDimY();j++){
			if(ter.getXY(i,j)=='$' && perso.getX()==i && perso.getY()==j){ter.setXY(i,j,' ');perso.setPiece(perso.getPiece()+1);}
			if(ter.getXY(i,j)=='!' && perso.getX()==i && perso.getY()==j){ter.setXY(i,j,' ');perso.setDegat(perso.getDegat()+1);}
			if(ter.getXY(i,j)=='O' && perso.getX()==i && perso.getY()==j){ter.setXY(i,j,' ');perso.setArmure(perso.getArmure()+1);}
			if(ter.getXY(i,j)=='+' && perso.getX()==i && perso.getY()==j){ter.setXY(i,j,' ');perso.setVie(perso.getVie()+1);}
		}
	}
}

int Jeu::getTemps()
{
	return temps;
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
