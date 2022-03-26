#ifndef _VIE_H
#define _VIE_H

class Vie{

private:
int x,y;
char life='+';
bool estRamasser=false;


public:
Vie();
Vie(const int _x,const int _y);
getX()const;
getY()const;
setX();
setY();

};

#endif