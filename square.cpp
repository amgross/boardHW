//
// Created by אריה גרוס on 04 מאי 2018.
//
#include "Board.h"

square::square(){
    shape='.';
}

char& square::operator=(const char& in){
    if (in!='X'&&in!='O'&&in!='.') throw IllegalCharException(in);
    shape=in;
    return shape;
}

square& square::operator=(const square& in){
    shape=in.shape;
    return *this;
}

ostream& operator<<(ostream& os,const square& a){
    return os<<a.shape;
}