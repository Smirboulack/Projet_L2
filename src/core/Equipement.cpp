#include "Equipement.h"
#include <iostream>


Equipement::Equipement(){
    x=0;
    y=0;
    direc=0;
}

Equipement::Equipement(float _x,float _y,float _direc){
    x= _x;
    y= _y;
    direc= _direc;
}


float Equipement::getX()const{
    return x;
}

float Equipement::getY()const{
    return y;
}


float Equipement::getDirec()const{
    return direc;
}

void Monstre::tirer(const Monstre & monst ,const Terrain & Eterr){


}

bool Monstre::estRamasser(Personnage & Epers){

if(Epers.getX()==getX() && Epers.getY()==getY()){
    if(type_equip==1) Epers.inventaire.psuh();
    if(type_equip==2) Epers.vie++;
    return 1;
}else{
    return 0;
}


}
