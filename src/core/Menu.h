#ifndef _MENU_H
#define _MENU_H

enum ChoixMenu { MENU_Choix1=1, MENU_Choix2=2, MENU_Choix3=3, MENU_Quit=4 };
enum ChoixMenuOptions {MENUO_Choix1=1, MENUO_Choix2=2, MENUO_Choix3=3, MENUO_Choix4=4, MENUO_Quit=5};
extern const int MENU_MAX;
extern const int MENUO_MAX;

void menuAff();
void menuoAff();
ChoixMenu menuQuestion();
ChoixMenuOptions menuoQuestion();

void testRegression();


#endif