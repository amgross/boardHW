//
// Created by אריה גרוס on 15 מאי 2018.
//
#include "TicTacToe.h"
bool win(Coordinate last,Board check){
    bool flag = true;
    for(uint i=0;i<check.size();i++){
        if (check[last]!=check[{last.x,i}]){
            flag = false;
            break;
        }
    }
    if (flag) return true;
    flag = true;
    for(uint i=0;i<check.size();i++){
        if (check[last]!=check[{i,last.y}]){
            flag = false;
            break;
        }
    }
    if (flag) return true;
    if (flag) return true;
    flag = true;
    for(uint i=0;i<check.size();i++){
        if (check[last]!=check[{i,i}]){
            flag = false;
            break;
        }
    }
    if (flag) return true;
    flag = true;
    for(uint i=0;i<check.size();i++){
        if (check[last]!=check[{i,check.size()-1-i}]){
            flag = false;
            break;
        }
    }
    if (flag) return true;

    return false;
}
TicTacToe::TicTacToe (uint size) :MyBoard(size){
}

void TicTacToe::play (Player& xPlayer, Player& oPlayer) {
    xPlayer.myChar='X';
    oPlayer.myChar='O';
    MyBoard='.';
    for(uint i=0;i<MyBoard.size()*MyBoard.size()/2;i++){
        try {
            Coordinate put = xPlayer.play(MyBoard);
            if(MyBoard[put]!='.'){
                Winner=&oPlayer;
                return;
            }
            MyBoard[put] = 'X';
            if(win(put,MyBoard)){
                Winner=&xPlayer;
                return;
            }
        }catch(...){
            Winner=&oPlayer;
            return;
        }
        try {
            Coordinate put = oPlayer.play(MyBoard);
            if(MyBoard[put]!='.'){
                Winner=&xPlayer;
                return;
            }
            MyBoard[put] = 'O';
            if(win(put,MyBoard)){
                Winner=&oPlayer;
                return;
            }
        }catch(...){
            Winner=&xPlayer;
            return;
        }
    }
    if(MyBoard.size()%2==1){
        try {
            Coordinate put = xPlayer.play(MyBoard);
            if(MyBoard[put]!='.'){
                Winner=&oPlayer;
                return;
            }
            MyBoard[put] = 'X';
            if(win(put,MyBoard)){
                Winner=&xPlayer;
                return;
            }
        }catch(...){
            Winner=&oPlayer;
            return;
        }
    }
    Winner=&oPlayer;
}
