//
// Created by אריה גרוס on 04 מאי 2018.
//

#ifndef BOARDHW_BOARD_H
#define BOARDHW_BOARD_H

#endif //BOARDHW_BOARD_H

#include <iostream>

using namespace std;
//class of board such that square i,j is board[length*i+j]

class coordinates {
public:
    int x;
    int y;

    friend ostream &operator<< (ostream &os, const coordinates &a);

    coordinates (int x, int y);
};

class square {

private:

    char shape;

public:
    friend class Board;

    square ();

    char &operator= (const char &in);

    square &operator= (const square &in);

    friend ostream &operator<< (ostream &os, const square &a);
};

class IllegalCoordinateException {
private:
    coordinates wrongPlace;
public:
    IllegalCoordinateException (coordinates bad);

    const coordinates &theCoordinate () const;
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
    size_t length;
    square *board;
    void copy(const Board& other);
public:

    Board (size_t a);
    Board (Board& other);

    ~Board ();

    friend ostream &operator<< (ostream &os, const Board &a);

    square &operator[] (coordinates a);

    Board &operator= (const char in);

    Board &operator= (const Board& in);

};

