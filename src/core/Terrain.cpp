#include "Terrain.h"
#include <iostream>
#include <cassert>
#include <unistd.h>
#include <fcntl.h>

// const int TAILLE_SPRITE = 36;
using namespace std;

Terrain::Terrain()
{
  dimx = 169;
  dimy = 20;
  choixniv = 1;
  loadMap("./data/Niveau" + std::to_string(choixniv) + ".txt");
  
}

Terrain::~Terrain()
{
  dimx = 0;
  dimy = 0;
}

bool Terrain::loadMap(const std::string pathname)
{
  char buf[1];
  int fd, nbrd;
  fd = open(pathname.c_str(), O_RDONLY);
  if (fd == -1)
  {
    cout << "Il y a plus de Map ou Erreur lors de ouvrir fichier Map" << endl;
    return EXIT_FAILURE;
  }

  for (int y = 0; y < dimy; y++)
  {
    for (int x = 0; x < dimx; x++)
    {
      nbrd = read(fd, buf, 1);
      // cout << buf[0];
      if (nbrd > 0 && (buf[0] == '\n' || buf[0] == '\r'))
      {
        nbrd = read(fd, buf, 1);
        ter[y][x] = buf[0];
      }
      else
      {
        ter[y][x] = buf[0];
      }
    }
  }

  close(fd);

  for (int y = 0; y < dimy; y++)
  {
    cout << y;
    for (int x = 0; x < dimx; x++)
    {
      cout << ter[y][x];
    }
    cout << endl;
  }

  return EXIT_SUCCESS;
}

void Terrain::afficherTerrain()
{
  for (int i = 0; i < dimx; i++)
  {
    for (int j = 0; j < dimy; j++)
    {
      cout << ter[i * dimx + j];
    }
    cout << endl;
  }
}

char Terrain::getXY(const int x, const int y) const
{
  assert(x >= 0);
  assert(y >= 0);
  assert(x < dimx);
  assert(y < dimy);
  return ter[y][x];
}

void Terrain::setXY(const int x, const int y, const char &c)
{
  assert(x >= 0);
  assert(y >= 0);
  assert(x < dimx);
  assert(y < dimy);
  ter[y][x] = c;
}

void Terrain::setVersion(const int &v) { version = v; }
void Terrain::setDimx(const int Dimx) { dimx = Dimx; }
void Terrain::setChoixniv(const int &n) { choixniv = n; }

int Terrain::getDimX() const { return dimx; }
int Terrain::getDimY() const { return dimy; }
int Terrain::getVersion() const { return version; }
int Terrain::getChoixniv() const { return choixniv; }

