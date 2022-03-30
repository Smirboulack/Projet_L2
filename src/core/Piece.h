#ifndef _Piece_H
#define _Piece_H


class Piece{

private:
int x,y;
char * coin;
bool estRamasser;


public:
Piece();
~Piece();
Piece(const int _x,const int _y);
int getX()const;
char getchar()const;
char getbool()const;
int getY()const;
void setX(const int a);
void setY(const int a);



};

#endif