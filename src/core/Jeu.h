#ifndef _JEU_H
#define _JEU_H

#include "Personnage.h"
#include "Terrain.h"
//#include "Monstre.h"


class Jeu
{

private:
  Terrain ter;
  Personnage perso;
  Personnage monst;
  Personnage tabmonstre[10];

  bool Fdj;

public:
  Jeu();

  Terrain &getTerrain();
  Personnage &getPerso();
  Personnage &getMonstre();
  Personnage &getMonstre(const int &i);

  const Terrain &getConstTerrain() const;
  const Personnage &getConstPersonnage() const;
  const Personnage &getConstMonstre() const;
  const Personnage &getConstMonstre(const int &i)const;
  //int getNombreMonstre() const;
  int getStatus() const;
  int getStatusO() const;
  int getSens() const;
  int getSensO() const;

  void actionsAutomatiques();
  // bool actionClavier(const int touche, int tps);
  bool actionClavier(const int touche);
  void gravite();
  void ramasserItems();
  void PersoSubirDegat();
  bool getFdj();
  void setFdj(bool fdj);
  void niveauSuivant();
  void initMonstre();

  void testRegression();
};

#endif
