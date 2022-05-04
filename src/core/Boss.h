#ifndef _BOSS_H
#define _BOSS_H

#include "Terrain.h"
#include "Personnage.h"

class Terrain;
class Personnage;

class Boss{
  private:
    //position du Boss en x et y
    int x, y;
    int limg, limd;
    int dir;
    //point de vie du Boss
    int bvie;
    //le sens du personnage 0 pour gauche et 1 pour droit
    int sens;
    //l'etat viant ou mort du Boss
    bool mort;
    //dégats du Boss
    int degat;
    //portée d'attaque du personnage
    int portee;
  public:
    //crée le Boss par défaut
    Boss();
    //crée le Boss par des attributs
    Boss(int bvie, int sens, int degat, int portee);
    //déstructeur
    ~Boss();
    //Methode permettant au Boss de perdre des pvs et mourrir
    void subirDegat(int degat);

    //des getter et setter
    void setX(int x);
    void setY(int y);
    void setBvie(int bvie);
    void setSens(int sens);
    void setMort(bool mort);
    void setDegat(int degat);
    void setPortee(int portee);

    int getX() const;
    int getY() const;
    int getBvie();
    int getSens();
    bool getMort();
    int getDegat();
    int getPortee();


    void gauche(const Terrain &ter);
    void droite(const Terrain &ter);
    void bougeAutoBoss(const Terrain &ter);
    void versPerso(const Terrain & ter, const Personnage &p);

    void testRegression();


};

#endif