#include "Terrain.h"
#include <iostream>

using namespace std;


const char terrain1[21][41]=
{
 "########################################",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "#                                      #",
 "########################################"
};

Terrain::Terrain(char terr[21][41])
{
    dimx = 21;
    dimy = 41;
    for(int i=0; i<dimx; i++)
    {
        for(int j=0; j<dimy; j++)
        {
            tab[i][j] = terrain1[i][j];
        }
    }
}


Terrain::~Terrain()
{
    dimx = 0;
    dimy = 0;
}

void Terrain::afficherTerrain() 
{
    for(int i=0; i<dimx; i++)
    {
        for(int j=0; j<dimy; j++)
        {
            cout<<tab[i * dimx + j];
        }
        cout<<endl;
    }
}