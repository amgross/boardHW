//
// Created by אריה גרוס on 14 מאי 2018.
//

#include "Champion.h"
const Coordinate Champion::play(const Board& board) {
    if(board[{board.size()-1,board.size()-1}]=='.' ) return {board.size()-1,board.size()-1};//first move - fill the botom right corner
    //if i'm first or playing against xyplayer fill the bottom row
    if(board[{1,0}]=='.'||board[{0,board.size()-1}]!='.'){

        for (uint i=0;i<board.size()-1;i++){
            if(board[{i,board.size()-1}]=='.')return {i,board.size()-1};
        }
    }
        //if i'm second and playing against yxplayer fill the rught row
    else{
        for (uint i=0;i<board.size()-1;i++){
            if(board[{board.size()-1,i}]=='.')return {board.size()-1,i};
        }
    }
    // if have problom, find some empty place and fill it
    for (uint y=0; y<board.size(); ++y) {
        for (uint x=0; x<board.size(); ++x) {
            Coordinate c{x,y};
            if (board[c]=='.') {
                return c;
            }
        }
    }
    return {0,0};  // did not find an empty square - play on the top-left
}
