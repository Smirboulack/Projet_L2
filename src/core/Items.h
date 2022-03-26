#ifndef _Equipement_H
#define _Equipement_H

#include "Terrain.h"
#include "Monstre.h"
#include "Vie.h"
#include "Armure.h"
#include "Arme.h"
#include "Piece.h"

class Items{

private:

 Arme * armes;
 Armure * armure;
 Piece * piece;
 Vie * vies;
 

public:
    Items();
    Items(const int _x,const int _y);
    ~Items();

    int getX()const;
    int getY()const;
    int setX();
    int setY();

    void testRegression();

};


#endif
