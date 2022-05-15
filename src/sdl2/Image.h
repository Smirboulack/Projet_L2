#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Image
{

private:
    SDL_Surface *surface; //!< \brief objet de type SDL_Surface
    SDL_Texture *texture; //!< \brief objet de type SDL_texture
    bool has_changed;     //!< \brief booleen

public:
    /**
     * @brief Constructeur par défaut de la classe sdlJeu
     *
     */
    Image();
    /**
     * @brief Procédure qui permet de charger une iamge depuis le chemin specifié
     * @param filename chaîne de caractères qui permet de spécifier le chemin vers le fichier image
     * @param renderer pointeur sur SDL_renderer
     *
     */
    void loadFromFile(const char *filename, SDL_Renderer *renderer);
    /**
     * @brief Procédure qui permet de créer une texture à partir du renderer
     * @param renderer pointeur sur SDL_renderer
     *
     */
    void loadFromCurrentSurface(SDL_Renderer *renderer);
    /**
     * @brief Procédure qui dessine l'image avec les paramètres spécifiés
     * @param renderer
     * @param x position X de l'image
     * @param y position Y de l'image
     * @param w largeur de l'image
     * @param h hauteur de l'image
     *
     */
    void draw(SDL_Renderer *renderer, int x, int y, int w = -1, int h = -1);
    /**
     * @brief Procédure pour dessiner une animation avec les paramètres spécifiés
     * @param n animation à n image
     * @param renderer pointeur sur SDL_renderder
     * @param i image actuel
     * @param x position X de l'image
     * @param y position Y de l'image
     * @param w largeur de l'image
     * @param h hauteur de l'image
     *
     */
    void draw_animation(int n, SDL_Renderer *renderer, int i, int x, int y, int w, int h);
    /**
     * @brief Fonction qui renvoie la donnée membre texture
     *
     */
    SDL_Texture *getTexture() const;
    /**
     * @brief Procédure qui permet de spécifier la donnée membre surface
     *
     */
    void setSurface(SDL_Surface *surf);
    /**
     * @brief Procédure testRegression de la classe Image
     *
     */

    void testRegression();
};
#endif
