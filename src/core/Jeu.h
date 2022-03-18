#ifndef _JEU_H
#define _JEU_H

#include "Personnage.h"
#include "Terrain.h"
#include "Menu.h"
#include "Monstre.h"


class Jeu {

private :

	Terrain  * ter;
	Personnage perso;
  Menu cmenu;
    // Monstre * monst;
    // Equipement * equip;

public :

    Jeu();
    ~Jeu();

    void genereMenu();

    Terrain& getTerrain ();
    Personnage& getPerso ();
    Monstre & getMonstre ();


    const Terrain& getConstTerrain () const;
    const Personnage& getConstPersonnage () const;
   // const Monstre& getConstMonstre () const;
    int getNombreMonstre() const;

    void actionsAutomatiques ();
    bool actionClavier(const char touche); // rend vrai si mange une pastille, faux sinon

};


#endif
