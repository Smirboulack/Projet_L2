#ifndef _JEU_H
#define _JEU_H

#include "Personnage.h"
#include "Terrain.h"
//#include "Menu.h"
#include "Monstre.h"
#include "Items.h"


class Jeu {

private :

	Terrain ter;
	Personnage perso;
  Monstre monst;
  Items itemss;
   int temps, dsaut, fsaut;
      //Menu cmenu;
    // Equipement * equip;

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

    int getTemps();

    void actionsAutomatiques ();
    bool actionClavier(const int touche, int tps);

  /*
    void actionsAutomatiques ();
    bool actionClavier(const char touche); // rend vrai si mange une pastille, faux sinon

  */
		void gravite();
};


#endif
