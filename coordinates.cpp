//
// Created by אריה גרוס on 04 מאי 2018.
//
#include "Board.h"
ostream & operator<<(ostream &os, const coordinates &a) { // print
    return os<<a.x<<","<<a.y;
}

coordinates::coordinates(int x, int y) { //constractor
    this->x=x;
    this->y=y;
}
