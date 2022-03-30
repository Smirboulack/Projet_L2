#include "Items.h"
#include <stdlib.h>
#include <iostream>

Items::Items(){
     armes=new Arme[2];
     armure=new Armure[2];
     piece=new Piece[2];
     vies=new Vie[2];

     for (unsigned int i=0;i<2;i++){
         int alearmex = rand()%42;
         int alearmey = (rand()%10)+3;

         int alearmurex = rand()%42;
         int alearmurey = (rand()%10)+3;

         int alepiecex = rand()%42;
         int alepiecey = (rand()%10)+3;

         int aleviesx = rand()%42;
         int aleviesy = (rand()%10)+3;


        armes[i].setX(alearmex);
        armes[i].setY(alearmey);

        armure[i].setX(alearmurex);
        armure[i].setY(alearmurey);

        piece[i].setX(alepiecex);
        piece[i].setY(alepiecey);

        vies[i].setX(aleviesx);
        vies[i].setY(aleviesy);
     }

}

Items::~Items(){

    delete armes;
    delete armure;
    delete piece;
    delete vies;

    armes->~Arme();
    armure->~Armure();
    piece->~Piece();
    vies->~Vie();

 armes=nullptr;
 armure=nullptr;
 piece=nullptr;
 vies=nullptr;

}


char Items::getchararme()const{
    return armes[0].getchar();
}
char Items::getchararmure()const{
    return armure[0].getchar();
}
char Items::getcharpiece()const{
    return piece[0].getchar();
}
char Items::getcharvie()const{
    return vies[0].getchar();
}

int Items::getarmex()const{
    return armes[0].getX();
}

int Items::getarmey()const{
    return armes[0].getY();
}

int Items::getarmurex()const{
    return armure[0].getX();
}

int Items::getarmurey()const{
    return armure[0].getY();
}

int Items::getviex()const{
    return vies[0].getX();
}

int Items::getviey()const{
    return vies[0].getY();
}

int Items::getpiecex()const{
    return piece[0].getX();
}

int Items::getpiecey()const{
    return piece[0].getY();
}

void Items::setarmex(const int a){
 armes[0].setX(a);
}
void Items::setarmey(const int a){
armes[0].setY(a);
}

void Items::setarmexy(const int a,const int b){
     armes[0].setX(a);
     armes[0].setY(b);
}

void Items::setarmurex(const int a){
armure[0].setX(a);
}
void Items::setarmurey(const int a){
armure[0].setY(a);
}

void Items::setarmurexy(const int a,const int b){
     armure[0].setX(a);
     armure[0].setY(b);
}

void Items::setpiecex(const int a){
piece[0].setX(a);
}
void Items::setpiecey(const int a){
    piece[0].setY(a);
}

void Items::setpiecexy(const int a,const int b){
     piece[0].setX(a);
     piece[0].setY(b);
}

void Items::setviex(const int a){
    vies[0].setX(a);
}

void Items::setviey(const int a){
vies[0].setY(a);
}

void Items::setviexy(const int a,const int b){
     vies[0].setX(a);
     vies[0].setY(a);
}


const Arme& Items::getarme()const{
    return *(armes);
}
const Armure& Items::getarmure()const{
    return *(armure);
}
const Piece& Items::getpiece()const{
    return *(piece);
}
const Vie& Items::getvies()const{
    return *(vies);
}   