#include "Terrain.h"
//#include "Items.h"
#include <iostream>
#include <cassert>

const int TAILLE_SPRITE = 32;
using namespace std;

//Items item1;

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
 "  [GGG]           [GGGGGGGGGGGGGGGGGGGGGGGG]       [GGG]               [GGG]                        ",
 "  (___)           (________________________)       (___)               (___)                        ",
 "                                                                                                    ",
 "                                [GGG]                      [GGG][GGG]                               ",
 "                                (___)                      (___)(___)                               ",
 "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT",
 "####################################################################################################",
 "####################################################################################################",
 "####################################################################################################"
};

Terrain::Terrain(){
    dimx = 100;
    dimy = 20;
    for(int i=0; i < dimy; i++)
    {
        for(int j=0; j < dimx; j++)
        {
           // terrain1[item1[0].getarmey()][item1[0].getarmurex()] = item1[0].getchararme();
            //terrain1[item1.getarmey()][item1.getarmurex()] = item1.getchararme();
            ter[i][j] = terrain1[i][j];


        }
    }
}


Terrain::~Terrain(){
    dimx = 0;
    dimy = 0;
   // delete item1;
   // item1=nullptr;
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
  int xtMin = x/TAILLE_SPRITE;
  int ytMin = y/TAILLE_SPRITE;
  int xtMax = (x + TAILLE_SPRITE - 1)/TAILLE_SPRITE ;
  int ytMax = (y + TAILLE_SPRITE - 1)/TAILLE_SPRITE ;
  cout << dimx * TAILLE_SPRITE << " " << dimy * TAILLE_SPRITE << endl;
  cout << x << " " << y << endl;
  cout << xtMin << " " << ytMin << endl;
  cout << xtMax << " " << ytMax << endl;
  return ((x>=0) && (x+TAILLE_SPRITE<dimx*TAILLE_SPRITE) && (y>=0) && (y+TAILLE_SPRITE<dimy*TAILLE_SPRITE) && (ter[ytMin][xtMin] == ' ') && (ter[ytMax][xtMax] == ' ') && (ter[ytMin][xtMax] == ' ') && (ter[ytMax][xtMin] == ' '));
}

int Terrain::getDimX () const { return dimx; }

int Terrain::getDimY () const {	return dimy; }
