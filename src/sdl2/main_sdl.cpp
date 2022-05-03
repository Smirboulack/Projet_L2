#include "sdlJeu.h"
#include <string>
#include "../core/Menu.h"
#include "../core/Jeu.h"
#include "../txt/winTxt.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main (int argc, char** argv) {
	sdlJeu sj;
	sj.sdlBoucle();
	return 0;
}

