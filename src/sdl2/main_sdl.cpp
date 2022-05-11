#include "sdlJeu.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

#include "../core/Jeu.h"
#include "../txt/winTxt.h"

using namespace std;


int main (int argc, char** argv) {
	
	int niv;
	cout << "Quel niveau jouer ? " <<endl;
	cin >> niv;



	sdlJeu sj;
	sj.sdlBoucle(niv);
	return 0;
}

