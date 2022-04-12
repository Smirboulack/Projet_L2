#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>

#include <iostream>
using namespace std;
const int TAILLE_SPRITE = 32;

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

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
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


//xs : x srcrect
//xd: x dstrect
void Image::draw_animation(int n, SDL_Renderer * renderer, int i, int x, int y, int w, int h){
  int ok;
  SDL_Rect r;
  SDL_Rect run[n];

  r.x = x;
  r.y = y;
  r.w = (w<0)?surface->w:w;
  r.h = (h<0)?surface->h:h;

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



sdlJeu::sdlJeu() : jeu(){

  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
    SDL_Quit();
    exit(1);
  }
  int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
  if( !(IMG_Init(imgFlags) & imgFlags)) {
      cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
      SDL_Quit();
      exit(1);
  }
  int dimx, dimy;
	dimx = jeu.getConstTerrain().getDimX() - 1;
	dimy = jeu.getConstTerrain().getDimY() - 1;
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;

  // Creation de la fenetre
  window = SDL_CreateWindow("Jeu1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx=800, dimy=500, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  if (window == NULL) {
      cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
      SDL_Quit();
      exit(1);
  }

  renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);


  im_mur.loadFromFile("data/#.png",renderer);
  im_ter.loadFromFile("data/T.png",renderer);
  im_grass.loadFromFile("data/G.png",renderer);
  im_grass_gauche.loadFromFile("data/[.png",renderer);
  im_grass_droite.loadFromFile("data/].png",renderer);
  im_mur_bas.loadFromFile("data/_.png",renderer);
  im_mur_bas_gauche.loadFromFile("data/(.png",renderer);
  im_mur_bas_droite.loadFromFile("data/).png",renderer);
  im_perso.loadFromFile("data/perso.png",renderer);
  im_background.loadFromFile("data/background.png",renderer);
  im_runright.loadFromFile("data/RunRight.png",renderer);
  im_runleft.loadFromFile("data/RunLeft.png",renderer);
  im_static.loadFromFile("data/Static.png",renderer);
  im_fall.loadFromFile("data/Fall.png",renderer);
}

sdlJeu::~sdlJeu () {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdlJeu::sdlAff(){
  int dimx, dimy;
  dimx = jeu.getConstTerrain().getDimX();
  dimy = jeu.getConstTerrain().getDimY();

  SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
  SDL_RenderClear(renderer);

  int x,y;
	const Terrain& ter = jeu.getConstTerrain();
	const Personnage& perso = jeu.getConstPersonnage();

  im_background.draw(renderer,0,0,dimx*TAILLE_SPRITE,dimy*TAILLE_SPRITE);
  // Afficher les sprites des murs et des pastilles
for (x=0;x<ter.getDimX();++x){
  for (y=0;y<ter.getDimY();++y){
      if (ter.getXY(x,y)=='#'){
        im_mur.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }else if(ter.getXY(x,y) == 'T'){
        im_ter.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }else if(ter.getXY(x,y) == 'G'){
        im_grass.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }else if(ter.getXY(x,y) == '['){
        im_grass_gauche.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }else if(ter.getXY(x,y) == ']'){
        im_grass_droite.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }else if(ter.getXY(x,y) == '('){
        im_mur_bas_gauche.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }else if(ter.getXY(x,y) == ')'){
        im_mur_bas_droite.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }else if(ter.getXY(x,y) == '_'){
        im_mur_bas.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }
  }
}
    int status = jeu.getStatus();
    if(status == 0){
      im_static.draw_animation(4, renderer,indiceStatic,perso.getX(),perso.getY(),TAILLE_SPRITE,TAILLE_SPRITE);
      indiceStatic = (indiceStatic + 1) % 4;
    }else if(status == 1){
      im_runright.draw_animation(10, renderer,indiceRunRight,perso.getX(),perso.getY(),TAILLE_SPRITE,TAILLE_SPRITE);
      indiceRunRight = (indiceRunRight + 1) % 10;
    }else if(status == 3){
      im_fall.draw_animation(4, renderer,indiceFall,perso.getX(),perso.getY(),TAILLE_SPRITE,TAILLE_SPRITE);
      indiceFall = (indiceFall + 1) % 4;
    }else if(status == 2){
      im_runleft.draw_animation(10, renderer,indiceRunLeft,perso.getX(),perso.getY(),TAILLE_SPRITE,TAILLE_SPRITE);
      indiceRunLeft = (indiceRunLeft + 1) % 10;
    }

//  im_perso.draw(renderer,perso.getX()*TAILLE_SPRITE,perso.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);


}

void sdlJeu::sdlBoucle(){
  bool quit = false;
  SDL_Event events;

  while(!quit){
    jeu.actionsAutomatiques();

    while(SDL_PollEvent(&events)){
      if(events.type == SDL_QUIT){
        quit = true;
      }else if(events.type == SDL_KEYDOWN){
        switch(events.key.keysym.scancode){
          case SDL_SCANCODE_LEFT:
            jeu.actionClavier(113,jeu.getTemps());
            break;
          case SDL_SCANCODE_RIGHT:
            jeu.actionClavier(100,jeu.getTemps());
            break;
          case SDL_SCANCODE_DOWN:
            jeu.actionClavier(115,jeu.getTemps());
            break;
          case SDL_SCANCODE_UP:
            jeu.actionClavier(122,jeu.getTemps());
            break;
          default:
            break;
        }
      }
    }
    sdlAff();
    SDL_Delay(90);
    SDL_RenderPresent(renderer);
  }
}
