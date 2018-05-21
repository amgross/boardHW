//
// Created by arye gross on 04  2018.
//
#include "Board.h"

square::square(){
    shape='.';//set on empty
}

char& square::operator=(const char& in){//set operator
    if (in!='X'&&in!='O'&&in!='.') throw IllegalCharException(in);
    shape=in;
    return shape;
}

square& square::operator=(const square& in){//set operator
    shape=in.shape;
    return *this;
}

ostream& operator<<(ostream& os,const square& a){//print
    return os<<a.shape;
}
bool square::operator== (const char &in) const {
    if (shape == in) return  true;
    return false;
}

bool square::operator!= (const char &in) const {
    if (shape != in) return  true;
    return false;
}

bool square::operator!= (const square &in) const {
    if (shape != in.shape) return  true;
    return false;
}