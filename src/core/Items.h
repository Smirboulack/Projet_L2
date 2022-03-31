#ifndef _Equipement_H
#define _Equipement_H

#include <stdlib.h>
#include <time.h> 

#include "Terrain.h"
#include "Monstre.h"
#include "Vie.h"
#include "Armure.h"
#include "Arme.h"
#include "Piece.h"


class Items{

private:

 unsigned int nb_items;

 Arme * armes;
 Armure * armure;
 Piece * piece;
 Vie * vies; 

public:

     unsigned int min = 1, max = 31;
    unsigned int plage = max-min+1;

    Items();
    ~Items();

    char getchararme()const;
    char getchararmure()const;
    char getcharpiece()const;
    char getcharvie()const;

    int getarmex()const;
    int getarmey()const;

    int getarmurex()const;
    int getarmurey()const;

    int getpiecex()const;
    int getpiecey()const;

    int getviex()const;
    int getviey()const;
    
    void setarmex(const int a);
    void setarmey(const int a);
    void setarmexy(const int a,const int b);

    void setarmurex(const int a);
    void setarmurey(const int a);
    void setarmurexy(const int a,const int b);

    void setpiecex(const int a);
    void setpiecey(const int a);
    void setpiecexy(const int a,const int b);

    void setviex(const int a);
    void setviey(const int a);
    void setviexy(const int a,const int b);

    const Arme& getarme()const;
    const Armure& getarmure()const;
    const Piece& getpiece()const;
    const Vie& getvies()const;

    const unsigned int getnbitems()const;

    void testRegression();

};


#endif
