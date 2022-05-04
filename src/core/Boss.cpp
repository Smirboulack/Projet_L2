#include "Boss.h"
#include<iostream>

using namespace std;

Boss::Boss(){
  x = 15;
  y = 10;
  dir=-1;
  limg=x;
  limd=limg+10;
  bvie = 30;
  sens = 0;
  mort = false;
  degat = 8;
  portee = 3;
}

Boss::Boss(int bvie, int sens, int degat, int portee){
  x = 15;
  y = 10;
  dir=-1;
  limg=x;
  limd=limg+10;
  this->bvie = bvie;
  this->sens = sens;
  this->degat = degat;
  this->portee = portee;
}

Boss::~Boss(){
  x = 0;
  y = 0;
  bvie = 0;
  mort = true;
  degat = 0;
  portee = 0;
}

void Boss::subirDegat(int degat){
  if(degat <= bvie)
    bvie -= degat;
  else
    bvie = 0;
  if(bvie <= 0)
    setMort(true);
}

void Boss::setX(int x){
  this->x = x;
}
void Boss::setY(int y){
  this->y = y;
}
void Boss::setBvie(int bvie){
  this->bvie = bvie;
}

void Boss::setSens(int sens){
  this->sens = sens;
}
void Boss::setMort(bool mort){
  this->mort = mort;
}

void Boss::setDegat(int degat){
  this->degat = degat;
}

void Boss::setPortee(int portee){
  this->portee = portee;
}

int Boss::getX() const{
  return x;
}
int Boss::getY() const{
  return y;
}
int Boss::getBvie(){
  return bvie;
}


int Boss::getSens(){
  return sens;
}

bool Boss::getMort(){
  return mort;
}

int Boss::getDegat(){
  return degat;
}

int Boss::getPortee(){
  return portee;
}


void Boss::gauche(const Terrain &ter){
  if (ter.estPositionPersoValide(x-1,y)) x--;
}

void Boss::droite(const Terrain &ter){
  if (ter.estPositionPersoValide(x+1,y)) x++;
}

void Boss::bougeAutoBoss(const Terrain &ter){
    int xtmp;
    xtmp = x + dir;
    if (ter.estPositionPersoValide(xtmp,y)) {
        if(x==limg)dir=1;
        if(x==limd)dir=-1;
        x=xtmp;
    }
   if (!ter.estPositionPersoValide(xtmp,y)){
        limg=-x;
        dir=-dir;
    }

  if (dir==1){
    if(!ter.estPositionPersoValide(x+1,y) || ter.estPositionPersoValide(x+1,y+1)){
      dir=-dir;
    }
    if(!ter.estPositionPersoValide(x-1,y) || ter.estPositionPersoValide(x-1,y+1)){
      dir=-dir;
    }

  }
  
}

void Boss::versPerso(const Terrain & ter, const Personnage &p){
  if(ter.estPositionPersoValide(p.getX(),p.getY()) && ter.estPositionPersoValide(x,y)){
    if(p.getX()<getX()-5){dir=dir;}
    if(p.getX()>getX()+5){dir=-dir;}
  }
}