#ifndef _Equipement_H
#define _Equipement_H

#include "Terrain.h"
#include "Monstre"
#include "Personnage"

class Equipement{

private:

// coordonnées de l'equipement ainsi que sa direction
float x,y,direc;
// entier qui permettent de selectionner le type d'équipement pour le joueur
enum type_equip = {arme=1,vie=2};

extern const int equip_max;



public:
    Equipement();
    Equipement (float _x,float _y,float _direc);
    ~Equipement();

    float getX()const;
    float getY()const;
    float getDirec()const;

    void tirer(Monstre & monst , Terrain & Eterr);
    bool estRamasser(Personnage & Epers);

    void testRegression();


};


#endif
