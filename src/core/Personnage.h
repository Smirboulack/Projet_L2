#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
#include "Terrain.h"

class Terrain;
const int VITESSE_SAUTER = 6;     //!< \brief constante de la vitesse de saut
const int VITESSE_ACCELEREE = 20; //!< \brief constante utilisé pour la gravité du personnage
const int NbMonstre = 18;         //!< \brief constante pour spécifier le nombre de monstre
class Personnage
{
private:
  int x, y;            //!< \brief position du personnage en x et y
  int vie;             //!< \brief point de vie de personnage
  bool sexe;           //!< \brief booleen : 0 pour personnage masculin 1 pour personnage feminin
  int sens;            //!< \brief le sens du personnage -1 pour gauche et 1 pour droit
  int sens_o;          //!< \brief le sens précedent du personnage
  bool mort;           //!< \brief l'etat viant ou mort du personnage
  std::string nom;     //!< \brief le nom du personnage
  int degat;           //!< \brief dégats du personnage
  int portee;          //!< \brief portée d'attaque du personnage
  int Armure;          //!< \brief armure du personnage
  bool arme;           //!< \brief Possession d'une arme ou non
  int piece;           //!< \brief Piece du personnage
  int status;          //!< \brief status de Personnage , idle:0 , left:1 ,  right:2 ,  down:3 , up:4
  int status_o;        //!< \brief status précédant du Personnage
  int vitesse_gravite; //!< \brief entier qui servira à gérer la vitesse gravitationnelle du personnage
  bool saute;          //!< \brief booléen qui permet de savoir si le personnage est en saut ou non

public:
  /**
   * @brief le constructeur par défaut de Personnage
   *
   */
  Personnage();
  /**
   * @brief le constructeur paramétré de Personnage
   *
   * @param x la coordonnée x
   * @param y la coordonnée y
   * @param vie les points de vie
   * @param degat les degats qu'ils infligent
   * @param portee la portée de son attaque
   * @param nom son nom
   */
  Personnage(int x, int y, int vie, int degat, int portee, std::string nom);
  /**
   * @brief Le destructeur de Personnage
   *
   */
  ~Personnage();
  /**
   * @brief la fonction qui permet le déplacement du personnage
   * @param direction le direction voulue
   * @param t le terrain
   * @return true
   * @return false
   */
  bool deplacer(char direction, const Terrain &t);
  /**
   * @brief la fonction qui permet le déplacement du monstre
   * @param direction le direction voulue
   * @param t le terrain
   * @return true
   * @return false
   */
  bool deplacerMonstre(char direction, const Terrain &t);
  /**
   * @brief la fonction qui permet le déplacement rapide du personnage
   *
   * @param n la vitesse souhaitée
   * @param direction le direction voulue
   * @param t le terrain
   * @return true
   * @return false
   */
  bool deplacerVite(int n, char direction, const Terrain &t);
  /**
   * @brief La procédure qui fait subir les dégats et réduit les points de vie du personnage
   *
   * @param degat le nombre de dégat subi
   */
  void subirDegat(int degat);
  /**
   * @brief la procédure de mise à jour du statut
   *
   * @param s le nouveau statut
   */
  void updateStatus(int s);
  /**
   * @brief la procédure de mise à jour du sens
   *
   */
  void updateSens(int s);
  /**
   * @brief la procédure qui permet au héros de sauter
   *
   * @param ter le terrain
   */
  void sauter(const Terrain &ter);
  /**
   * @brief la procédure qui applique la gravité au Personnage
   *
   * @param ter le terrain
   */
  void gravite(const Terrain &ter);
  /**
   * @brief la procédure qui permet au héros d'attaquer
   *
   * @param perso le Personnage à attaquer
   */
  void attaquer(Personnage &perso);
  /**
   * @brief Mutateur de x
   *
   */
  void setX(int x);
  /**
   * @brief Mutateur de y
   *
   */
  void setY(int y);
  /**
   * @brief Mutateur de vie
   *
   */
  void setVie(int vie);
  /**
   * @brief Mutateur du sexe
   *
   */
  void setSexe(bool sexe);
  /**
   * @brief Mutateur du sens
   *
   */
  void setSens(int sens);
  /**
   * @brief Mutateur de mort
   *
   */
  void setMort(bool mort);
  /**
   * @brief Mutateur du nom
   *
   */
  void setNom(std::string nom);
  /**
   * @brief Mutateur de degat
   *
   */
  void setDegat(int degat);
  /**
   * @brief Mutateur de portée
   *
   */
  void setPortee(int portee);
  /**
   * @brief Mutateur de piece
   *
   */
  void setPiece(int piece);
  /**
   * @brief Mutateur de armure
   *
   */
  void setArmure(int armure);
  /**
   * @brief Mutateur de arme
   *
   */
  void setArme(bool b);
  /**
   * @brief Procédure qui permet de modifier la valeur du booléen saut
   *@param saute mutateur de la donnée membre saut
   *
   */
  void setSaute(bool saute);

  /**
   * @brief Accesseur de x
   *
   * @return int la coordonnée x
   */
  int getX() const;
  /**
   * @brief Accesseur de y
   *
   * @return int la coordonnée y
   */
  int getY() const;
  /**
   * @brief Accesseur de l'ancien x
   *
   * @return int la coordonnée ancienne x
   */
  int getXO() const;
  /**
   * @brief Accesseur de l'ancien y
   *
   * @return int la coordonnée ancienne y
   */
  int getYO() const;
  /**
   * @brief Accesseur de vie
   *
   * @return int la donnée-membre vie
   */
  int getVie();
  /**
   * @brief Accesseur de nom
   *
   * @return int la donnée-membre nom
   */
  std::string getNom();
  /**
   * @brief Accesseur du sexe
   *
   * @return bool la donnée-membre sexe
   */
  bool getSexe();
  /**
   * @brief Accesseur de sens
   *
   * @return int la donnée-membre sens
   */
  int getSens() const;
  /**
   * @brief Accesseur de l'ancien sens
   *
   * @return int la donnée-membre sens_o
   */
  int getSensO() const;
  /**
   * @brief Accesseur de mort
   *
   * @return bool la donnée-membre mort
   */
  bool getMort();
  /**
   * @brief Accesseur de degat
   *
   * @return int la donnée-membre degat
   */
  int getDegat();
  /**
   * @brief Accesseur de portée
   *
   * @return int la donnée-membre portée
   */
  int getPortee();
  /**
   * @brief Accesseur de statut
   *
   * @return int la donnée-membre statut
   */
  int getStatus() const;
  /**
   * @brief Accesseur de l'ancien statut
   *
   * @return int la donnée-membre statut_o
   */
  int getStatusO() const;
  /**
   * @brief Accesseur de piece
   *
   * @return int la donnée-membre piece
   */
  int getPiece();
  /**
   * @brief Accesseur de armure
   *
   * @return int la donnée-membre armure
   */
  int getArmure();
  /**
   * @brief Accesseur de arme
   *
   * @return bool la donnée-membre arme
   */
  bool getArme();
  /**
   * @brief Fonction accesseur qui renvoie le booléen saut
   *
   */
  bool getSaute();

  /**
   * @brief La procédure qui permet au monstre de se diriger vers le héros
   *
   * @param ter le terrain
   * @param p le héros
   */
  void versPerso(const Terrain &ter, const Personnage &p);
  /**
   * @brief Procédure de test de Personnage
   *
   */
  void testRegression();
};

#endif
