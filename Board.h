//
// Created by Kevin on 11/28/2016.
//

#ifndef SUDOKU_SUDOKUBOARD_H
#define SUDOKU_SUDOKUBOARD_H

#include <array>
#include <cstring>
#include "Square.h"

using namespace std;

class Board{

    friend ostream& operator<<(ostream& stream, Board& sudoku);

public:

    Board();

    string print();

    void createBoard();

private:

    static const int SIDE_SIZE = 9; //global const for size of board (one side, one cell)
    static const int SQUARE_SIZE = 3;

    int fullBoard [SIDE_SIZE] [SIDE_SIZE]; //9x9 array of ints
    Square squareBoard [SQUARE_SIZE] [SQUARE_SIZE]; //3x3 array of squares

    bool* checkRow(int row);
    bool* checkColumn(int row);

    bool createSquare(Square& square, int x, int y);

};

#endif //SUDOKU_SUDOKUBOARD_H
