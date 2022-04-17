#ifndef _MONSTRE_H
#define _MONSTRE_H

#include "Terrain.h"
#include "Personnage.h"

class Terrain;
class Personnage;

class Monstre{
  private:
    //position du monstre en x et y
    int x, y;

    int limg, limd;
    int dir;
    //point de vie du monstre
    int mvie;
    //le sens du personnage 0 pour gauche et 1 pour droit
    int sens;
    //l'etat viant ou mort du monstre
    bool mort;
    //dégats du monstre
    int degat;
    //portée d'attaque du personnage
    int portee;
  public:
    //crée le monstre par défaut
    Monstre();
    //crée le monstre par des attributs
    Monstre(int mvie, int sens, int degat, int portee);
    //déstructeur
    ~Monstre();
    //Methode permettant au monstre de perdre des pvs et mourrir
    void subirDegat(int degat);

    //des getter et setter
    void setX(int x);
    void setY(int y);
    void setMvie(int mvie);
    void setSens(int sens);
    void setMort(bool mort);
    void setDegat(int degat);
    void setPortee(int portee);

    int getX() const;
    int getY() const;
    int getMvie();
    int getSens();
    bool getMort();
    int getDegat();
    int getPortee();


    void gauche(const Terrain &ter);
    void droite(const Terrain &ter);
    void bougeAutoMonstre(const Terrain &ter);
    void versPerso(const Terrain & ter, const Personnage &p);


};

#endif