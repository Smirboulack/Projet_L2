#include "../../src/core/Terrain.h"
#include "../../src/core/Personnage.h"
//Le camera qui suivre le personnage
class Camera{
    public:
      //Le dimension de camera par pixels
      const int TAILLE_SPRITE = 36;
      const int CAMERA_WIDTH = 25 * TAILLE_SPRITE;
      const int CAMERA_HEIGHT = 20 * TAILLE_SPRITE;

      //Initialisation des variables
      Camera();
      //Destroy
      ~Camera();
      //decalage de x
      int decalageX(const Personnage & perso, const Terrain & ter);

      void testRegression();
/*
    private:
      //Coordonnées horizontales à gauche et à droite de camera
      int xG,xD;

      //Coordonnées verticales à gauche et à droite de camera
      int yH,yB;
*/
};
