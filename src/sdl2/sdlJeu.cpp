#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>

#include <iostream>
using namespace std;

sdlJeu::sdlJeu() : jeu()
{
  int n;
  cout << "quel niveau jouer ? " << endl;
  cin >> n;
  jeu.getTerrain().setChoixniv(n);
  jeu.getTerrain().setVersion(1);

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
    SDL_Quit();
    exit(1);
  }
  int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
  if (!(IMG_Init(imgFlags) & imgFlags))
  {
    cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
    SDL_Quit();
    exit(1);
  }

  // if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0)
  {
    cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
    cout << "No sound !!!" << endl;
    // SDL_Quit();exit(1);
    withSound = false;
    withmusique = false;
  }
  else
  {
    withSound = true;
    withmusique = true;
  }

  int dimx, dimy;
  dimx = jeu.getConstTerrain().getDimX();
  dimy = jeu.getConstTerrain().getDimY();
  dimx = dimx * TAILLE_SPRITE;
  dimy = dimy * TAILLE_SPRITE;

  // Creation de la fenetre
  window = SDL_CreateWindow("Jeu1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx = 25 * TAILLE_SPRITE, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  if (window == NULL)
  {
    cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
    SDL_Quit();
    exit(1);
  }

  // Attribution d'un icon à la fenetre
  im_icon = IMG_Load("data/icon-jeu.png");
  SDL_SetWindowIcon(window, im_icon);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

 
  im_mortperso.loadFromFile("data/deathscene.png", renderer);
  im_mur.loadFromFile("data/#.png", renderer);
  im_ter.loadFromFile("data/G.png", renderer);
  im_grass.loadFromFile("data/G.png", renderer);
  im_grass_gauche.loadFromFile("data/[.png", renderer);
  im_grass_droite.loadFromFile("data/].png", renderer);
  im_mur_bas.loadFromFile("data/_.png", renderer);
  im_mur_bas_gauche.loadFromFile("data/(.png", renderer);
  im_mur_bas_droite.loadFromFile("data/).png", renderer);
  //im_background.loadFromFile("data/background.png", renderer);
  im_ciel.loadFromFile("data/background1.png", renderer);
  im_runright.loadFromFile("data/RunRight.png", renderer);
  im_runleft.loadFromFile("data/RunLeft.png", renderer);
  im_idleright.loadFromFile("data/IdleRight.png", renderer);
  im_idleleft.loadFromFile("data/IdleLeft.png", renderer);
  im_fallleft.loadFromFile("data/FallLeft.png", renderer);
  im_fallright.loadFromFile("data/FallRight.png", renderer);
  im_jumpleft.loadFromFile("data/JumpLeft.png", renderer);
  im_jumpright.loadFromFile("data/JumpRight.png", renderer);
  im_turnleft.loadFromFile("data/TurnLeft.png", renderer);
  im_turnright.loadFromFile("data/TurnRight.png", renderer);
  im_vie.loadFromFile("data/vie2.png", renderer);
  im_money.loadFromFile("data/Money.png", renderer);
  im_item.loadFromFile("data/epee.png", renderer);
  im_armor.loadFromFile("data/armor.png", renderer);
  im_portal.loadFromFile("data/Portal.png", renderer);
  im_skeletonWalkRight.loadFromFile("data/SkeletonWalkRight.png", renderer);
  im_skeletonWalkLeft.loadFromFile("data/SkeletonWalkLeft.png", renderer);
  im_attack1right.loadFromFile("data/Attack1Right.png", renderer);
  im_attack1left.loadFromFile("data/Attack1Left.png", renderer);
  im_arbressapins.loadFromFile("data/Y.png", renderer);
  im_burnedground.loadFromFile("data/B.png", renderer);
  im_burnedground2.loadFromFile("data/L.png", renderer);
  im_piques.loadFromFile("data/^.png", renderer);
  im_lave.loadFromFile("data/=.png", renderer);
  im_fond.loadFromFile("data/0.png", renderer);
  im_ciel2.loadFromFile("data/background2.png", renderer);
   // im_heart.loadFromFile("data/coeur.png", renderer);
  //im_ciel3.loadFromFile("data/background3.jpg", renderer);


  // SONS et MUSIQUE
    if (withSound)
    {
        soundpiece = Mix_LoadWAV("data/piece2.wav");
        if (soundpiece == nullptr)
            soundpiece = Mix_LoadWAV("../data/piece2.wav");
        if (soundpiece == nullptr) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl;
                SDL_Quit();
                exit(1);
        }

        soundvie = Mix_LoadWAV("data/vie.wav");
        if (soundvie == nullptr)
            soundvie = Mix_LoadWAV("../data/vie.wav");
        if (soundvie == nullptr) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl;
                SDL_Quit();
                exit(1);
        }

        soundarmure = Mix_LoadWAV("data/armure.wav");
        if (soundarmure == nullptr)
            soundarmure = Mix_LoadWAV("../data/armure.wav");
        if (soundarmure == nullptr) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl;
                SDL_Quit();
                exit(1);
        }

        soundarme = Mix_LoadWAV("data/arme.wav");
        if (soundarme == nullptr)
            soundarme = Mix_LoadWAV("../data/arme.wav");
        if (soundarme == nullptr) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl;
                SDL_Quit();
                exit(1);
        }

        soundattack = Mix_LoadWAV("data/attack.wav");
        if (soundattack == nullptr)
            soundattack = Mix_LoadWAV("../data/attack.wav");
        if (soundattack == nullptr) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl;
                SDL_Quit();
                exit(1);
        }

        finniveau = Mix_LoadWAV("data/finniveau.wav");
        if (finniveau == nullptr)
            finniveau = Mix_LoadWAV("../data/finniveau.wav");
        if (finniveau == nullptr) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl;
                SDL_Quit();
                exit(1);
        }
    }

  if (withmusique && jeu.getConstTerrain().getChoixniv()==1)
  {
    musique = Mix_LoadMUS("data/zicmu.mp3");
    Mix_PlayMusic(musique, -1);
    if (musique == nullptr)
    {
      musique = Mix_LoadMUS("../data/zicmu.mp3");
      Mix_PlayMusic(musique, -1);
    }
    if (musique == nullptr)
    {
      cout << "Failed to load zicmu.mp3! SDL_mixer Error: " << Mix_GetError() << endl;
      SDL_Quit();
      exit(1);
    }
  }
