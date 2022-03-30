#include "Armure.h"
#include <iostream>


Armure::Armure(){
    x=0;
    y=0;
    armor=new char('O');
    estRamasser=false;
}

Armure::~Armure(){
    x=0;
    y=0;
    estRamasser=true;
    delete armor;
    armor=nullptr;

}

Armure::Armure(const int _x,const int _y){
    x=_x;
    y=_y;
    armor=new char('O');
    estRamasser=false;
}


int Armure::getX()const{return x;}


char Armure::getchar()const{return *(armor);}

char Armure::getbool()const{return estRamasser;}


int Armure::getY()const{return y;}


void Armure::setX(const int a){x=a;}


void Armure::setY(const int a){y=a;}
