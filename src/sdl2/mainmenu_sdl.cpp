#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cassert>
#include "Image.h"

using namespace std;

int main(int argc, char *argv[])
{
	Image im_menu;
	
	//SDL_Surface *window = NULL;
	SDL_Surface * im_icon = NULL;
	SDL_Window *screen = NULL;
	//SDL_Surface *menu = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Event event;
	//SDL_Rect positionMenu;

	bool continuer=true;

	SDL_Init(SDL_INIT_EVERYTHING);
	screen = SDL_CreateWindow("Mon premier Menu en SDL2",
							  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							  1080, 880,
							  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	if (screen == NULL) {
      cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
      SDL_Quit();
      exit(1);
  }

	
	im_icon = IMG_Load("data/icon-jeu.png");
	//menu=IMG_Load("data/Main_Menu.png");
	SDL_SetWindowIcon(screen, im_icon);

	renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
	im_menu.loadFromFile("data/Main_Menu.png",renderer);
	im_menu.draw(renderer,0,0,1080,880);
	SDL_RenderPresent(renderer);
	while (continuer)
	{
		
		SDL_WaitEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			continuer=false;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{

			case SDLK_ESCAPE:
				continuer=false;
				break;
			case SDLK_SPACE:
				SDL_DestroyRenderer(renderer);
				break;
			}
			break;
		}
	//	SDL_Delay(3);
    //	
		
	}
	
	//SDL_FreeSurface(menu);
	SDL_DestroyWindow(screen);
	SDL_Quit();

	return 0;
}