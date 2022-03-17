#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
using namespace std;

class Personnage{
  private:
    //position du personnage en x et y
    int x, y;
    //point de vie de personnage
    int vie;
    int sexe;
    //le sens du personnage 0 pour gauche et 1 pour droit
    int sens;
    //l'etat viant ou mort du personnage
    bool mort;
    //le nom du personnage
    string nom;
    //dégats du personnage
    int degat;
    //portée d'attaque du personnage
    int portee;
  public:
    //crée le personnage par défaut
    Personnage();
    //crée le personnage par des attributs
    Personnage(int vie, int sexe, string nom, int degat, int portee);
    //déstructeur
    ~Personnage();
    //pour déplacer le personnage
    void deplacer(char direction);

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
    int getX();
    int getY();
    int getVie();
    string getNom();
    int getSexe();
    int getSens();
    bool getMort();
    int getDegat();
    int getPortee();
};


#endif
