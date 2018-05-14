//
// Created by אריה גרוס on 04 מאי 2018.
//

#include "Board.h"

Board::Board(size_t a) :board(new square[a*a]), length(a){ //new constracrot

}

Board::Board (Board &other) :board(new square[other.length*other.length]), length(other.length){ // copy constractor
    copy(other);
}
Board::~Board() { // destracrot
    delete [] board;
}

ostream & operator<<(ostream& os,const Board& b) { //print
    for(int i=0;i<b.length;i++){
        for (int j = 0; j < b.length; ++j) {
            os<<b.board[i*b.length+j];
        }
        os<<endl;
    }
    return os;
}



square & Board::operator[](Coordinate a) {// operator
    if(a.x>=length||a.y>=length) throw IllegalCoordinateException(a);
    return board[a.x*length+a.y];

}

char & Board::operator[](Coordinate a) const{// operator
    if(a.x>=length||a.y>=length) throw IllegalCoordinateException(a);
    return board[a.x*length+a.y].shape;

}

Board& Board::operator=(const char in) {//set operator
    if (in!='X'&&in!='O'&&in!='.') throw IllegalCharException(in);
    for(int i=0;i<this->length;i++){
        for (int j = 0; j < this->length; ++j) {
            this->board[i*this->length+j]=in;
        }
    }
    return *this;
}
void Board::copy (const Board &other) {//set copy board
    for(int i=0;i<this->length;i++){
        for (int j = 0; j < this->length; ++j) {
            this->board[i*this->length+j]=other.board[i*this->length+j];
        }
    }
}
Board& Board::operator=(const Board& in) {//set copy operator
    if(length!=in.length){
        delete [] board;
        board = new square[in.length*in.length];
        length = in.length;
    }
    copy(in);
    return *this;
}

bool Board::operator== (const Board &in) {
    if (length!=in.length)return  false;
    for(int i=0;i<this->length;i++){
        for (int j = 0; j < this->length; ++j) {
            if(this->board[i*length+j].shape!=in.board[i*length+j].shape) return false;
        }
    }
    return true;
}
