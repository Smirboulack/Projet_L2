#ifndef TERRAIN_H
#define TERRAIN_H

#include <string.h>
#include <string>


const int TAILLE_SPRITE = 36;
class Terrain
{
    private :
    int dimx, dimy;
    char ter[20][169];
    int version;
    int choixniv;
    //std::string pathname;
    public :
    /**
     * @brief Constructeur par défaut de Terrain
     * 
     */
    Terrain();
    /**
     * @brief Destructeur de Terrain
     * 
     */
    ~Terrain();
    /**
     * @brief Procédure de chargement d'un niveau
     * 
     * @param pathname le chemain vers le niveau
     * @return true 
     * @return false 
     */
    bool loadMap(const std::string pathname);
    /**
     * @brief La procédure qui permet l'affichage du terrain
     * 
     */
    void afficherTerrain();
    /**
     * Renvoie le type d'objet se trouvant en (x,y)
     * @param  x               abs de la case de l'objet
     * @param  y               ordonnée de la case de l'objet
     * @return   le type d'objet se trouvant en (x,y)
     */

    char getXY (const int x, const int y) const;
    /**
     * @brief Mutateur du terrain en coordonnée x et y
     * 
     * @param x la coordonnée
     * @param y la coordonnée
     * @param c le caractère à insérer
     */
    void setXY(const int x, const int y,const char & c);
    /**
     * @brief Mutateur de dimx
     * 
     * @param Dimx la coordonnée à insérer
     */
    void setDimx(const int Dimx);
    /**
     * @brief Mutateur de la version
     * 
     * @param v la version 
     */
    void setVersion(const int & v);
    /**
     * @brief Mutateur du choix du niveau
     * 
     * @param n le niveau
     */
    void setChoixniv(const int &n);
    /**
     * @brief Acesseur de dimx
     * 
     * @return int dimx
     */
    int getDimX () const;
    /**
     * @brief Acesseur de dimy
     * 
     * @return int dimy
     */
    int getDimY () const;
    /**
     * @brief Acesseur du Choix de niveau
     * 
     * @return int dimx
     */
    int getChoixniv () const;
    /**
     * @brief Acesseur dela version
     * 
     * @return int la version
     */
    int getVersion()const;
    /**
     * @brief La fonction qui vérifie si la position du Personnage est valide
     * 
     * @param x la coordonnée x
     * @param y la coordonnée y
     * @return true si la position est valide
     * @return false si la position est invalide
     */
    bool estPositionPersoValide(const int x,const int y) const;
    /**
     * @brief La procédure de lecture d'un terrain
     * 
     * @param pathname le chemin vers le terrain
     */
    void ouvrir(std::string pathname);
    
    void testRegression();
};


#endif
