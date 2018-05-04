//
// Created by אריה גרוס on 04 מאי 2018.
//

#ifndef BOARDHW_BOARD_H
#define BOARDHW_BOARD_H

#endif //BOARDHW_BOARD_H

#include <iostream>
using namespace std;
//class of board such that square i,j is board[length*i+j]
typedef struct{
    int x;
    int y;
}coordinates;
class Board{
private:
    size_t length;
    char* board;

public:

    Board(size_t a);

    ~Board();

    friend ostream& operator<<(ostream& os,const Board& a);
    char& operator[](coordinates a);

};
