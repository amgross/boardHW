//
// Created by אריה גרוס on 04 מאי 2018.
//

#ifndef BOARDHW_BOARD_H
#define BOARDHW_BOARD_H

#endif //BOARDHW_BOARD_H

#include <iostream>

using namespace std;
//class of board such that square i,j is board[length*i+j]

class coordinates { //the class of place in the board
public:
    int x;
    int y;

    friend ostream &operator<< (ostream &os, const coordinates &a);//print

    coordinates (int x, int y);//constractor
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
    
    bool operator== (const char &in);
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

    friend ostream &operator<< (ostream &os, const Board &a);//print

    square &operator[] (coordinates a);// operator

    Board &operator= (const char in);// set operator

    Board &operator= (const Board& in);// set copy operator

    bool operator== (const Board& in);

};

