#include "Items.h"
#include <iostream>


Items::Items(){

}

Items::Items(int _x,int _y){
    x= _x;
    y= _y;   
}

int Items::getX()const{
    return x;
}

int Items::getY()const{
    return y;
}


