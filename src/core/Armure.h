#ifndef _Armure_H
#define _Armure_H

class Armure{

private:
int x,y;
char * armor;
bool estRamasser;


public:
Armure();
~Armure();
Armure(const int _x,const int _y);
int getX()const;
char getchar()const;
char getbool()const;
int getY()const;
void setX(const int a);
void setY(const int a);



};


#endif