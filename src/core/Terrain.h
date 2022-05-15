#ifndef TERRAIN_H
#define TERRAIN_H

#include <string.h>
#include <string>

const int TAILLE_SPRITE = 36;
class Terrain
{
private:
    int dimx, dimy;    //!< \brief dimension sur l'axe X et dimension sur l'axe Y du terrain
    char ter[20][169]; //!< \brief terrain 2D de caractères qui servira à stocker la lecture du terrain depuis le fichier texte
    int version;       //!< \brief entier qui sert de passerelles entre la version txt du jeu et la version SDL
    int choixniv;      //!< \brief entier qui permet de sélectionner le niveau parmis les 3 niveaux disponible
public:
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

    char getXY(const int x, const int y) const;
    /**
     * @brief Mutateur du terrain en coordonnée x et y
     *
     * @param x la coordonnée
     * @param y la coordonnée
     * @param c le caractère à insérer
     */
    void setXY(const int x, const int y, const char &c);
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
    void setVersion(const int &v);
    /**
     * @brief Mutateur du choix du niveau
     *
     * @param n le niveau
     */
    void setChoixniv(const int &n);
    /**
     * @brief Accesseur de dimx
     *
     * @return int dimx
     */
    int getDimX() const;
    /**
     * @brief Accesseur de dimy
     *
     * @return int dimy
     */
    int getDimY() const;
    /**
     * @brief Accesseur du Choix de niveau
     *
     * @return int dimx
     */
    int getChoixniv() const;
    /**
     * @brief Accesseur dela version
     *
     * @return int la version
     */
    int getVersion() const;
    /**
     * @brief La fonction qui vérifie si la position du Personnage est valide
     *
     * @param x la coordonnée x
     * @param y la coordonnée y
     * @return true si la position est valide
     * @return false si la position est invalide
     */
    bool estPositionPersoValide(const int x, const int y) const;
    /**
     * @brief La fonction qui vérifie si la position du monstre est valide
     *
     * @param x la coordonnée x
     * @param y la coordonnée y
     * @return true si la position est valide
     * @return false si la position est invalide
     */
    bool estPositionMonstreValide(const int x, const int y) const;

    /**
     * @brief La procédure de lecture d'un terrain
     *
     * @param pathname le chemin vers le terrain
     */
    void ouvrir(std::string pathname);
    /**
     * @brief Procédure testRegression de terrain
     *
     */

    void testRegression();
};

#endif