if (withmusique && jeu.getConstTerrain().getChoixniv()==2){
  musique2 = Mix_LoadMUS("data/zicmu2.mp3");
    Mix_PlayMusic(musique2, -1);
    if (musique2 == nullptr)
    {
      musique2 = Mix_LoadMUS("../data/zicmu2.mp3");
      Mix_PlayMusic(musique2, -1);
    }
    if (musique2 == nullptr)
    {
      cout << "Failed to load zicmu2.mp3! SDL_mixer Error: " << Mix_GetError() << endl;
      SDL_Quit();
      exit(1);
    }


}
  



}

sdlJeu::~sdlJeu()
{
  if (withSound)
    Mix_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void sdlJeu::sdlAff()
{
  // int dimx, dimy;
  // dimx = jeu.getConstTerrain().getDimX();
  // dimy = jeu.getConstTerrain().getDimY();
  SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
  SDL_RenderClear(renderer);
  drawTerrain();
  drawPersonnage();
  drawMonstre();
}

SDL_Event sdlJeu::getEvent() const { return event; }

void sdlJeu::sdlBoucle()
{


  const Terrain & ter = jeu.getConstTerrain();

  for(int y = 0; y < jeu.getTerrain().getDimY(); y++){
    cout << y;
    for(int x = 0; x < jeu.getTerrain().getDimX(); x++){

      cout << ter.getXY(x , y);
    }
    cout << endl;
  }

  //ter.getXY(11, 5);
  bool quit = false;
  SDL_Event events = getEvent();
  bool sauter = false;


  while (!quit && !jeu.getFdj())
  {
    while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
                bool mangepiece = false;
				switch (events.key.keysym.sym) {
				case SDLK_UP:
				//	mangepiece = jeu.actionClavier();    // car Y inverse
					break;
				case SDLK_DOWN:
				//	mangepiece = jeu.actionClavier();     // car Y inverse
					break;
				case SDLK_LEFT:
				//	mangepiece = jeu.actionClavier();
					break;
				case SDLK_RIGHT:
				//	mangepiece = jeu.actionClavier();
					break;
        case SDLK_v:
          Mix_PlayChannel(-1,soundattack,0);
          break;
        case SDLK_m:
          if (Mix_PausedMusic() == 1) // Si la musique est en pause
          {
            Mix_ResumeMusic(); // Reprendre la musique
          }
          else
          {
            Mix_PauseMusic(); // Mettre en pause la musique
          }
          break;
          case SDLK_ESCAPE:
          Mix_FreeMusic(musique);
          Mix_FreeMusic(musique2);
          Mix_CloseAudio();
          quit = true;
          break;
                case SDL_SCANCODE_ESCAPE:
                case SDL_SCANCODE_Q:
                    quit = true;
                    break;
				default: break;
				}
				if (withSound){
          Mix_PlayChannel(-1,soundpiece,0);
        }

			}
		}

    if (sauter && jeupause == false)
    {
      jeu.actionClavier(122);
      if (jeu.getStatus() == 0)
        sauter = false;
    }
    else if (jeupause == false)
    {
      jeu.actionsAutomatiques();
    }

    const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_LEFT] && currentKeyStates[SDL_SCANCODE_UP])
    {
      sauter = true;
      jeu.actionClavier(113);
    }
    else if (currentKeyStates[SDL_SCANCODE_RIGHT] && currentKeyStates[SDL_SCANCODE_UP])
    {
      sauter = true;
      jeu.actionClavier(100);
    }
    else if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
      jeu.actionClavier(113);
    }
    else if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
      jeu.actionClavier(100);
    }
    else if (currentKeyStates[SDL_SCANCODE_DOWN])
    {
      jeu.actionClavier(115);
    }
    else if (currentKeyStates[SDL_SCANCODE_UP])
    {
      sauter = true;
    }
    else if (currentKeyStates[SDL_SCANCODE_V])
    {
      jeu.actionClavier(118);
    }
    sdlAff();
    SDL_Delay(3);
    SDL_RenderPresent(renderer);
  }
}

