#include <iostream>
#include "Personnage.h"

using namespace std;

Personnage::Personnage(){
  x = 0;
  y = 0;
  vie = 20;
  sexe = 0;
  sens = 1;
  mort = false;
  nom = "mario";
  Armure = 0;
  degat = 1;
  arme = false;
  portee = 3;
  piece=0;
  status = 0;
  status_o = status;
  vitesse_gravite = VITESSE_ACCELEREE;
}

Personnage::Personnage(int x, int y, int vie, int degat, int portee, string monst){
  this->x = x;
  this->y = y;
  this->vie = vie;
  this->sexe = sexe;
  this->nom = monst;
  this->degat = degat;
  this->portee = portee;
  sens = 1;
  status = 0;
  status_o = status;
  vitesse_gravite = VITESSE_ACCELEREE;
}

Personnage::~Personnage(){
  x = 0;
  y = 0;
  vie = 0;
  mort = true;
  nom = "";
  degat = 0;
  portee = 0;
  piece=0;
}

bool Personnage::deplacer(char direction, const Terrain & t){

    if(direction == 'd' && t.estPositionPersoValide(x+1,y)){
      x++;
      updateStatus(2);//droite
      updateSens(1);
      return true;
    }else if(direction == 'q' && t.estPositionPersoValide(x-1,y)){
      x--;
      updateStatus(1);//gauche
      updateSens(-1);
      return true;
    }else if(direction == 's' && t.estPositionPersoValide(x,y+1)){
      y++;
      updateStatus(3);//tomper
      return true;
    }else if(direction == 'z' && t.estPositionPersoValide(x,y-1)){
      y--;
      updateStatus(4);//sauter
      return true;
    }else{
      updateStatus(0);//idle
      updateSens(sens);
      return false;
    }
}
/*
bool Personnage::deplacerMonstre(char direction, const Terrain & t){

      if(direction == 'd' && t.estPositionMonstreValide(x+1,y+1) && t.estPositionMonstreValide(x+1,y+2) ){
      x++;
      updateStatus(2);//droite
      updateSens(1);
      return true;
    }else if(direction == 'q' && t.estPositionMonstreValide(x-1,y-1) && t.estPositionMonstreValide(x-1,y-2)){
      x--;
      updateStatus(1);//gauche
      updateSens(-1);
      return true;
    }else if(direction == 's' && t.estPositionMonstreValide(x,y+1)){
      y++;
      updateStatus(3);//tomper
      return true;
    }else if(direction == 'z' && t.estPositionMonstreValide(x,y-1)){
      y--;
      updateStatus(4);//sauter
      return true;
    }else{
      updateStatus(0);//idle
      updateSens(sens);
      return false;
    }
}
*/
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


void Personnage::attaquer(Personnage & perso){
  if(getArme())
  {
    if((x + portee * sens >= perso.getX() && y == perso.getY())) perso.subirDegat(degat);
    updateStatus(5);
  }
}


void Personnage::sauter(const Terrain & ter){
  if(VITESSE_SAUTER-(vitesse_gravite/VITESSE_ACCELEREE) > 0){
    deplacerVite(VITESSE_SAUTER-(vitesse_gravite/VITESSE_ACCELEREE), 'z', ter);
  }else{
    deplacerVite(-(VITESSE_SAUTER-(vitesse_gravite/VITESSE_ACCELEREE)), 's', ter);
  }
  vitesse_gravite++;
}

void Personnage::gravite(const Terrain & ter){
  if(deplacerVite(vitesse_gravite/VITESSE_ACCELEREE, 's', ter)){
    vitesse_gravite++;
  }else{
    vitesse_gravite = VITESSE_ACCELEREE;
  }
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
void Personnage::setSexe(bool sexe){
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

void Personnage::setPiece(int piece){
  this->piece = piece;
}

void Personnage::setArmure(int armure){
  this->Armure = armure;
}

void Personnage::setArme(bool b)
{
  this->arme = b;
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
bool Personnage::getSexe(){
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

int Personnage::getArmure(){
  return Armure;
}

int Personnage::getPiece(){
  return piece;
}

int Personnage::getStatus() const{
  return status;
}
int Personnage::getStatusO() const{
  return status_o;
}

bool Personnage::getArme()
{
  return arme;
}

