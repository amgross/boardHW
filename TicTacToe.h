//
// Created by אריה גרוס on 14 מאי 2018.
//
#pragma once
#ifndef BOARDHW_MASTER_TICTACTOE_H
#define BOARDHW_MASTER_TICTACTOE_H
#include "Board.h"
#include "Player.h"

/*
 * class that presents games between players on board with the same size
 */
class TicTacToe{
private:
    //board present how the board looked when the last game finished
    Board MyBoard;
    //remembers who won the last game
    Player* Winner;
public:
    //constructor that gets the length of the board
    TicTacToe(uint size);

    const Player& winner() const{ return *Winner;};

    const Board& board() const{return MyBoard;}
    /*
     * checking how each p[layer will play against the other
     * saving who win and how the board will lok in the end of the game
     */
    void play(Player& xPlayer,Player& oPlayer);

};
#endif //BOARDHW_MASTER_TICTACTOE_H
