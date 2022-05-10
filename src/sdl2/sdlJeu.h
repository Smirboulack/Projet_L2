#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "../core/Jeu.h"
#include "Image.h"
#include "../core/Camera.h"

class sdlJeu{
private:
  Jeu jeu;

  SDL_Window * window;
  SDL_Renderer * renderer;
  SDL_Surface * im_icon;
  //SDL_Event event;

  Image im_menu;
  Image im_mortperso;
  Image im_mur;
  Image im_background;
  Image im_ciel;
  Image im_ter;
  Image im_grass;
  Image im_grass_gauche;
  Image im_grass_droite;
  Image im_mur_bas;
  Image im_mur_bas_gauche;
  Image im_mur_bas_droite;
  Image im_runright;
  Image im_runleft;
  Image im_idleright;
  Image im_idleleft;
  Image im_fallleft;
  Image im_fallright;
  Image im_jumpleft;
  Image im_jumpright;
  Image im_turnleft;
  Image im_turnright;
  Image im_item;
  Image im_vie;
  Image im_money;

    Mix_Chunk * sound;
    bool withSound;

  Camera camera;

  int i = 0;
public:
  //taille de chaque case par pixels
  const int TAILLE_SPRITE = 36;
  //FPS pour animation après FPS meme images on change à l'images suivante
  const int FPS = 20;
  sdlJeu();
  ~sdlJeu();

  void sdlBoucle();
  void sdlAff();
  void drawTerrain();
  void drawPersonnage();
  void drawMenu();


  void testRegression();

};

#endif
