#include "Terrain.h"
//#include "Items.h"
#include <iostream>
#include <cassert>

const int TAILLE_SPRITE = 36;
using namespace std;

//Items item1;

char terrain1[21][101]=
{                   //22    //32        //42    //52       //61         //79      //83  //88
 "  PSEUDO:         VIE:   Armure:   Degats:   Portee:   Piece:    positionPerso: {x:  ,y:  }         ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                                                                                                    ",
 "                      $$$$$$$$$$$$$$$$                                                              ",
 "  [GGG]           [GGGGGGGGGGGGGGGGGGGGGGGG]       [GGG]               [GGG]                        ", 
 "  (___)           (________________________)       (___)               (___)                        ",
 "                                                                                                    ",
 "                                    [GGG]                          [GGG][GGG]                       ",
 "            ++          !!          (___)      OO   OO             (___)(___)                       ",
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

void Terrain::setXY(const int x, const int y,const char & c){
    assert(x>=0);
	assert(y>=0);
	assert(x<dimx);
	assert(y<dimy); 
    ter[y][x]=c;
}


bool Terrain::estPositionPersoValide(const int x,const int y) const{
  int xtMin = x/TAILLE_SPRITE;
  int ytMin = y/TAILLE_SPRITE;
  int xtMax = (x + TAILLE_SPRITE - 1)/TAILLE_SPRITE;
  int ytMax = (y + TAILLE_SPRITE - 1)/TAILLE_SPRITE;
  //cout << dimx * TAILLE_SPRITE << " " << dimy * TAILLE_SPRITE << endl;
  //cout << x << " " << y << endl;
  //cout << xtMin << " " << ytMin << endl;
  //cout << xtMax << " " << ytMax << endl;
  return ((x>=0) && (x+TAILLE_SPRITE<dimx*TAILLE_SPRITE) && (y>=0) && (y+TAILLE_SPRITE<dimy*TAILLE_SPRITE) && ((ter[ytMin][xtMin] == ' ') && (ter[ytMax][xtMax] == ' ') && (ter[ytMin][xtMax] == ' ') && (ter[ytMax][xtMin] == ' ')));
}


int Terrain::getDimX () const { return dimx; }
int Terrain::getDimY () const {	return dimy; }
