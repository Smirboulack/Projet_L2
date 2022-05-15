/** \mainpage Jeu-Vidéo ULTIMATE-LIFKAS

\section intro Introduction

# PROJET ULTIMATE-LIFKAS pour l'UE LIFAP4
TEMIRBOULATOV KOUREICH p1707160 ; BENZIANE ABDELDJALLIL p1919796 ; MA SHENGQI p2108131


Ultimate-LIFKAS est un jeu-vidéo developpé en c++ en utilisant la SDL/SDL2. Ce projet de developpement à été réalisé dans le cadre de l'UE LIFAP4 <br>
Voir la page du cours : http://licence-info.univ-lyon1.fr/LIFAP4


Ce dossier contient un makefile permettant d'executer le code du jeu-vidéo.<br> 
le Dossier src contient les sous-dossiers /core /sdl2 et /txt qui contiennent les modules spécifiques du jeu. (fichiers .h et .cpp) <br> 

Le jeu-vidéo est jouable en version console(version texte) sans interface graphique et en version graphique avec la SDL.

Il peut se compiler sous Linux et Windows (avec WSL notamment) , avec la commande make depuis le dossier source.

## Code et l'organisation des fichiers

Le code est divisé en plusieurs modules répartis entre le coeur (fichiers dans le dossiers /src/core) qui constitue le noyau du programme et entre les modes d'interfaces (fichiers dans le sous-dossier /src/txt) pour la version console(texte) <br>
et l'interface graphique (fichiers dans le sous-dossier src/sdl2) pour la version en SDL. 

\section compil Compilation

L'organistion des fichiers est la suivante.

- **bin**   : 		Contient les fichiers executable créees avec la commande make depuis le dossier racine , pour éxecuter un fichier il faut executer la commande ./nom_executable , exemple : ./main_sdl 
- **data**   : 		Contient les fichiers images,audio et .txt du jeu 
- **doc**   : 		Contient le fichier .doxy permettant d'éditer et générer la documentation doxygen. 
- **doc/html/index.html** : La page internet de la documentation généré par doxygen.
- **obj**   : 		répertoire comportant les fichiers objets créés lors de la compilation.
- **src**   : 		Contient les sous-dossiers /core /sdl2 et /txt
- **src/core**   : 		Contient les fichiers source .cpp et .h qui constitue les modules principaux du jeu , les modules noyau.
- **src/sdl2**   : 		Contient les fichiers source .cpp et .h qui constitue de les modules principaux pour la version graphique SDL du jeu.
- **src/txt**   : 		Contient les fichiers source .cpp et .h qui constitue les modules principaux pour la version txt du jeu.


Pour la documentation du code, voir la rubrique "documentation du code" plus bas.

## Pour compiler

Si vous êtes sous linux , assurez-vous d'avoir SDL/SDL2 installer sur votre machine.
-Ouvrez un terminal et éxecuter simplement la commande : sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev imagemagick
-Puis depuis le dossier racine du jeu , executez , depuis votre terminal, la commande : make
-Une fois la compilation terminée , executez la commande ./bin/main_txt pour lancer la version txt du jeu ou ./bin/main_sdl pour lancer la version graphique

Si la commande d'installation de la SDL/SDL2 ne fonctionne pas , reférez-vous à la commande spécifique pour installer SDL/SDL2 selon votre distribution linux.

### Préambule : si vous voulez un Linux sous Windows, vous pouvez installer WSL ! 

Voir la page de l'UE : https://perso.liris.cnrs.fr/alexandre.meyer/public_html/www/doku.php?id=lifap4#wsl_pour_faire_tourner_un_linux_ultra_leger_sous_windows

C'est léger, pratique, rapide et suffisant pour de nombreuses applications.
Windows/WSL est exactement comme une machine Linux avec des drivers minimalistes, 
donc la gestion de certains périphériques commes la carte son ou l'accélération 3D peut ne pas marcher mais pour ce cours ca peut être suffisant.
Il faut parcontre que vous ayez installé XMing pour pouvoir ouvrir des fenêtres comme expliqué sur la page du cours. 
Valgrind marche aussi !


### Pour installer SDL2
Pour installer SDL2 sous Linux ou avec WSL/Windows
``` sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev imagemagick ```


### Une fois SDL2 et WSL (le cas échéant) installés, la compilation s'effectue en ligne de commande:
Depuis le répertoire racine du module image, exécutez la commande make.
Si la compilation ne s'effectue pas, vérifiez que les chemins d'inclusion précisés dans le fichier Makefile en racine du projet correspondent à votre installation de SDL2 (par défaut /usr/include).


\section doc Documentation

Une documentation détaillée générée grâce à Doxygen est disponible dans le répertoire doc <br>



Le programme contient neuf classes et utilise plusieurs librairies .

Les classes sont Camera,Jeu,Terrain,Personnage,Menu,Image,sdlJeu,txtJeu et winTxt <br>


###class Camera
La class Camera permet de gérer le déplacement de la caméra dans la version graphique (SDL)  <br>

********Pour les fonctions membres : 

int decalageX(const Personnage &perso, const Terrain &ter) : La fonction qui calcule le décalage à appliquer pour le déplacement du terrain <br>

###class Jeu
La class Jeu constitue la class principale du Jeu , elle gère le personnage , les monstres , la gravité etc ... 

********Pour les fonctions membres : 
Terrain &getTerrain(); Accesseur du terrain qui renvoie la donnée membre ter <br>
Personnage &getPerso(); Accesseur de Personnage qui renvoie la donnée membre perso <br>
Personnage &getMonstre(); Accesseur de Personnage qui renvoie la donnée membre monstre <br>
Personnage &getMonstre(const int &i); Accesseur de Personnage qui renvoie le monstre d'indice i du tableau de monstre <br>
const Terrain &getConstTerrain() const; Accesseur du terrain qui renvoie la donnée membre ter <br>
const Personnage &getConstPersonnage() const; Accesseur de Personnage qui renvoie la donnée membre perso <br>
const Personnage &getConstMonstre() const; Accesseur de Personnage qui renvoie la donnée membre monstre <br>
int getStatus() const; Accesseur qui renvoie la donnée membre status <br>
int getStatusO() const;  Accesseur qui renvoie la donnée membre statusO <br>
int getSens() const; Accesseur qui renvoie la donnée membre Sens <br>
int getSensO() const; Accesseur qui renvoie la donnée membre SensO <br>
bool getFdj(); Accesseur qui renvoie la donnée membre fdj <br>
void setFdj(bool fdj);  mutateur qui modifie la donnée membre fdj <br>
void actionsAutomatiques(); Procédure qui sert à appeler les fonctions membres en boucle <br>
void initMonstre(); Procédure qui sert à initialiser les monstres <br>
bool actionClavier(const int touche); Fonction qui fait appel à la procédure correspondante à la touche pressée <br>
void gravite(); Fonction qui applique la gravité sur le terrain <br>
void graviteMonstre(); Fonction qui applique la gravité uniquement sur les monstres <br>
void ramasserItems(); Procédure qui permet au héros de ramasser les items <br>
void PersoSubirDegat(); Procédure qui permet de gérer la collision entre le héros et les monstres <br>
void FinDuJeu(); Procédure qui permet de vérifier si le jeu doit se terminer ou non <br>
void niveauSuivant(); Procédure qui permet le passage aux niveaux suivants <br>
void bougeAutoMonstre(Terrain &ter); Procédure qui permet de faire bouger les monstres automatiquement et de façon aléatoires <br>

###class Terrain
La class Terrain est la class qui gère la lecture et l'affichage du terrain de jeu.

********Pour les fonctions membres : 
bool loadMap(const std::string pathname);Procédure de chargement d'un niveau <br>
void afficherTerrain(); procédure qui permet l'affichage du terrain<br>
char getXY(const int x, const int y) const;  Renvoie le type d'objet se trouvant en (x,y)<br>
void setXY(const int x, const int y, const char &c);  Mutateur du terrain en coordonnée x et y<br>
void setDimx(const int Dimx); Mutateur de dimx <br>
void setVersion(const int &v); Mutateur de la version<br>
void setChoixniv(const int &n); Mutateur du choix du niveau<br>
int getDimX() const; Accesseur de dimx <br>
int getDimY() const; Accesseur de dimy <br>
int getChoixniv() const; Accesseur du Choix de niveau <br>
int getVersion() const; Accesseur dela version <br>
bool estPositionPersoValide(const int x, const int y) const; Fonction qui vérifie si la position du Personnage est valide <br>
bool estPositionMonstreValide(const int x, const int y) const; Fonction qui vérifie si la position du monstre est valide <br>
void ouvrir(std::string pathname); Procédure de lecture d'un terrain <br>

###class Personnage
La class Personnage permet d'initialiser un personnage joueur et des monstres

********Pour les fonctions membres : 
  bool deplacer(char direction, const Terrain &t); la fonction qui permet le déplacement du personnage<br>
  bool deplacerMonstre(char direction, const Terrain &t); la fonction qui permet le déplacement du monstre<br>
  bool deplacerVite(int n, char direction, const Terrain &t); la fonction qui permet le déplacement rapide du personnage<br>
  void subirDegat(int degat); La procédure qui fait subir les dégats et réduit les points de vie du personnage<br>
  void updateStatus(int s); la procédure de mise à jour du statut <br>
  void updateSens(int s); la procédure de mise à jour du sens<br>
  void sauter(const Terrain &ter); la procédure qui permet au héros de sauter<br>
  void gravite(const Terrain &ter); la procédure qui applique la gravité au Personnage<br>
  void attaquer(Personnage &perso); la procédure qui permet au héros d'attaquer<br>
  void setX(int x); Mutateur de x<br>
  void setY(int y); Mutateur de y<br>
  void setVie(int vie); Mutateur de vie<br>
  void setSexe(bool sexe); Mutateur du sexe<br>
  void setSens(int sens); Mutateur du sens<br>
  void setMort(bool mort); Mutateur de mort<br>
  void setNom(std::string nom); Mutateur du nom<br>
  void setDegat(int degat); Mutateur de degat<br>
  void setPortee(int portee); Mutateur de portée<br>
  void setPiece(int piece); Mutateur de piece<br>
  void setArmure(int armure); Mutateur de armure<br>
  void setArme(bool b); Mutateur de arme<br>
  void setSaute(bool saute); Procédure qui permet de modifier la valeur du booléen saut<br>
  int getX() const; Accesseur de x<br>
  int getY() const; Accesseur de y<br>
  int getXO() const; Accesseur de l'ancien x<br>
  int getYO() const; Accesseur de l'ancien y<br>
  int getVie(); Accesseur de vie<br>
  std::string getNom(); Accesseur de nom<br>
  bool getSexe(); Accesseur du sexe<br>
  int getSens() const; Accesseur de sens<br>
  int getSensO() const; Accesseur de l'ancien sens<br>
  bool getMort(); Accesseur de mort<br>
  int getDegat(); Accesseur de degat<br>
  int getPortee(); Accesseur de portée<br>
  int getStatus() const; Accesseur de statut<br>
  int getStatusO() const; Accesseur de l'ancien statut<br>
  int getPiece(); Accesseur de piece<br>
  int getArmure(); Accesseur de armure<br>
  bool getArme(); Accesseur de arme<br>
  bool getSaute(); Fonction accesseur qui renvoie le booléen saut<br>
  void versPerso(const Terrain &ter, const Personnage &p); La procédure qui permet au monstre de se diriger vers le héros<br>

###class Menu
La class Menu permet de faire l'affichage d'un menu en version txt

********Pour les fonctions membres : 
void menuAff(); Procédure qui permet d'afficher les choix du menu principal <br>
void menuoAff(); Procédure qui permet d'afficher les choix du sous-menu options <br>
ChoixMenu menuQuestion(); Procédure qui permet gérer le déplacement dans le menu principal <br>
ChoixMenuOptions menuoQuestion(); Procédure qui permet gérer le déplacement dans le sous-menu options <br>


###class Image
La classe permet de charger une image et de l'afficher

********Pour les fonctions membres : 
    void loadFromFile(const char *filename, SDL_Renderer *renderer); Procédure qui permet de charger une iamge depuis le chemin specifié<br>
	void loadFromCurrentSurface(SDL_Renderer *renderer); Procédure qui permet de créer une texture à partir du renderer<br>
	void draw(SDL_Renderer *renderer, int x, int y, int w = -1, int h = -1); Procédure qui dessine l'image avec les paramètres spécifiés<br>
	void draw_animation(int n, SDL_Renderer *renderer, int i, int x, int y, int w, int h); Procédure pour dessiner une animation avec les paramètres spécifiés<br>
	SDL_Texture *getTexture() const; Fonction qui renvoie la donnée membre texture<br>
	void setSurface(SDL_Surface *surf); Procédure qui permet de spécifier la donnée membre surface<br>

###class sdlJeu
La class sdlJeu gère la version graphique du jeu ainsi que l'audio

********Pour les fonctions membres : 
void sdlBoucle(); Procédure qui permet de faire appels aux fonctions membres en boucle<br>
void sdlAff(); Procédure qui permet de faire l'affichage des objets du jeu et les animations<br>
void drawTerrain(); Procédure qui permet de dessiner le terrain de jeu<br>
void drawPersonnage(); Procédure qui permet de dessiner le personnage joueur<br>
void drawMonstre(); Procédure qui permet de dessiner le personnage monstre<br>
SDL_Event getEvent() const; Fonction qui permet de renvoyer l'objet event de type SDL_Event<br>
void drawInfoPerso(); Procédure qui permet de dessiner les informations sur le personnage<br>


###class txtJeu
La class txtJeu gère la version console(texte) du jeu.

********Pour les fonctions membres : 
void txtBoucle(Jeu &j);Procédure qui permet de faire l'affichage de l'écran en boucle<br>

###class winTxt
La class winTxt gère l'affichage en version console(texte)

********Pour les fonctions membres : 
void clear(char c = ' ');Procédure qui nettoie l'écran en l'a remplissant avec le caractère ' ' <br>
void print(int x, int y, char c); Procédure qui affiche à l'écran le caractère c au paramètres spécifiés <br>
void print(int x, int y, char *c); Procédure qui affiche à l'écran le caractère c au paramètres spécifiés <br>
void draw(int x = 0, int y = 0); Procédure qui permet de dessiner dans l'écran <br>
void pause(); Procédure qui permet de mettre en pause l'écran en attente de l'entrée d'une touche <br>
char getCh(); Fonction qui retourne le caractère <br>

l'executable bin/test permet de faire un test de regression en faisant appel à la procédure de test de régression <br><br>
l'executable bin/main_sdl lance la version graphique du jeu <br><br>
l'executable bin/main_txt permet lance la version texte du jeu <br><br>

*/