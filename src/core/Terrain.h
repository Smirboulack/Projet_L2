#ifndef TERRAIN_H
#define TERRAIN_H

#include <string.h>
#include <string>


const int TAILLE_SPRITE = 36;
class Terrain
{
    private :
    int dimx, dimy;
    char ter[21][171];
    int version;
    int choixniv;
    //std::string pathname;
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
    void setDimx(const int Dimx);
    void setVersion(const int & v);
    void setChoixniv(const int &n);

    //Renvoie la largeur du terrain
    int getDimX () const;

    int getChoixniv () const;

    //Renvoie la hauteur du terrain
    int getDimY () const;
    int getVersion()const;
    bool estPositionPersoValide(const int x,const int y) const;
    void ouvrir(std::string pathname);

    void testRegression();
};


#endif
