#include "Items.h"
#include <iostream>

Items::Items(){

    nb_items = (rand() % plage) + min;

     armes=new Arme[nb_items];
     armure=new Armure[nb_items];
     piece=new Piece[nb_items];
     vies=new Vie[nb_items];

     for (unsigned int i=0;i<nb_items;i++){
         int alearmex = rand()%101;
         int alearmey = (rand()%15)+3;

         int alearmurex = rand()%101;
         int alearmurey = (rand()%15)+3;

         int alepiecex = rand()%101;
         int alepiecey = (rand()%15)+3;

         int aleviesx = rand()%101;
         int aleviesy = (rand()%15)+3;

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
    return armes->getchar();
}
char Items::getchararmure()const{
    return armure->getchar();
}
char Items::getcharpiece()const{
    return piece->getchar();
}
char Items::getcharvie()const{
    return vies->getchar();
}

int Items::getarmex()const{
    return armes->getX();
}

int Items::getarmey()const{
    return armes->getY();
}

int Items::getarmurex()const{
    return armure->getX();
}

int Items::getarmurey()const{
    return armure->getY();
}

int Items::getviex()const{
    return vies->getX();
}

int Items::getviey()const{
    return vies->getY();
}

int Items::getpiecex()const{
    return piece->getX();
}

int Items::getpiecey()const{
    return piece->getY();
}

void Items::setarmex(const int a){
 armes->setX(a);
}
void Items::setarmey(const int a){
armes->setY(a);
}

void Items::setarmexy(const int a,const int b){
     armes->setX(a);
     armes->setY(b);
}

void Items::setarmurex(const int a){
armure->setX(a);
}
void Items::setarmurey(const int a){
armure->setY(a);
}

void Items::setarmurexy(const int a,const int b){
     armure->setX(a);
     armure->setY(b);
}

void Items::setpiecex(const int a){
piece->setX(a);
}
void Items::setpiecey(const int a){
    piece->setY(a);
}

void Items::setpiecexy(const int a,const int b){
     piece->setX(a);
     piece->setY(b);
}

void Items::setviex(const int a){
    vies->setX(a);
}

void Items::setviey(const int a){
vies->setY(a);
}

void Items::setviexy(const int a,const int b){
     vies->setX(a);
     vies->setY(a);
}


const Arme& Items::getarme()const{return *(armes);}
const Armure& Items::getarmure()const{return *(armure);}
const Piece& Items::getpiece()const{ return *(piece);}
const Vie& Items::getvies()const{return *(vies);}   

const unsigned int Items::getnbitems()const{return nb_items;}