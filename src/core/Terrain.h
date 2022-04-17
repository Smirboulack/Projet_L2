#ifndef TERRAIN_H
#define TERRAIN_H

#include "Items.h"

class Terrain
{
    private :
    int dimx, dimy;
    char ter[21][101];
    public :

    Terrain(); //Constructeur
    ~Terrain();                 //Destructeur

    // Items * items;

    void afficherTerrain();     //Procédure d'affichage
    /**
     * Renvoie le type d'objet se trouvant en (x,y)
     * @param  x               abs de la case de l'objet
     * @param  y               ordonnée de la case de l'objet
     * @return   le type d'objet se trouvant en (x,y)
     */

    char getXY (const int x, const int y) const;
    char setXY(const int x, const int y,const char & c);

    //Renvoie la largeur du terrain
    int getDimX () const;

    //Renvoie la hauteur du terrain
    int getDimY () const;
    bool estPositionPersoValide(const int x,const int y) const;
};


#endif
