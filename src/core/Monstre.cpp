#include "Monstre.h"
#include<iostream>

using namespace std;

Monstre::Monstre(){
  x = 0;
  y = 0;
  mvie = 30;
  sens = 0;
  mort = false;
  degat = 8;
  portee = 3;
}

Monstre::Monstre(int mvie, int sens, int degat, int portee){
  x = 0;
  y = 0;
  this->mvie = mvie;
  this->sens = sens;
  this->degat = degat;
  this->portee = portee;
}

Monstre::~Monstre(){
  x = 0;
  y = 0;
  mvie = 0;
  mort = true;
  degat = 0;
  portee = 0;
}

void Monstre::subirDegat(int degat){
  if(degat <= mvie)
    mvie -= degat;
  else
    mvie = 0;
  if(mvie <= 0)
    setMort(true);
}

void Monstre::setX(int x){
  this->x = x;
}
void Monstre::setY(int y){
  this->y = y;
}
void Monstre::setMvie(int mvie){
  this->mvie = mvie;
}

void Monstre::setSens(int sens){
  this->sens = sens;
}
void Monstre::setMort(bool mort){
  this->mort = mort;
}

void Monstre::setDegat(int degat){
  this->degat = degat;
}

void Monstre::setPortee(int portee){
  this->portee = portee;
}

int Monstre::getX() const{
  return x;
}
int Monstre::getY() const{
  return y;
}
int Monstre::getMvie(){
  return mvie;
}


int Monstre::getSens(){
  return sens;
}

bool Monstre::getMort(){
  return mort;
}

int Monstre::getDegat(){
  return degat;
}

int Monstre::getPortee(){
  return portee;
}
