#ifndef _JEU_H
#define _JEU_H

#include "Personnage.h"
#include "Terrain.h"
//#include "Menu.h"
#include "Monstre.h"
#include "Items.h"
#include <ctime>
#include <iostream>

using namespace std;

class Jeu {

private :

	Terrain ter;
	Personnage perso;
  Monstre monst;
  Items itemss;
      //Menu cmenu;
    // Equipement * equip;
  int temps, dsaut, fsaut;

public :

    Jeu();

    //void genereMenu();

    Terrain& getTerrain ();
    Personnage& getPerso ();
    //Monstre & getMonstre ();


    const Terrain& getConstTerrain () const;
    const Personnage& getConstPersonnage () const;
    const Monstre& getConstMonstre () const;
    const Items& getConstItems()const;
    //int getNombreMonstre() const;
    int getStatus() const;

    int getTemps();

    void actionsAutomatiques ();
    bool actionClavier(const int touche, int tps);
		void gravite();
};


#endif
