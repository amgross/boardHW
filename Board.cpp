//
// Created by אריה גרוס on 04 מאי 2018.
//

#include "Board.h"

Board::Board(size_t a) :board(new char[a*a]), length(a){
    for(int i=0;i<a*a;i++){
        board[i]='.';
    }
}
Board::~Board() {
    delete [] board;
}

ostream & operator<<(ostream& os,const Board& b) {
    for(int i=0;i<b.length;i++){
        for (int j = 0; j < b.length; ++j) {
            os<<b.board[i*b.length+j];
        }
        if(i<b.length-1) os<<endl;
    }
    return os;
}

char& Board::operator[](coordinates a) {
    return board[a.x*length+a.y];

}
