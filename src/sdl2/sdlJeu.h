#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../core/Jeu.h"

class Image {

private:

    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_changed;

public:
    Image () ;
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    void draw_animation(int n, SDL_Renderer * renderer, int i, int x, int y, int w, int h);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
    void animationRun();
};

class sdlJeu{
private:
  Jeu jeu;

  SDL_Window * window;
  SDL_Renderer * renderer;

  Image im_mur;
  Image im_background;
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
  Image im_fall;

  int i = 0;
public:
  sdlJeu();
  ~sdlJeu();
  void sdlBoucle();
  void sdlAff();


};

#endif
