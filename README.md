
# 🎮 Ultimate-LIFKAS

## 📑 Sommaire

-   [📌 Introduction](#-introduction)
    
-   [🛠 Organisation des fichiers](#-organisation-des-fichiers)
    
-   [⚙ Compilation](#-compilation)
    
    -   [📦 Installation des dépendances](#-installation-des-d%C3%A9pendances-linux--wsl)
        
    -   [▶ Compilation et exécution](#-compilation-et-ex%C3%A9cution)
        
-   [📚 Documentation](#-documentation)
    
    -   [🏗 Structure des classes](#-structure-des-classes)
        
        -   [Camera](#1-camera)
            
        -   [Jeu](#2-jeu)
            
        -   [Terrain](#3-terrain)
            
        -   [Personnage](#4-personnage)
            
        -   [Menu](#5-menu)
            
        -   [Image](#6-image)
            
        -   [sdlJeu](#7-sdljeu)
            
        -   [txtJeu](#8-txtjeu)
            
        -   [winTxt](#9-wintxt)
            
-   [🧪 Exécutables disponibles](#-ex%C3%A9cutables-disponibles)
----------
## 📌 Introduction

**Projet Ultimate-LIFKAS** – UE LIFAP4  
**Auteurs :**

-   TEMIRBOULATOV KOUREICH – _p1707160_
    
-   BENZIANE ABDELDJALLIL – _p1919796_
    
-   MA SHENGQI – _p2108131_
    

Ultimate-LIFKAS est un jeu vidéo développé en **C++** avec **SDL/SDL2**.  
Ce projet a été réalisé dans le cadre de l’UE [LIFAP4](http://licence-info.univ-lyon1.fr/LIFAP4).

📂 **Contenu du projet :**

-   **Makefile** pour compiler le jeu
    
-   **Dossier `src`** avec :
    
    -   `/core` → noyau du programme
        
    -   `/txt` → interface console
        
    -   `/sdl2` → interface graphique SDL
        

🎮 **Modes de jeu :**

-   Version console (texte)
    
-   Version graphique avec SDL
    

💻 **Compatibilité :**

-   Linux
    
-   Windows (via WSL)
    
----------
## 🛠 Organisation des fichiers

Dossier/Fichier

Contenu

**`bin`**

Exécutables compilés (`./main_sdl`, `./main_txt`)

**`data`**

Images, audio, fichiers `.txt`

**`doc`**

Fichier `.doxy` pour générer la documentation Doxygen

**`doc/html/index.html`**

Documentation HTML générée

**`obj`**

Fichiers objets compilés

**`src/core`**

Noyau du jeu (`.cpp` et `.h`)

**`src/sdl2`**

Modules pour l’interface graphique SDL

**`src/txt`**

Modules pour l’interface texte

----------

## ⚙ Compilation

### 📦 Installation des dépendances (Linux / WSL)

`sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev imagemagick` 

### ▶ Compilation et exécution

`
# Compilation
make

# Lancer version texte
./bin/main_txt

# Lancer version SDL
./bin/main_sdl
` 

💡 Sous WSL, installez **XMing** pour l’affichage graphique.  
[Guide WSL sur le site du cours](https://perso.liris.cnrs.fr/alexandre.meyer/public_html/www/doku.php?id=lifap4#wsl_pour_faire_tourner_un_linux_ultra_leger_sous_windows)

----------

## 📚 Documentation

La documentation complète est disponible dans :  
`doc/html/index.html` _(générée avec Doxygen)_.

----------

### 🏗 Structure des classes

#### **1. `Camera`**

Gère le déplacement de la caméra en SDL.

-   `int decalageX(const Personnage &perso, const Terrain &ter)`
    

----------

#### **2. `Jeu`**

Classe principale :

-   Gestion du joueur, monstres, gravité, progression
    
-   Actions automatiques, collisions, ramassage d’items
    

----------

#### **3. `Terrain`**

-   Chargement et affichage des niveaux
    
-   Vérification des positions valides
    
-   Lecture et modification de cases
    

----------

#### **4. `Personnage`**

-   Mouvement, saut, attaque
    
-   Points de vie, dégâts, armure, inventaire
    

----------

#### **5. `Menu`**

-   Menu principal et options en mode texte
    

----------

#### **6. `Image`**

-   Chargement et affichage des textures SDL
    
-   Gestion des animations
    

----------

#### **7. `sdlJeu`**

-   Boucle graphique
    
-   Affichage du terrain, personnages, HUD
    
-   Gestion des événements SDL
    

----------

#### **8. `txtJeu`**

-   Boucle en mode texte
    

----------

#### **9. `winTxt`**

-   Affichage console : impression, nettoyage, pause
    

----------

## 🧪 Exécutables disponibles

Exécutable

Description

`bin/test`

Test de régression

`bin/main_sdl`

Version graphique SDL

`bin/main_txt`

Version texte
