//
// Created by אריה גרוס on 14 מאי 2018.
//
#pragma once
#ifndef BOARDHW_MASTER_PLAYER_H
#define BOARDHW_MASTER_PLAYER_H

#endif //BOARDHW_MASTER_PLAYER_H

#include "Board.h"
class  Player {
protected:
    char myChar;
public:
    virtual const string name() const  { return "XYPlayer"; }
    virtual const Coordinate play(const Board& board) ;
};