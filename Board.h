//
// Created by Kevin on 11/28/2016.
//

#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <array>
#include <cstring>
#include "Square.h"

using namespace std;

class Board{

    friend ostream& operator<<(ostream& stream, Board& sudoku);

public:

    Board();

    string print();

    void generate();

private:

    static const int SIDE_SIZE = 9; //global const for size of board (one side, one cell)
    static const int SQUARE_SIZE = 3;
    int farthestX = 0;
    int farthestY = 0;

    int fullBoard [SIDE_SIZE] [SIDE_SIZE]; //9x9 array of ints
    Square squareBoard [SQUARE_SIZE] [SQUARE_SIZE]; //3x3 array of squares

    void initialize();

    bool createBoard();

    bool createSquare(Square& square, int x, int y);

    void checkRow(int row, bool hash[9]);
    void checkColumn(int row, bool hash[9]);

};

#endif //SUDOKUBOARD_H
