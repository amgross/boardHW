//
// Created by אריה גרוס on 14 מאי 2018.
//

#include "Champion.h"
const Coordinate Champion::play(const Board& board) {
    for (uint x=0; x<board.size(); ++x) {
        for (uint y=0; y<board.size(); ++y) {
            Coordinate c{x,y};
            if (board[c]=='.') {
                return c;
            }
        }
    }
    return {0,0};  // did not find an empty square - play on the top-left
}