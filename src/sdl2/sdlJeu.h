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

class sdlJeu
{
private:
  Jeu jeu;

  SDL_Window *window;     //!< \brief objet de type SDL_window pour dessiner une fenêtre SDL
  SDL_Renderer *renderer; //!< \brief objet de type de SDL_renderer
  SDL_Surface *im_icon;   //!< \brief objet de type de type SDL_surface qui servira à afficher l'icône de la fenêtre SDL
  SDL_Event event;        //!< \brief objet de type SDL_Event

  /*
//! \brief Les objets de type Image suivantes serviront à charger des images depuis le repertoire 'data'.
*/
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
  Image im_armor;
  Image im_money;
  Image im_portal;
  Image im_skeletonWalkRight;
  Image im_skeletonWalkLeft;
  Image im_attack1right;
  Image im_attack1left;
  Image im_lave;
  Image im_piques;
  Image im_fond;
  Image im_burnedground;
  Image im_burnedground2;
  Image im_arbressapins;
  Image im_ciel2;
  Image im_ciel3;
  Image im_heart;
  Image im_shield;
  Image im_arbremort;

  Mix_Chunk *soundpiece;  //!< \brief objet de type Mix_Chunk pour générer le son d'une piece
  Mix_Chunk *soundvie;    //!< \brief objet de type Mix_Chunk pour générer le son d'une vie
  Mix_Chunk *soundarmure; //!< \brief objet de type Mix_Chunk pour générer le son d'une armure
  Mix_Chunk *soundarme;   //!< \brief objet de type Mix_Chunk pour générer le son d'une arme
  Mix_Chunk *soundattack; //!< \brief objet de type Mix_Chunk pour générer le son d'une attaque
  Mix_Chunk *finniveau;   //!< \brief objet de type Mix_Chunk pour générer le son d'un fin de niveau
  Mix_Chunk *sonpas1;     //!< \brief objet de type Mix_Chunk pour générer le son de pas
  Mix_Chunk *sonpas2;     //!< \brief objet de type Mix_Chunk pour générer le son de pas

  Mix_Music *musique;  //!< \brief objet de type Mix_Music pour la jouer musique de niveau 1
  Mix_Music *musique2; //!< \brief objet de type Mix_Music pour la jouer musique de niveau 2
  Mix_Music *musique3; //!< \brief objet de type Mix_Music pour la jouer musique de niveau 3
  bool withSound;      //!< \brief booleen pour activer/désactiver les sons
  bool withmusique;    //!< \brief booleen pour activer/désactiver la musique

  Camera camera; //!< \brief objet de type Camera pour faire défiler la camera de jeu.

  int i = 0;

public:
  const int TAILLE_SPRITE = 36; //!< \brief taille de chaque case par pixels

  const int FPS = 20;    //!< \brief FPS pour animation après FPS meme images on change à l'images suivante
  bool jeupause = false; //!< \brief booléen pour mettre le jeu en pause

  /**
   * @brief Constructeur par défaut de la classe sdlJeu
   */
  sdlJeu();
  /**
   * @brief Déstucteur par défaut de la classe sdlJeu
   *
   */
  ~sdlJeu();
  /**
   * @brief Procédure qui permet de faire appels aux fonctions membres en boucle
   *
   */
  void sdlBoucle();
  /**
   * @brief Procédure qui permet de faire l'affichage des objets du jeu et les animations
   *
   */
  void sdlAff();
  /**
   * @brief Procédure qui permet de dessiner le terrain de jeu
   *
   */
  void drawTerrain();
  /**
   * @brief Procédure qui permet de dessiner le personnage joueur
   *
   */
  void drawPersonnage();
  /**
   * @brief Procédure qui permet de dessiner le personnage monstre
   *
   */
  void drawMonstre();
  /**
   * @brief Fonction qui permet de renvoyer l'objet event de type SDL_Event
   *
   */
  SDL_Event getEvent() const;
  /**
   * @brief Procédure qui permet de dessiner les informations sur le personnage
   *
   */
  void drawInfoPerso();
  /**
   * @brief Procédure testRegression de la classe sdlJeu
   *
   */
  void testRegression();
};

#endif
