//
// Created by אריה גרוס on 14 מאי 2018.
//
#pragma once
#ifndef BOARDHW_MASTER_TICTACTOE_H
#define BOARDHW_MASTER_TICTACTOE_H
#include "Board.h"
#include "Player.h"
class TicTacToe{
private:
    Board MyBoard;
    Player* Winner;
public:
    TicTacToe(uint size);

    const Player& winner() const{ return *Winner;};

    const Board& board() const{return MyBoard;}

    void play(Player& xPlayer,Player& oPlayer);

};
#endif //BOARDHW_MASTER_TICTACTOE_H
