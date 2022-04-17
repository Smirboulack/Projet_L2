#ifndef _MENU_H
#define _MENU_H

enum ChoixMenu { MENU_Choix1=1, MENU_Choix2=2, MENU_Quit=3 };
extern const int MENU_MAX;

void menuAff();
ChoixMenu menuQuestion();


#endif