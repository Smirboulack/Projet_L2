#ifndef _JEU_H
#define _JEU_H

#include "Personnage.h"
#include "Terrain.h"
//#include "Menu.h"
#include "Monstre.h"
#include "Items.h"
#include <ctime>
#include <iostream>
#include <assert.h>

using namespace std;

class Jeu {

private :

	Terrain ter;
	Personnage perso;
  Monstre monst;

  int temps, dsaut, fsaut;
	int vitesse_gravite;
public :

    Jeu();

    Terrain& getTerrain ();
    Personnage& getPerso ();
    Monstre & getMonstre ();


    const Terrain& getConstTerrain () const;
    const Personnage& getConstPersonnage () const;
    const Monstre& getConstMonstre () const;
    //int getNombreMonstre() const;
    int getStatus() const;
    int getStatusO() const;
		int getSens() const;
		int getSensO() const;

    int getTemps();

    void actionsAutomatiques ();
    bool actionClavier(const int touche, int tps);
		void gravite();
    void ramasserItems();
};


#endif
