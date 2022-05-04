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
	sdlJeu sj;
	sj.sdlBoucle();
	return 0;
}

