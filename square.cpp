//
// Created by אריה גרוס on 04 מאי 2018.
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