bool Terrain::estPositionPersoValide(const int x, const int y) const
{
  int xtMin = x / TAILLE_SPRITE;
  int ytMin = y / TAILLE_SPRITE;
  int xtMax = (x + TAILLE_SPRITE - 1) / TAILLE_SPRITE;
  int ytMax = (y + TAILLE_SPRITE - 1) / TAILLE_SPRITE;
  // cout << dimx * TAILLE_SPRITE << " " << dimy * TAILLE_SPRITE << endl;
  // cout << x << " " << y << endl;
  // cout << xtMin << " " << ytMin << endl;
  // cout << xtMax << " " << ytMax << endl;

  /*
  if(version==1){return ((x>=0) && (x+TAILLE_SPRITE<dimx*TAILLE_SPRITE) && (y>=0) && (y+TAILLE_SPRITE<dimy*TAILLE_SPRITE) && ((ter[ytMin][xtMin] == ' ') && (ter[ytMax][xtMax] == ' ') && (ter[ytMin][xtMax] == ' ') && (ter[ytMax][xtMin] == ' ')));
  }else{
      return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy)
      && ((ter[y][x]==' ') || (ter[y][x]=='$') || (ter[y][x]=='!') || (ter[y][x]=='O') || (ter[y][x]=='+') || (ter[y][x]=='F') ));
  }
  */

  if (version == 1)
  {
    return (
        (x >= 0) && (x + TAILLE_SPRITE < dimx * TAILLE_SPRITE) && (y >= 0) && (y + TAILLE_SPRITE < dimy * TAILLE_SPRITE) &&
        ((
             (ter[ytMin][xtMin] == ' ') || (ter[ytMin][xtMin] == '+') || (ter[ytMin][xtMin] == '$') || (ter[ytMin][xtMin] == 'O') || (ter[ytMin][xtMin] == '!') || (ter[ytMin][xtMin] == 'F') || (ter[ytMin][xtMin] == 'Y') || (ter[ytMin][xtMin] == '/') || (ter[ytMin][xtMin] == '^') || (ter[ytMin][xtMin] == '9')) &&
         ((ter[ytMax][xtMax] == ' ') || (ter[ytMax][xtMax] == '+') || (ter[ytMax][xtMax] == '$') || (ter[ytMax][xtMax] == 'O') || (ter[ytMax][xtMax] == '!') || (ter[ytMax][xtMax] == 'F') || (ter[ytMax][xtMax] == 'Y') || (ter[ytMax][xtMax] == '/') || (ter[ytMax][xtMax] == '=') || (ter[ytMax][xtMax] == '^') || (ter[ytMax][xtMax] == '9')) &&
         ((ter[ytMin][xtMax] == ' ') || (ter[ytMin][xtMax] == '+') || (ter[ytMin][xtMax] == '$') || (ter[ytMin][xtMax] == 'O') || (ter[ytMin][xtMax] == '!') || (ter[ytMin][xtMax] == 'F') || (ter[ytMin][xtMax] == 'Y') || (ter[ytMin][xtMax] == '/') || (ter[ytMin][xtMax] == '=') || (ter[ytMin][xtMax] == '^') || (ter[ytMin][xtMax] == '9')) &&
         ((ter[ytMax][xtMin] == ' ') || (ter[ytMax][xtMin] == '+') || (ter[ytMax][xtMin] == '$') || (ter[ytMax][xtMin] == 'O') || (ter[ytMax][xtMin] == '!') || (ter[ytMax][xtMin] == 'F') || (ter[ytMax][xtMin] == 'Y') || (ter[ytMax][xtMin] == '/') || (ter[ytMax][xtMin] == '=') || (ter[ytMax][xtMin] == '^') || (ter[ytMax][xtMin] == '9'))));
  }
  else
  {
    return ((x >= 0) && (x < dimx) && (y >= 0) && (y < dimy) && ((ter[y][x] == ' ') || (ter[y][x] == '$') || (ter[y][x] == '!') || (ter[y][x] == 'O') || (ter[y][x] == '+') || (ter[y][x] == 'F') || (ter[y][x] == 'Y') || (ter[y][x] == '/') || (ter[y][x] == '=') || (ter[y][x] == '^') || (ter[y][x] == '9')));
  }
}
/*
bool Terrain::estPositionMonstreValide(const int x, const int y) const
{
  int xtMin = x / TAILLE_SPRITE;
  int ytMin = y / TAILLE_SPRITE;
  int xtMax = (x + TAILLE_SPRITE - 1) / TAILLE_SPRITE;
  int ytMax = (y + TAILLE_SPRITE - 1) / TAILLE_SPRITE;
  // cout << dimx * TAILLE_SPRITE << " " << dimy * TAILLE_SPRITE << endl;
  // cout << x << " " << y << endl;
  // cout << xtMin << " " << ytMin << endl;
  // cout << xtMax << " " << ytMax << endl;

  
  if(version==1){return ((x>=0) && (x+TAILLE_SPRITE<dimx*TAILLE_SPRITE) && (y>=0) && (y+TAILLE_SPRITE<dimy*TAILLE_SPRITE) && ((ter[ytMin][xtMin] == ' ') && (ter[ytMax][xtMax] == ' ') && (ter[ytMin][xtMax] == ' ') && (ter[ytMax][xtMin] == ' ')));
  }else{
      return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy)
      && ((ter[y][x]==' ') || (ter[y][x]=='$') || (ter[y][x]=='!') || (ter[y][x]=='O') || (ter[y][x]=='+') || (ter[y][x]=='F') ));
  }
  

  if (version == 1)
  {
    return (
        (x >= 0) && (x + TAILLE_SPRITE < dimx * TAILLE_SPRITE) && (y >= 0) && (y + TAILLE_SPRITE < dimy * TAILLE_SPRITE) &&
        ((
             (ter[ytMin][xtMin] == ' ') || (ter[ytMin][xtMin] == '+') || (ter[ytMin][xtMin] == '$') || (ter[ytMin][xtMin] == 'O') || (ter[ytMin][xtMin] == '!') || (ter[ytMin][xtMin] == 'F') || (ter[ytMin][xtMin] == 'Y') || (ter[ytMin][xtMin] == '/') || (ter[ytMin][xtMin] == '9')) &&
         ((ter[ytMax][xtMax] == ' ') || (ter[ytMax][xtMax] == '+') || (ter[ytMax][xtMax] == '$') || (ter[ytMax][xtMax] == 'O') || (ter[ytMax][xtMax] == '!') || (ter[ytMax][xtMax] == 'F') || (ter[ytMax][xtMax] == 'Y') || (ter[ytMax][xtMax] == '/') || (ter[ytMax][xtMax] == '9')) &&
         ((ter[ytMin][xtMax] == ' ') || (ter[ytMin][xtMax] == '+') || (ter[ytMin][xtMax] == '$') || (ter[ytMin][xtMax] == 'O') || (ter[ytMin][xtMax] == '!') || (ter[ytMin][xtMax] == 'F') || (ter[ytMin][xtMax] == 'Y') || (ter[ytMin][xtMax] == '/') || (ter[ytMin][xtMax] == '9')) &&
         ((ter[ytMax][xtMin] == ' ') || (ter[ytMax][xtMin] == '+') || (ter[ytMax][xtMin] == '$') || (ter[ytMax][xtMin] == 'O') || (ter[ytMax][xtMin] == '!') || (ter[ytMax][xtMin] == 'F') || (ter[ytMax][xtMin] == 'Y') || (ter[ytMax][xtMin] == '/') || (ter[ytMax][xtMin] == '9'))));
  }
  else
  {
    return ((x >= 0) && (x < dimx) && (y >= 0) && (y < dimy) && ((ter[y][x] == ' ') || (ter[y][x] == '$') || (ter[y][x] == '!') || (ter[y][x] == 'O') || (ter[y][x] == '+') || (ter[y][x] == 'F') || (ter[y][x] == 'Y') || (ter[y][x] == '/') || (ter[y][x] == '=') || (ter[y][x] == '^') || (ter[y][x] == '9')));
  }
}
*/

