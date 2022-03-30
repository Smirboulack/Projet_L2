#include "Piece.h"
#include <iostream>

Piece::Piece(){
    x=0;
    y=0;
    coin=new char('$');
    estRamasser=false;
}

Piece::~Piece(){
    x=0;
    y=0;
    delete coin;
    coin=nullptr;
    estRamasser=true;
}

Piece::Piece(const int _x,const int _y){
    x=_x;
    y=_y;
    coin=new char('$');
    estRamasser=false;
}


int Piece::getX()const{
    return x;
}

int Piece::getY()const{
    return y;
}

char Piece::getchar()const{
    return *(coin);
}


void Piece::setX(const int a){
    x=a;
}


void Piece::setY(const int a){
    y=a;
}