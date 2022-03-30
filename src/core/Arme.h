#ifndef _Arme_H
#define _Arme_H

class Arme{

private:
int x,y;
char * weapon;
bool estRamasser;


public:

Arme();
~Arme();
Arme(const int _x,const int _y);
int getX()const;
char getchar()const;
char getbool()const;
int getY()const;
void setX(const int a);
void setY(const int a);



};


#endif