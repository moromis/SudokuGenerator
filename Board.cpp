//
// Created by Kevin on 11/28/2016.
//

#include <iostream>
#include <sstream>
#include "Board.h"
#include "Square.cpp"

/*
 * Default constructor for Board
 */
Board::Board() {

    for (int i = 0; i < SIDE_SIZE; ++i) {
        for (int j = 0; j < SIDE_SIZE; ++j) {
            fullBoard[i][j] = -1;
        }
    }

    for (int i = 0; i < SQUARE_SIZE; ++i) {
        for (int j = 0; j < SQUARE_SIZE; ++j) {
            fullBoard[i][j] = -1;
        }
    }

}

void Board::createBoard() {
    for (int i = 0; i < SQUARE_SIZE; ++i) {
        for (int j = 0; j < SQUARE_SIZE; ++j) {
            createSquare(squareBoard[i][j], i, j);
        }
    }
}

/*
 * O(n^2)
 */
bool Board::createSquare(Square& square, int x, int y) {

    bool* hash = new bool[9];

    for (int i = 0; i < SQUARE_SIZE; ++i) {
        for (int j = 0; j < SQUARE_SIZE; ++j) {
            //check square
            square.checkSquare(hash);
            //check column
            //check row
        }
    }

    delete[] hash;
}

bool* Board::checkColumn(int row) {

}

bool* Board::checkRow(int row) {
    return false;
}

/*
 * Print out the board
 *
 *  O(n^2)
 */
string Board::print() {

    stringstream ss;

    ss << " -----------------------------------\n";

    for (int i = 0; i < SIDE_SIZE; ++i) {

        ss << "|  ";
        for (int j = 0; j < SIDE_SIZE; ++j) {

            ss << abs(fullBoard [i] [j]) << "  ";

            if ((j+1) % 3 == 0) ss << "|  ";

        }

        ss << "\n";
        if((i+1) % 3 == 0) ss << " -----------------------------------\n";

    }

    return ss.str();
}

/*
 * overload of operator<<
 */
ostream& operator<<(ostream& stream, Board& sudoku) {
    stream << sudoku.print();
    return stream;
}
