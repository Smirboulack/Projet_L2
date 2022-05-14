#include <assert.h>
#include "sdlJeu.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

Image::Image () {
    surface = NULL;
    texture = NULL;
    has_changed = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    //SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    //SDL_FreeSurface(surface);
    //surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}


//
//n: animation à n image
//i: image actuel
void Image::draw_animation(int n, SDL_Renderer * renderer, int i, int x, int y, int w, int h){
  int ok;
  SDL_Rect r;
  SDL_Rect run[n];

  r.x = x;
  r.y = y;
  r.w = (w<0)?surface->w:w;
  r.h = (h<0)?surface->h:h;
  //on range les images dans chaque case
  for(int i = 0;i < n;i++){
    run[i].w = surface->w / n;
    run[i].h = surface->h;
    run[i].x = i*run[i].w;
    run[i].y = 0;
  }

  if (has_changed) {
      ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
      assert(ok == 0);
      has_changed = false;
  }

  ok = SDL_RenderCopy(renderer,texture,&run[i],&r);
  assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return texture;}

void Image::setSurface(SDL_Surface * surf) {surface = surf;}
