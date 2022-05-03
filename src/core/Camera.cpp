#include "Camera.h"
#include <iostream>
Camera::Camera(){
  /*
  xG = 0;
  xD = xG + CAMERA_WIDTH;
  yH = 0;
  yB = yH + CAMERA_HEIGHT;
  */
}

Camera::~Camera(){
/*
  xG = 0;
  xD = 0;
  yH = 0;
  yB = 0;
*/
}

int Camera::decalageX(const Personnage & perso, const Terrain & ter){
  int x = perso.getX();
  int dimx = ter.getDimX() * TAILLE_SPRITE;
  //position x de plus gauche et droite de camera
  int gauche = x - (CAMERA_WIDTH / 2);
  int droite = x + (CAMERA_WIDTH / 2);
  if(gauche <= 0){
    return 0;
  }else if(droite >= dimx){
    return dimx - CAMERA_WIDTH;
  }else{
    return gauche;
  }
}
