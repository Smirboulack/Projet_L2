#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain
{
    private :
    int dimx, dimy;
    char tab[21][41];



    public :
    Terrain(char terr[21][41]); //Constructeur
    ~Terrain();                 //Destructeur

    void afficherTerrain();     //Procédure d'affichage
    /**
     * Renvoie le type d'objet se trouvant en (x,y)
     * @param  x               abs de la case de l'objet
     * @param  y               ordonnée de la case de l'objet
     * @return   le type d'objet se trouvant en (x,y)
     */

    char getXY (const int x, const int y) const;

    //Renvoie la largeur du terrain
    int getDimX () const;

    //Renvoie la hauteur du terrain
    int getDimY () const;

};


#endif
