#ifndef _VIE_H
#define _VIE_H

class Vie{

private:
int x,y;
char * life;
bool estRamasser;


public:
Vie();
~Vie();
Vie(const int _x,const int _y);
int getX()const;
char getchar()const;
int getY()const;
void setX(const int a);
void setY(const int a);

};

#endif