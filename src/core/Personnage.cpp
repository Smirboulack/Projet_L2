#include"Personnage.h"
#include<iostream>

using namespace std;

Personnage::Personnage(){
  x = 2;
  y = 2;
  vie = 20;
  sexe = 0;
  sens = 0;
  mort = false;
  nom = "mario";
  degat = 8;
  portee = 3;
}

Personnage::Personnage(int vie, int sexe, string nom, int degat, int portee){
  x = 0;
  y = 0;
  this->vie = vie;
  this->sexe = sexe;
  this->nom = nom;
  this->degat = degat;
  this->portee = portee;
}

Personnage::~Personnage(){
  x = 0;
  y = 0;
  vie = 0;
  mort = true;
  nom = "";
  degat = 0;
  portee = 0;
}

void Personnage::deplacer(char direction, const Terrain & t){
    if(direction == 'd' && t.estPositionPersoValide(x+1,y)){
      x++;
    }
    if(direction == 'q' && t.estPositionPersoValide(x-1,y)){
      x--;
    }
    if(direction == 's' && t.estPositionPersoValide(x,y+1)){
      y++;
    }
    if(direction == 'z' && t.estPositionPersoValide(x,y-1)){
      y--;
    }
}
void Personnage::deplacerVite(int n, char direction, const Terrain & t){
  for(int i = 0; i < n;i++){
    deplacer(direction, t);
  }
}

void Personnage::subirDegat(int degat){
  if(degat <= vie)
    vie -= degat;
  else
    vie = 0;
  if(vie <= 0)
    setMort(true);
}

void Personnage::setX(int x){
  this->x = x;
}
void Personnage::setY(int y){
  this->y = y;
}
void Personnage::setVie(int vie){
  this->vie = vie;
}
void Personnage::setSexe(int sexe){
  this->sexe = sexe;
}
void Personnage::setSens(int sens){
  this->sens = sens;
}
void Personnage::setMort(bool mort){
  this->mort = mort;
}
void Personnage::setNom(string nom){
  this->nom = nom;
}
void Personnage::setDegat(int degat){
  this->degat = degat;
}
void Personnage::setPortee(int portee){
  this->portee = portee;
}
int Personnage::getX() const{
  return x;
}
int Personnage::getY() const{
  return y;
}
int Personnage::getVie(){
  return vie;
}
string Personnage::getNom(){
  return nom;
}
int Personnage::getSexe(){
  return sexe;
}
int Personnage::getSens(){
  return sens;
}
bool Personnage::getMort(){
  return mort;
}
int Personnage::getDegat(){
  return degat;
}
int Personnage::getPortee(){
  return portee;
}
