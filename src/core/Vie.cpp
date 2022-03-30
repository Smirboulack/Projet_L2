#include "Vie.h"
#include <iostream>


Vie::Vie(){
    x=0;
    y=0;
    estRamasser=false;
    life=new char('+');
}

Vie::~Vie(){
    x=0;
    y=0;
    estRamasser=true;
    delete life;
    life=nullptr;
}

Vie::Vie(const int _x,const int _y){
    x=_x;
    y=_y;
    estRamasser=false;
    life=new char('+');
}

int Vie::getX()const{return x;}

char Vie::getchar()const{return *(life);}

char Vie::getbool()const{return estRamasser;}

int Vie::getY()const{return y;}

void Vie::setX(const int a){x=a;}

void Vie::setY(const int a){y=a;}
