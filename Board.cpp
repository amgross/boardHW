//
// Created by אריה גרוס on 04 מאי 2018.
//

#include "Board.h"

Board::Board(size_t a) :board(new square[a*a]), length(a){

}

Board::Board (Board &other) :board(new square[other.length*other.length]), length(other.length){
    copy(other);
}
Board::~Board() {
    delete [] board;
}

ostream & operator<<(ostream& os,const Board& b) {
    for(int i=0;i<b.length;i++){
        for (int j = 0; j < b.length; ++j) {
            os<<b.board[i*b.length+j];
        }
        os<<endl;
    }
    return os;
}



square & Board::operator[](coordinates a) {
    if(a.x>=length||a.x<0||a.y>=length||a.y<0) throw IllegalCoordinateException(a);
    return board[a.x*length+a.y];

}

Board& Board::operator=(const char in) {
    if (in!='X'&&in!='O'&&in!='.') throw IllegalCharException(in);
    for(int i=0;i<this->length;i++){
        for (int j = 0; j < this->length; ++j) {
            this->board[i*this->length+j]=in;
        }
    }
    return *this;
}
void Board::copy (const Board &other) {
    for(int i=0;i<this->length;i++){
        for (int j = 0; j < this->length; ++j) {
            this->board[i*this->length+j]=other.board[i*this->length+j];
        }
    }
}
Board& Board::operator=(const Board& in) {
    copy(in);
    return *this;
}
