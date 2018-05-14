//
// Created by אריה גרוס on 04 מאי 2018.
//
#include "Board.h"
ostream & operator<<(ostream &os, const Coordinate &a) { // print
    return os<<a.x<<","<<a.y;
}

Coordinate::Coordinate(int x, int y) { //constractor
    this->x=x;
    this->y=y;
}