void sdlJeu::drawTerrain()
{
  int dx = camera.decalageX(jeu.getConstPersonnage(), jeu.getConstTerrain());
  int x, y;
  const Terrain &ter = jeu.getConstTerrain();
  // renderer background
  //  im_background.draw(renderer,0,0,25*TAILLE_SPRITE,20*TAILLE_SPRITE);
  // renderer background
 if(ter.getChoixniv()==1)im_ciel.draw(renderer, 0, 0, 28 * TAILLE_SPRITE, 19 * TAILLE_SPRITE);
 if(ter.getChoixniv()==2)im_ciel2.draw(renderer, 0, 0, 28 * TAILLE_SPRITE, 19 * TAILLE_SPRITE);
// if(ter.getChoixniv()==3)im_ciel3.draw(renderer, 0, 0, 28 * TAILLE_SPRITE, 19 * TAILLE_SPRITE);
  // Afficher les sprites des murs et des pastilles
  for (y = 0; y < ter.getDimY(); y++)
  {
    for (x = 0; x < ter.getDimX(); x++)
    {
      //cout << ter.getXY(x, y);
      if (ter.getXY(x, y) == 'Y')
      {
        im_arbressapins.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE-300, 5*TAILLE_SPRITE, 10*TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == '=')
      {
        im_lave.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == 'B')
      {
        im_burnedground.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == '0')
      {
        im_fond.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == '^')
      {
        im_piques.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE-15, TAILLE_SPRITE, 3*TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == 'L')
      {
        im_burnedground2.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == '#')
      {
        im_mur.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == 'T')
      {
        im_ter.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == 'G')
      {
        im_grass.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == '[')
      {
        im_grass_gauche.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == ']')
      {
        im_grass_droite.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == '(')
      {
        im_mur_bas_gauche.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == ')')
      {
        im_mur_bas_droite.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == '_')
      {
        im_mur_bas.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == '+')
      {
        im_vie.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x,y)=='O')
      {
        im_armor.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == '$')
      {
        im_money.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == '!')
      {
        im_item.draw(renderer, x * TAILLE_SPRITE - dx, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
      }
      else if (ter.getXY(x, y) == 'F')
      {
        im_portal.draw_animation(10, renderer, (i / FPS) % 10, x * TAILLE_SPRITE - dx - 28, y * TAILLE_SPRITE - 38, 93, 94);
      }
    }
    //cout << endl;
  }
}

