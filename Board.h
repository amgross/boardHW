//
// Created by אריה גרוס on 04 מאי 2018.
//
#pragma once
#ifndef BOARDHW_BOARD_H
#define BOARDHW_BOARD_H

#endif //BOARDHW_BOARD_H

#include <iostream>

using namespace std;
//class of board such that square i,j is board[length*i+j]

class Coordinate { //the class of place in the board
public:
    uint x;
    uint y;

    friend ostream &operator<< (ostream &os, const Coordinate &a);//print

    Coordinate (uint x, uint y);//constractor
};

class square { // //the class of square in the board

private:

    char shape;

public:
    friend class Board;

    square ();//constractor

    char &operator= (const char &in);//set operator

    square &operator= (const square &in);//set operator

    friend ostream &operator<< (ostream &os, const square &a); // print
    
    bool operator== (const char &in) const;

    bool operator!= (const char &in) const;

    bool operator!= (const square &in) const;
};

class IllegalCoordinateException {
private:
    Coordinate wrongPlace;
public:
    IllegalCoordinateException (Coordinate bad);

    const Coordinate &theCoordinate () const;
};

class IllegalCharException {
private:
    int bad;
public:
    IllegalCharException (char bad);

    const char theChar () const;
};

class Board {
private:
    uint length;
    square *board;
    void copy(const Board& other);
public:
    Board ();
    Board (uint a);
    Board (Board& other);

    ~Board ();

    friend ostream &operator<< (ostream &os, const Board &a);//print

    square &operator[] (Coordinate a);// operator

    char &operator[] (Coordinate a) const;// operator

    Board &operator= (const char in);// set operator

    Board &operator= (const Board& in);// set copy operator

    bool operator== (const Board& in);

    friend istream& operator>>(istream & input, Board &board1); // input

    string draw (uint n);

    uint size() const { return length;};

};

