#include"Personnage.h"
#include<iostream>

using namespace std;

Personnage::Personnage(){
  x = 2;
  y = 2;

  vie = 20;
  sexe = 0;
  sens = 1;
  mort = false;
  nom = "mario";
  degat = 8;
  portee = 3;
  status = 0;
  status_o = status;
}

Personnage::Personnage(int vie, int sexe, string nom, int degat, int portee){
  x = 0;
  y = 0;
  this->vie = vie;
  this->sexe = sexe;
  this->nom = nom;
  this->degat = degat;
  this->portee = portee;
  sens = 1;
  status = 0;
  status_o = status;
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

bool Personnage::deplacer(char direction, const Terrain & t){

    if(direction == 'd' && t.estPositionPersoVide(x+1,y)){
      x++;
      updateStatus(2);//droite
      updateSens(1);
      return true;
    }else if(direction == 'q' && t.estPositionPersoVide(x-1,y)){
      x--;
      updateStatus(1);//gauche
      updateSens(0);
      return true;
    }else if(direction == 's' && t.estPositionPersoVide(x,y+1)){
      y++;
      updateStatus(3);//tomper
      return true;
    }else if(direction == 'z' && t.estPositionPersoVide(x,y-1)){
      y--;
      updateStatus(4);//sauter
      return true;
    }else{
      updateStatus(0);//idle
      updateSens(sens);
      return false;
    }
}

void Personnage::updateStatus(int s){
  status_o = status;
  status = s;
}
void Personnage::updateSens(int s){
  sens_o = sens;
  sens = s;
}
bool Personnage::deplacerVite(int n, char direction, const Terrain & t){
  for(int i = 0; i < n;i++){
    if(!deplacer(direction, t)){
      return false;
    }
  }
  return true;
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
int Personnage::getSens() const{
  return sens;
}
int Personnage::getSensO() const{
  return sens_o;
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
int Personnage::getStatus() const{
  return status;
}
int Personnage::getStatusO() const{
  return status_o;
}
