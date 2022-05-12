#include "Terrain.h"
#include <iostream>
#include <cassert>
#include <unistd.h>
#include <fcntl.h>


//const int TAILLE_SPRITE = 36;
using namespace std;

//Items item1;
/*
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
 "            ++++++     F    !!          (___)      OO   OO             (___)(___)                   ",
 "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT",
 "####################################################################################################",
 "####################################################################################################",
 "####################################################################################################"
};
*/


Terrain::Terrain(){
    dimx = 171;
    dimy = 21;
    /*
    for(int i=0; i < dimy; i++)
    {
        for(int j=0; j < dimx; j++)
        {
            ter[i][j] = terrain1[i][j];
        }
    }*/
    /*
    switch (choixniv)
    {
    case '1':
        ouvrir("./data/Niveau1.txt");
        break;
    case '2':
        ouvrir("./data/Niveau2.txt");
        break;
    case 3:
        ouvrir("./data/Niveau3.txt");
        break;
    case 4:
        ouvrir("./data/Niveau4.txt");
        break;
    case 5:
        ouvrir("./data/Niveau5.txt");
        break;
    default:
        ouvrir("./data/Niveau1.txt");
    }

*/
/*
if(choixniv=1){ouvrir("./data/Niveau1.txt");
    }else if(choixniv=2){
        ouvrir("./data/Niveau2.txt");
    }else if(choixniv=3){
        ouvrir("./data/Niveau2.txt");
    }else if(choixniv=4){
        ouvrir("./data/Niveau2.txt");
    }else if(choixniv=5){
        ouvrir("./data/Niveau2.txt");
    }else{
        exit(EXIT_SUCCESS);
    }
*/


  // ouvrir(choixnive);

}



Terrain::~Terrain(){
    dimx = 0;
    dimy = 0;
}



void Terrain::ouvrir(string pathname)
{
    char buf;
    int fd, nbrd;
    int x,y;
    x=0;
    y=0;
    /*
    if(choixniv==1){ouvrir("./data/Niveau1.txt");
    }else if(choixniv==2){
        ouvrir("./data/Niveau2.txt");
    }else if(choixniv==3){
        ouvrir("./data/Niveau2.txt");
    }else if(choixniv==4){
        ouvrir("./data/Niveau2.txt");
    }else if(choixniv==5){
        ouvrir("./data/Niveau2.txt");
    }else{
        exit(EXIT_SUCCESS);
    }
    */
    

    fd = open(pathname.c_str(), O_RDONLY);
    if (fd == -1)
    {
        cout << "Erreur lors de l'ouverture" << endl;
    }
    else
    {
        for ( y = 0; y < dimy; y++)
        {
            for ( x = 0; x < dimx; x++)
            {
                /*do
                {
                    if (buf != 'G' && buf != '[' && buf != ']' && buf != '_' && buf != '(' &&
                        buf != ')' && buf != '#' && buf != 'T' && buf != 'F' && buf != ' ')
                    {
                        cout << "Caractere SPECIAL à l'adresse y: " << y << " x: " << x <<" valeur : "<<buf <<endl;
                    }
                    else
                    {
                        cout << "Caractere normal à l'adresse y: " << y << " x: " << x <<" valeur : "<<buf << endl;
                    }
                    nbrd = read(fd, &buf, 1);
                    x++;
                    if(x==80)
                    {
                        x=0;
                        y++;
                    }
                }*/

                    nbrd = read(fd, &buf, 1);
                    if(buf == '\n')
                    {
                    nbrd = read(fd, &buf, 1);
                    y++;
                    x=0;
                    }
                    ter[y][x] = buf;
           }
        }
    }
    close(fd);
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
	/*assert(x>=0);
	assert(y>=0);
	assert(x<dimx);
	assert(y<dimy);*/
	return ter[y][x];
}

void Terrain::setXY(const int x, const int y,const char & c){
    assert(x>=0);
	assert(y>=0);
	assert(x<dimx);
	assert(y<dimy);
    ter[y][x]=c;
}

void Terrain::setVersion(const int & v){version=v;}
void Terrain::setDimx(const int Dimx){dimx=Dimx;}
void Terrain::setChoixniv(const int &n){choixniv=n;}


int Terrain::getDimX () const { return dimx; }
int Terrain::getDimY () const {	return dimy; }
int Terrain::getVersion()const {return version;}
int Terrain::getChoixniv () const{return choixniv;}


bool Terrain::estPositionPersoValide(const int x,const int y) const{
  int xtMin = x/TAILLE_SPRITE;
  int ytMin = y/TAILLE_SPRITE;
  int xtMax = (x + TAILLE_SPRITE - 1)/TAILLE_SPRITE;
  int ytMax = (y + TAILLE_SPRITE - 1)/TAILLE_SPRITE;
  //cout << dimx * TAILLE_SPRITE << " " << dimy * TAILLE_SPRITE << endl;
  //cout << x << " " << y << endl;
  //cout << xtMin << " " << ytMin << endl;
  //cout << xtMax << " " << ytMax << endl;


/*
if(version==1){return ((x>=0) && (x+TAILLE_SPRITE<dimx*TAILLE_SPRITE) && (y>=0) && (y+TAILLE_SPRITE<dimy*TAILLE_SPRITE) && ((ter[ytMin][xtMin] == ' ') && (ter[ytMax][xtMax] == ' ') && (ter[ytMin][xtMax] == ' ') && (ter[ytMax][xtMin] == ' ')));
}else{
    return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy)
    && ((ter[y][x]==' ') || (ter[y][x]=='$') || (ter[y][x]=='!') || (ter[y][x]=='O') || (ter[y][x]=='+') || (ter[y][x]=='F') ));
}
*/


if(version==1){return (
    (x>=0) && (x+TAILLE_SPRITE<dimx*TAILLE_SPRITE) && (y>=0) && (y+TAILLE_SPRITE<dimy*TAILLE_SPRITE) &&
    (
      (
        (ter[ytMin][xtMin] == ' ')||(ter[ytMin][xtMin] == '+')||(ter[ytMin][xtMin] == '$')||(ter[ytMin][xtMin] == 'O')||(ter[ytMin][xtMin] == '!')||(ter[ytMin][xtMin] == 'F')
      )
      &&
      (
        (ter[ytMax][xtMax] == ' ') ||(ter[ytMax][xtMax] == '+')||(ter[ytMax][xtMax] == '$')||(ter[ytMax][xtMax] == 'O')||(ter[ytMax][xtMax] == '!')||(ter[ytMax][xtMax] == 'F')
      )
      &&
      (
        (ter[ytMin][xtMax] == ' ') || (ter[ytMin][xtMax] == '+')|| (ter[ytMin][xtMax] == '$')|| (ter[ytMin][xtMax] == 'O')|| (ter[ytMin][xtMax] == '!')|| (ter[ytMin][xtMax] == 'F')
      )
      &&
      ((ter[ytMax][xtMin] == ' ') || (ter[ytMax][xtMin] == '+')|| (ter[ytMax][xtMin] == '$')|| (ter[ytMax][xtMin] == 'O')|| (ter[ytMax][xtMin] == '!')|| (ter[ytMax][xtMin] == 'F'))
  )
  );}else{
    return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy)
    && ((ter[y][x]==' ') || (ter[y][x]=='$') || (ter[y][x]=='!') || (ter[y][x]=='O') || (ter[y][x]=='+') || (ter[y][x]=='F') ));
}



}
