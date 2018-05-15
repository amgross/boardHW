//
// Created by אריה גרוס on 14 מאי 2018.
//
#pragma once
#ifndef BOARDHW_MASTER_PLAYER_H
#define BOARDHW_MASTER_PLAYER_H
#include "Board.h"
class  Player {

public:
    char myChar;
    virtual char getChar() const { return myChar;};
    virtual const string name() const=0 ;
    virtual const Coordinate play(const Board& board) =0;
};
#endif //BOARDHW_MASTER_PLAYER_H

