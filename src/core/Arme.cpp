#include "Arme.h"
#include <iostream>


Arme::Arme(){
    x=0;
    y=0;
    weapon=new char('!');
    estRamasser=false;
}

Arme::~Arme(){
    estRamasser=true;
    x=0;
    y=0;
    delete weapon;
    weapon=nullptr;
}


Arme::Arme(const int _x,const int _y){
    x=_x;
    y=_y;
    weapon=new char('!');
    estRamasser=false;
}


int Arme::getX()const{return x;}


char Arme::getchar()const{return *(weapon);}


int Arme::getY()const{return y;}


void Arme::setX(const int a){x=a;}


void Arme::setY(const int a){y=a;}
