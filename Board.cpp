//
// Created by אריה גרוס on 04 מאי 2018.
//

#include "Board.h"
#include <fstream>


Board::Board(){ //new empty constracrot

}
Board::Board(uint a) :board(new square[a*a]), length(a){ //new constracrot

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
istream& operator>>(istream & input, Board &board){
    uint counter=0;//for lines
    string st, line;
    input >> st;
    ifstream myfile (st);// from http://www.cplusplus.com/doc/tutorial/files/
    if (myfile.is_open()) {
        getline (myfile,line);//need one out of the loop, for creating the table
        uint lineLenght = line.length()-1;
        board.board = new square[lineLenght*lineLenght];
        board.length = lineLenght;

        do  {                       //for each line
            for(uint i=0; i<lineLenght;i++) {// //for each cell
                switch (line.at(i)){
                    case 'X': board[{counter,i}]='X';
                        break;
                    case 'O':board[{counter,i}]='O';
                        break;
                }
            }
            counter++;
        }
        while ( getline (myfile,line) );

        myfile.close();
    }
    else cout << "Unable to open file";
    return input;
}
string Board::draw (uint n) {
    const int cell = n/length;
    uint rowCount = 0;

    string fName = "board_picture", lName = ".ppm"; // find free filename
    uint mName = 0;
    bool nameExist= true;
    do {
        ifstream infile(fName+to_string(++mName)+lName);
        nameExist=infile.good(); }
    while(nameExist);

    ofstream imageFile(fName+to_string(mName)+lName);
    imageFile << "P6" << endl << n <<" " << n << endl << 255 << endl;
    for (int j = 0; j < n; ++j)  {
        int cellCount = -1; // because of the first border
        for (int i = 0; i < n; ++i) {
            if (j % cell == 0 || i % cell == 0
                    || j == n-1 || i == n-1 ) {
                imageFile << (char)0 << (char)0 << (char)0;
                cellCount++;
                continue;
            }
            if (board[rowCount*length+cellCount].shape == 'X') {
                if ( (i%cell) == (j%cell) || (i%cell) == cell - (j%cell) ){
                    imageFile << (char)255 << (char)0 << (char)0;
                    continue;}
            }
            if (board[rowCount*length+cellCount].shape == 'O') {
                int circle = ((i%cell)-(cell/2))*((i%cell)-(cell/2))+
                              ((j%cell)-(cell/2)) * ((j%cell)-(cell/2))-
                              (cell/2) * (cell/2);//circle, (x-x1)^2+(y-y1)^2=r^2
                if ( circle<0 ) {
                    imageFile << (char)0 << (char)0 << (char)255;
                    continue;
            }}

            imageFile << (char)255 << (char)255 << (char)255;
        }
        if (j % cell == 0 && j != 0)
            rowCount++;
    }
    imageFile.close();
    return fName+to_string(mName)+lName;
}

