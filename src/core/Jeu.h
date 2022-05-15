#ifndef _JEU_H
#define _JEU_H

#include "Personnage.h"
#include "Terrain.h"
//#include "Monstre.h"

class Jeu
{

private:
  Terrain ter;      // Le terrain pour jouer
  Personnage perso; // Le persnnage que nous pouvons incarner (le héros)
  Personnage monst;
  Personnage tabmonstre[10]; // La liste de monstres présents sur le terrain

  bool Fdj; // Le booléen qui indique si la partie est terminée

public:
  /**
   * @brief Construct du jeu faisant appel aux autres constrcteurs
   * 
   */
  Jeu();

  /**
   * @brief Accesseur du terrain ter
   * 
   * @return le Terrain& ter
   */
  Terrain &getTerrain();
  /**
   * @brief Acceseur du personnage perso
   * 
   * @return le Personnage& perso
   */
  Personnage &getPerso();
  Personnage &getMonstre();
  /**
   * @brief Accesseur du ieme monstre
   * 
   * @param i l'indice du monstre dans le tableau
   * @return le Personnage& monstre d'indice i
   */
  Personnage &getMonstre(const int &i);

  /**
   * @brief Accesseur du terrain ter en donnée
   * 
   * @return le const Terrain& ter en donnée
   */
  const Terrain &getConstTerrain() const;
  /**
   * @brief Accesseur du Personnage perso en donnée
   * 
   * @return le const Personnage& perso en donnée 
   */
  const Personnage &getConstPersonnage() const;
  const Personnage &getConstMonstre() const;
  /**
   * @brief Accesseur du ieme monstre
   * 
   * @param il'indice du monstre dans le tableau
   * @return le const Personnage& monstre d'indice i en donnée
   */
  const Personnage &getConstMonstre(const int &i) const;
  // int getNombreMonstre() const;
  /**
   * @brief Accesseur du statut actuel du personnage
   * 
   * @return entier correspondant au statut
   */
  int getStatus() const;
  /**
   * @brief Accesseur de l'ancien statut du personnage
   * 
   * @return entier correspondant au statut
   */
  int getStatusO() const;
  /**
   * @brief Accesseur du sens du personnage
   * 
   * @return entier correspondant au sens
   */
  int getSens() const;
  /**
   * @brief Accesseur de l'ancien sens du personnage
   * 
   * @return entier correspondant au sens
   */
  int getSensO() const;

  /**
   * @brief La procédure appellée en boucle qui execute les actions automatiques
   * 
   */
  void actionsAutomatiques();
  /**
   * @brief La fonction d'initaialisation des monstres
   * 
   */
  void initMonstre();
  // bool actionClavier(const int touche, int tps);
  /**
   * @brief la fonction qui fait appel à la procédure correspondante à la touche pressée
   * 
   * @param touche la touche pressée
   * @return true 
   * @return false 
   */
  bool actionClavier(const int touche);
  /**
   * @brief La fonction qui applique la gravité sur le terrain
   * 
   */
  void gravite();
  /**
   * @brief La procédure qui permet au héros de ramasser les items
   * 
   */
  void ramasserItems();
  /**
   * @brief La procédure qui permet de gérer la collision entre le héros et les monstres
   * 
   */
  void PersoSubirDegat();
  /**
   * @brief La procédure qui permet de vérifier si le jeu doit se terminer ou non
   * 
   */
  void FinDuJeu();
  /**
   * @brief La procéudure qui permet le passage aux niveaux suivants
   * 
   */
  void niveauSuivant();
  /**
   * @brief Acceseur à la variable fdj (findujeu)
   * 
   * @return fdj le booléen qui indique si le jeu doit se terminer
   */
  bool getFdj();
  /**
   * @brief Mutateur de fdj
   * 
   * @param fdj le booléen qu'on affecte à la donnée-membre fdj
   */
  void setFdj(bool fdj);
  void testRegression();
};

#endif