void sdlJeu::drawPersonnage()
{
  int dx = camera.decalageX(jeu.getConstPersonnage(), jeu.getConstTerrain());
  const Personnage &perso = jeu.getConstPersonnage();
  int status = jeu.getStatus();
  int sens = jeu.getSens();
  int status_o = jeu.getStatusO();
  int sens_o = jeu.getSensO();
  // cout << "sens_o: " << sens_o << " sens: " << sens << endl;
  // status idle left and right
  if (status == -1 && sens == -1 && status_o == 0 && sens_o == -1)
  {
    im_idleleft.draw_animation(2, renderer, (i / FPS) % 2, perso.getX() + 3 - dx, perso.getY(), 30, 36);
    // Comme il n'y a que n images et que nous voulons ralentir l'animation,
    //  nous passons à l'image suivante toutes les n images.(n == nombre image pour l'animation)
  }
  else if (status == 0 && sens == 1 && status_o == 0 && sens_o == 1)
  {
    im_idleright.draw_animation(2, renderer, (i / FPS) % 2, perso.getX() + 3 - dx, perso.getY(), 30, 36);
  }

  // status run left and right
  else if ((status_o == 0 && status == 2) || (status == 2 && status_o == 2))
  {
    im_runright.draw_animation(10, renderer, (i / FPS) % 10, perso.getX() - 1 - dx, perso.getY() - 3, 38, 42);
  }
  else if ((status_o == 0 && status == 1) || (status == 1 && status_o == 1))
  {
    im_runleft.draw_animation(10, renderer, (i / FPS) % 10, perso.getX() - 1 - dx, perso.getY() - 3, 38, 42);
  }
  // fall
  else if ((status_o == 3 && status == 1 && sens == -1) || (status == 3 && sens == -1))
  {
    im_fallleft.draw_animation(4, renderer, (i / FPS) % 4, perso.getX() + 2 - dx, perso.getY() - 12, 32, 60);
  }
  else if ((status_o == 3 && status == 2 && sens == 1) || (status == 3 && sens == 1))
  {
    im_fallright.draw_animation(4, renderer, (i / FPS) % 4, perso.getX() + 2 - dx, perso.getY() - 12, 32, 60);
  }
  // jump
  else if ((status_o == 4 && status == 1 && sens == -1) || (status == 4 && sens == -1))
  {
    im_jumpleft.draw_animation(4, renderer, (i / FPS) % 4, perso.getX() + 5 - dx, perso.getY() - 7, 26, 50);
  }
  else if ((status_o == 4 && status == 2 && sens == 1) || (status == 4 && sens == 1))
  {
    im_jumpright.draw_animation(4, renderer, (i / FPS) % 4, perso.getX() + 5 - dx, perso.getY() - 7, 26, 50);
  }
  else if(status == 5 && sens == 1){
    im_attack1right.draw_animation(10, renderer, (i / FPS) % 10, perso.getX() - 34 - dx, perso.getY() - 18, 104, 54);
  }
  else if(status == 5 && sens == -1){
    im_attack1left.draw_animation(10, renderer, (i / FPS) % 10, perso.getX() - 34 - dx, perso.getY() - 18, 104, 54);
  }
  // status turn left and turn right
  else if (sens_o == 0 && sens == 1)
  {
    cout << "yes" << endl;
    im_turnright.draw_animation(10, renderer, (i / FPS) % 10, perso.getX() + 1 - dx, perso.getY(), 34, 36);
  }
  else if (sens_o == 1 && sens == -1)
  {
    im_turnleft.draw_animation(10, renderer, (i / FPS) % 10, perso.getX() + 1 - dx, perso.getY(), 34, 36);
  }
  else if (sens == -1)
  {
    im_idleleft.draw_animation(2, renderer, (i / FPS) % 2, perso.getX() + 3 - dx, perso.getY(), 30, 36);
  }
  else if (sens == 1)
  {
    im_idleright.draw_animation(2, renderer, (i / FPS) % 2, perso.getX() + 3 - dx, perso.getY(), 30, 36);
  }
  i++;
}

void sdlJeu::drawMonstre()
{
  /*
  int dx = camera.decalageX(jeu.getConstPersonnage(), jeu.getConstTerrain());
   Personnage& monst = jeu.getMonstre();
  int sens = monst.getSens();
  if(sens == 1){
    im_skeletonWalkRight.draw_animation(13, renderer, (i/FPS)%13,monst.getX()-4-dx,monst.getY()-30,44,66);
  }else{
    im_skeletonWalkLeft.draw_animation(13, renderer, (i/FPS)%13,monst.getX()-4-dx,monst.getY()-30,44,66);
  }*/

  int dx = camera.decalageX(jeu.getConstPersonnage(), jeu.getConstTerrain());
  int Tsens[10];
  Personnage Tmonst[10];
  for (int i = 0; i < 10; i++)
  {
    Tmonst[i] = jeu.getMonstre(i);
    Tsens[i] = Tmonst[i].getSens();

  if(!Tmonst[i].getMort())
  {

    if (Tsens[i] == 1)
    {
      im_skeletonWalkRight.draw_animation(13, renderer, (i / FPS) % 13, Tmonst[i].getX() - dx -4, Tmonst[i].getY() - 30, 44, 66);
    }
    else
    {
      im_skeletonWalkLeft.draw_animation(13, renderer, (i / FPS) % 13, Tmonst[i].getX() - dx - 4, Tmonst[i].getY() - 30, 44, 66);
    }
  }
  }
}

/*
void sdlJeu::drawPV()
{
  int dx = camera.decalageX(jeu.getConstPersonnage(), jeu.getConstTerrain());
  Personnage &perso = jeu.getPerso();

  for(int i; i<perso.getVie(); i++)
  {
    im_heart.draw(renderer, 5+(i*10),5+(i*10),TAILLE_SPRITE, TAILLE_SPRITE);
  }
}
*/
