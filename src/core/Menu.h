#ifndef _MENU_H
#define _MENU_H

enum ChoixMenu
{
    MENU_Choix1 = 1,
    MENU_Choix2 = 2,
    MENU_Choix3 = 3,
    MENU_Quit = 4
}; //!< \brief ensemble d'entier qui vont permettre d'acceder aux choix du menu principal
enum ChoixMenuOptions
{
    MENUO_Choix1 = 1,
    MENUO_Choix2 = 2,
    MENUO_Choix3 = 3,
    MENUO_Choix4 = 4,
    MENUO_Quit = 5
};                          //!< \brief ensemble d'entier qui vont permettre d'acceder aux choix du sous-menu options
extern const int MENU_MAX;  //!< \brief constante de la valeur maximale de choix dans le menu principal
extern const int MENUO_MAX; //!< \brief constante de la valeur maximale de choix dans le sous-menu d'options

/**
 * @brief Procédure qui permet d'afficher les choix du menu principal
 *
 */
void menuAff();
/**
 * @brief Procédure qui permet d'afficher les choix du sous-menu options
 *
 */
void menuoAff();
/**
 * @brief Procédure qui permet gérer le déplacement dans le menu principal
 *
 */
ChoixMenu menuQuestion();
/**
 * @brief Procédure qui permet gérer le déplacement dans le sous-menu options
 *
 */
ChoixMenuOptions menuoQuestion();
/**
 * @brief Procédure de test de Menu
 *
 */

void testRegression();

#endif