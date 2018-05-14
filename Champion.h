//
// Created by אריה גרוס on 14 מאי 2018.
//

#ifndef BOARDHW_MASTER_CHAMPION_H
#define BOARDHW_MASTER_CHAMPION_H

#endif //BOARDHW_MASTER_CHAMPION_H
#include "Player.h"
/*
	This player will win the dummy players
*/
class Champion: public Player {
public:
    const string name() const override { return "arye and ytshak"; }
    const Coordinate play(const Board& board) override;
};