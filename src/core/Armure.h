#ifndef _Armure_H
#define _Armure_H

class Armure{

private:
int x,y;
char armor='¤';
bool estRamasser=false;


public:
Arme();
Arme(const int _x,const int _y);
getX()const;
getY()const;
setX();
setY();



};


#endif