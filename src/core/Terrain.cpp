#include "Terrain.h"
#include <iostream>
#include <cassert>

using namespace std;


const char terrain1[21][26]=
{
 "                         ",
 "                         ",
 "                         ",
 "                         ",
 "                         ",
 "                         ",
 "                         ",
 "                         ",
 "                         ",
 "                         ",
 "                         ",
 "  [GGG]           [GGGGGG",
 "  (___)           (______",
 "                         ",
 "                         ",
 "                         ",
 "TTTTTTTTTTTTTTTTTTTTTTTTT",
 "#########################",
 "#########################",
 "#########################"
};

Terrain::Terrain(){
    dimx = 26;
    dimy = 21;
    for(int i=0; i < dimy; i++)
    {
        for(int j=0; j < dimx; j++)
        {
            ter[i][j] = terrain1[i][j];
        }
    }
}


Terrain::~Terrain(){
    dimx = 0;
    dimy = 0;
}

void Terrain::afficherTerrain(){
    for(int i=0; i<dimx; i++)
    {
        for(int j=0; j<dimy; j++)
        {
            cout<<ter[i * dimx + j];
        }
        cout<<endl;
    }
}

char Terrain::getXY (const int x, const int y) const {
	assert(x>=0);
	assert(y>=0);
	assert(x<dimx);
	assert(y<dimy);
	return ter[y][x];
}



int Terrain::getDimX () const { return dimx; }

int Terrain::getDimY () const {	return dimy; }
