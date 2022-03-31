#include "winTxt.h"
#include <iostream>
#include "txtJeu.h"
#include "../core/Jeu.h"

using namespace std;


int main ( int argc, char** argv ) {

    srand((unsigned int)time(NULL));
    Jeu jeu;
    termClear();
	txtBoucle(jeu);
    termClear();
	return 0;
}
