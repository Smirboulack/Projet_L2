#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


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
#endif
