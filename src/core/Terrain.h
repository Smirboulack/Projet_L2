#ifndef TERRAIN_H
#define TERRAIN_H

#include <string.h>
#include <string>

using namespace std;

class Terrain
{
    private :
    int dimx, dimy;
    char ter[21][101];
    int version;
    public :

    Terrain(); //Constructeur
    ~Terrain();                 //Destructeur

    void afficherTerrain();     //Procédure d'affichage
    /**
     * Renvoie le type d'objet se trouvant en (x,y)
     * @param  x               abs de la case de l'objet
     * @param  y               ordonnée de la case de l'objet
     * @return   le type d'objet se trouvant en (x,y)
     */

    char getXY (const int x, const int y) const;
    void setXY(const int x, const int y,const char & c);
    void setVersion(const int & v);

    //Renvoie la largeur du terrain
    int getDimX () const;

    //Renvoie la hauteur du terrain
    int getDimY () const;
    int getVersion()const;
    bool estPositionPersoValide(const int x,const int y) const;
    void ouvrir(string pathname);
};


#endif
