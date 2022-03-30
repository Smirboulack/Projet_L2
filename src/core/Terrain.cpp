#include "Terrain.h"
#include "Items.h"
#include <iostream>
#include <cassert>

using namespace std;

Items * item1=new Items[1];

char terrain1[21][101]=
{
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "  [GGG]           [GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG]    [GGG]         [GGG]                     ", 
 "  (___)           (____________________________________)    (___)         (___)                     ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT",
 "####################################################################################################",
 "####################################################################################################",
 "####################################################################################################"
};

Terrain::Terrain(){
    dimx = 101;
    dimy = 21;
    for(int i=0; i < dimy; i++)
    {
        for(int j=0; j < dimx; j++)
        {
            terrain1[item1[0].getarmey()][item1[0].getarmurex()] = item1[0].getchararme();
            ter[i][j] = terrain1[i][j];
            
            
        }
    }
}


Terrain::~Terrain(){
    dimx = 0;
    dimy = 0;
    delete item1;
    item1=nullptr;
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

bool Terrain::estPositionPersoValide(const int x,const int y) const{
  return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (ter[y][x]==' '));
}

int Terrain::getDimX () const { return dimx; }

int Terrain::getDimY () const {	return dimy; }
