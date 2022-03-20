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
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
};




class sdlJeu{
private:
  Jeu jeu;

  SDL_Window * window;
  SDL_Renderer * renderer;

  Image im_mur;
  Image im_perso;
  Image im_background;
  Image im_ter;
  Image im_grass;
  Image im_grass_gauche;
  Image im_grass_droite;
  Image im_mur_bas;
  Image im_mur_bas_gauche;
  Image im_mur_bas_droite;

public:
  sdlJeu();
  ~sdlJeu();
  void sdlBoucle();
  void sdlAff();
};

#endif