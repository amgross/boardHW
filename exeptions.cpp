//
// Created by אריה גרוס on 04 מאי 2018.
//

#include "Board.h"
IllegalCoordinateException::IllegalCoordinateException(Coordinate bad) :wrongPlace(bad.x,bad.y) {
    wrongPlace.x=bad.x;
    wrongPlace.y=bad.y;
}

const Coordinate& IllegalCoordinateException::theCoordinate() const{
    return  wrongPlace;
}

IllegalCharException::IllegalCharException(char bad) :bad(bad) {}

const char  IllegalCharException::theChar() const {

    return bad;
}