#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>

#include <iostream>
using namespace std;

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
	dimx = jeu.getConstTerrain().getDimX();
	dimy = jeu.getConstTerrain().getDimY();
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;

  // Creation de la fenetre
  window = SDL_CreateWindow("Jeu1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx=25*TAILLE_SPRITE, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
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
  im_background.loadFromFile("data/background.png",renderer);
  im_runright.loadFromFile("data/RunRight.png",renderer);
  im_runleft.loadFromFile("data/RunLeft.png",renderer);
  im_idleright.loadFromFile("data/IdleRight.png",renderer);
  im_idleleft.loadFromFile("data/IdleLeft.png",renderer);
  im_fallleft.loadFromFile("data/FallLeft.png",renderer);
  im_fallright.loadFromFile("data/FallRight.png",renderer);
  im_jumpleft.loadFromFile("data/JumpLeft.png",renderer);
  im_jumpright.loadFromFile("data/JumpRight.png",renderer);
  im_turnleft.loadFromFile("data/TurnLeft.png",renderer);
  im_turnright.loadFromFile("data/TurnRight.png",renderer);
}

sdlJeu::~sdlJeu () {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdlJeu::sdlAff(){
  //int dimx, dimy;
  //dimx = jeu.getConstTerrain().getDimX();
  //dimy = jeu.getConstTerrain().getDimY();
  SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
  SDL_RenderClear(renderer);

  drawTerrain();
  drawPersonnage();


}

void sdlJeu::sdlBoucle(){
  bool quit = false;
  SDL_Event events;
  bool sauter = false;
  jeu.getTerrain().setVersion(1);

  while(!quit){

    while(SDL_PollEvent(&events)){
      if(events.type == SDL_QUIT){
        quit = true;
      }else if(events.type == SDL_KEYDOWN){

      }
    }

    if(sauter){
      jeu.actionClavier(122);
      if(jeu.getStatus() == 0) sauter = false;
    }else{
      jeu.actionsAutomatiques();
    }

    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if(currentKeyStates[SDL_SCANCODE_LEFT] && currentKeyStates[SDL_SCANCODE_UP]){
      sauter = true;
      jeu.actionClavier(113);
    }else if(currentKeyStates[SDL_SCANCODE_RIGHT] && currentKeyStates[SDL_SCANCODE_UP]){
      sauter = true;
      jeu.actionClavier(100);
    }else if(currentKeyStates[SDL_SCANCODE_LEFT]){
      jeu.actionClavier(113);
    }else if(currentKeyStates[SDL_SCANCODE_RIGHT]){
      jeu.actionClavier(100);
    }else if(currentKeyStates[SDL_SCANCODE_DOWN]){
      jeu.actionClavier(115);
    }else if(currentKeyStates[SDL_SCANCODE_UP]){
      sauter = true;
    }
    sdlAff();
    SDL_Delay(3);
    SDL_RenderPresent(renderer);
  }
}

void sdlJeu::drawTerrain(){
  int dx = camera.decalageX(jeu.getConstPersonnage(), jeu.getConstTerrain());
  int x,y;
	const Terrain& ter = jeu.getConstTerrain();
  //renderer background
  im_background.draw(renderer,0,0,25*TAILLE_SPRITE,20*TAILLE_SPRITE);
  // Afficher les sprites des murs et des pastilles
for (x=0;x<ter.getDimX();++x){
  for (y=0;y<ter.getDimY();++y){
      if (ter.getXY(x,y)=='#'){
        im_mur.draw(renderer,x*TAILLE_SPRITE-dx,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }else if(ter.getXY(x,y) == 'T'){
        im_ter.draw(renderer,x*TAILLE_SPRITE-dx,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }else if(ter.getXY(x,y) == 'G'){
        im_grass.draw(renderer,x*TAILLE_SPRITE-dx,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }else if(ter.getXY(x,y) == '['){
        im_grass_gauche.draw(renderer,x*TAILLE_SPRITE-dx,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }else if(ter.getXY(x,y) == ']'){
        im_grass_droite.draw(renderer,x*TAILLE_SPRITE-dx,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }else if(ter.getXY(x,y) == '('){
        im_mur_bas_gauche.draw(renderer,x*TAILLE_SPRITE-dx,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }else if(ter.getXY(x,y) == ')'){
        im_mur_bas_droite.draw(renderer,x*TAILLE_SPRITE-dx,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }else if(ter.getXY(x,y) == '_'){
        im_mur_bas.draw(renderer,x*TAILLE_SPRITE-dx,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
      }
  }
}

}

void sdlJeu::drawPersonnage(){
  int dx = camera.decalageX(jeu.getConstPersonnage(), jeu.getConstTerrain());
  const Personnage& perso = jeu.getConstPersonnage();

    int status = jeu.getStatus();
    int sens = jeu.getSens();
    int status_o = jeu.getStatusO();
    int sens_o = jeu.getSensO();
    //cout << "sens_o: " << sens_o << " sens: " << sens << endl;
    //status idle left and right
    if(status == 0 && sens == 0 && status_o == 0 && sens_o == 0){
      im_idleleft.draw_animation(2, renderer,(i/FPS)%2,perso.getX()+3-dx,perso.getY(),30,36);
      //Comme il n'y a que n images et que nous voulons ralentir l'animation,
      // nous passons à l'image suivante toutes les n images.(n == nombre image pour l'animation)
    }
    else if(status == 0 && sens == 1 && status_o == 0 && sens_o == 1){
      im_idleright.draw_animation(2, renderer,(i/FPS)%2,perso.getX()+3-dx,perso.getY(),30,36);
    }

    //status run left and right
    else if((status_o == 0 && status == 2) || (status == 2 && status_o == 2)){
      im_runright.draw_animation(10, renderer,(i/FPS)%10,perso.getX()-1-dx,perso.getY()-3,38,42);
    }
    else if((status_o == 0 && status == 1) || (status == 1 && status_o == 1)){
      im_runleft.draw_animation(10, renderer,(i/ FPS) % 10,perso.getX()-1-dx,perso.getY()-3,38,42);
    }
    //fall
    else if((status_o == 3 && status == 1 && sens == 0) || (status == 3 && sens == 0)){
      im_fallleft.draw_animation(4, renderer,(i/FPS)%4,perso.getX()+2-dx,perso.getY()-12,32,60);
    }else if((status_o == 3 && status == 2 && sens == 1) || (status == 3 && sens == 1)){
      im_fallright.draw_animation(4, renderer,(i/FPS)%4,perso.getX()+2-dx,perso.getY()-12,32,60);
    }
    //jump
    else if((status_o == 4 && status == 1 && sens == 0) || (status == 4 && sens == 0) ){
      im_jumpleft.draw_animation(4, renderer,(i/FPS)%4,perso.getX()+5-dx,perso.getY()-7,26,50);
    }else if((status_o == 4 && status == 2 && sens == 1) || (status == 4 && sens == 1)){
      im_jumpright.draw_animation(4, renderer,(i/FPS)%4,perso.getX()+5-dx,perso.getY()-7,26,50);
    }
    //status turn left and turn right
    else if(sens_o == 0 && sens == 1){
      cout << "yes" << endl;
      im_turnright.draw_animation(10, renderer,(i/FPS)%10,perso.getX()+1-dx,perso.getY(),34,36);
    }else if(sens_o == 1 && sens == 0){
      im_turnleft.draw_animation(10, renderer,(i/FPS)%10,perso.getX()+1-dx,perso.getY(),34,36);
    }
    else if(sens == 0){
      im_idleleft.draw_animation(2, renderer,(i/FPS)%2,perso.getX()+3-dx,perso.getY(),30,36);
    }else if(sens == 1){
      im_idleright.draw_animation(2, renderer,(i/FPS)%2,perso.getX()+3-dx,perso.getY(),30,36);
    }
    i++;
}
