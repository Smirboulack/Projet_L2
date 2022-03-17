#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain 
{
    private :
    int dimx, dimy;
    char tab[21][41];
    


    public :
    Terrain(char terr[21][41]);                  //Constructeur
    ~Terrain();                 //Destructeur

    void afficherTerrain();     //Procédure d'affichage


};


#endif