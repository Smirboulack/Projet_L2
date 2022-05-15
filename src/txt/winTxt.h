#ifndef _WINTXT_H
#define _WINTXT_H

/*
//! \brief une fenêtre texte est un tableau 2D de caractères

*/
class WinTXT
{
private:
    int dimx;  //!< \brief largeur
    int dimy;  //!< \brief hauteur
    char *win; //!< \brief stocke le contenu de la fenêtre dans un tableau 1D mais on y accede en 2D

public:
    /**
     * @brief Constructeur par défaut de winTxt
     *
     */
    WinTXT();
    /**
     * @brief Procédure de chargement d'un niveau
     *
     * @param dx largeur
     * @param dy hauteur
     *
     */
    WinTXT(int dx, int dy);
    /**
     * @brief Procédure qui nettoie l'écran en l'a remplissant avec le caractère ' '
     *
     * @param c caractère ' '
     *
     */
    void clear(char c = ' ');
    /**
     * @brief Procédure qui affiche à l'écran le caractère c au paramètres spécifiés
     *
     * @param x position x dans l'écran
     * @param y position y dans l'écran
     * @param c caractère
     */
    void print(int x, int y, char c);
    /**
     * @brief Procédure qui affiche à l'écran le caractère c au paramètres spécifiés
     *
     * @param x position x dans l'écran
     * @param y position y dans l'écran
     * @param c caractère de type pointeur sur char
     */
    void print(int x, int y, char *c);
    /**
     * @brief Procédure qui permet de dessiner dans l'écran
     *
     * @param x position x=0
     * @param y position y=0
     *
     */
    void draw(int x = 0, int y = 0);
    /**
     * @brief Procédure qui permet de mettre en pause l'écran en attente de l'entrée d'une touche
     *
     */
    void pause();
    /**
     * @brief Fonction qui retourne le caractère
     *
     */
    char getCh();
    /**
     * @brief testRegression de winTxt
     *
     */
    void testRegression();
};

/**
 * @brief Procédure qui permet de nettoyer la console avec la commande unix "clear"
 *
 */
void termClear();

#endif
