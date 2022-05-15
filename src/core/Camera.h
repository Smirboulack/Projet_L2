#include "../../src/core/Terrain.h"
#include "../../src/core/Personnage.h"
// Le camera qui suivre le personnage
class Camera
{
public:
  // Le dimension de camera par pixels
  const int TAILLE_SPRITE = 36;                 //!< \brief Le terrain pour jouer
  const int CAMERA_WIDTH = 25 * TAILLE_SPRITE;  //!< \brief Le terrain pour jouer
  const int CAMERA_HEIGHT = 20 * TAILLE_SPRITE; //!< \brief Le terrain pour jouer

  /**
   * @brief le constructeur de caméra
   *
   */
  Camera();
  /**
   * @brief le destructeur de caméra
   *
   */
  ~Camera();
  /**
   * @brief La fonction qui calcule le décalage à appliquer pour le déplacement du terrain
   *
   * @param perso le héros
   * @param ter le terrain
   * @return int le décalage
   */
  int decalageX(const Personnage &perso, const Terrain &ter);
  /**
   * @brief Procédure test de Camera
   *
   */
  void testRegression();
  /*
      private:
        //Coordonnées horizontales à gauche et à droite de camera
        int xG,xD;

        //Coordonnées verticales à gauche et à droite de camera
        int yH,yB;
  */
};
