#ifndef _Piece_H
#define _Piece_H

class Piece{

private:
int x,y;
char coin='€';
bool estRamasser=false;


public:
Piece();
Piece(const int _x,const int _y);
getX()const;
getY()const;
setX();
setY();



};

#endif