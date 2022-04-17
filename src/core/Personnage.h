#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
#include "Terrain.h"
using namespace std;

class Terrain;

class Personnage{
  private:
    //position du personnage en x et y
    int x, y;
    //point de vie de personnage
    int vie;
    int sexe;
    //le sens du personnage 0 pour gauche et 1 pour droit
    int sens;
    //le sens d'avant
    int sens_o;
    //l'etat viant ou mort du personnage
    bool mort;
    //le nom du personnage
    string nom;
    //dégats du personnage
    int degat;
    //portée d'attaque du personnage
    int portee;
    int Armure;
    //Piece du personnage
    int piece;
    //status de Personnage
    //idle:0
    //left:1
    //right:2
    //down:3
    //up:4
    int status;
    //status avant de Personnage
    int status_o;
  public:
    //crée le personnage par défaut
    Personnage();
    //crée le personnage par des attributs
    Personnage(int vie, int sexe, string nom, int degat, int portee);
    //déstructeur
    ~Personnage();
    //pour déplacer le personnage
    bool deplacer(char direction,const Terrain & t);
    //Methode permettant au personnage de perdre des pvs et mourrir
    bool deplacerVite(int n, char direction, const Terrain & t);
    void subirDegat(int degat);
    //s: new status
    void updateStatus(int s);
    //s:new sens
    void updateSens(int s);
    //des getter et setter
    void setX(int x);
    void setY(int y);
    void setVie(int vie);
    void setSexe(int sexe);
    void setSens(int sens);
    void setMort(bool mort);
    void setNom(string nom);
    void setDegat(int degat);
    void setPortee(int portee);
    void setPiece(int piece);
    void setArmure(int armure);
    int getX() const;
    int getY() const;
    int getXO() const;
    int getYO() const;
    int getVie();
    string getNom();
    int getSexe();
    int getSens() const;
    int getSensO() const;
    bool getMort();
    int getDegat();
    int getPortee();
    int getStatus() const;
    int getStatusO() const;
    int getPiece();
    int getArmure();
};


#endif
