//
// Created by Kevin on 11/28/2016.
//

#include <iostream>
#include <sstream>
#include <math>

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
            Square square(i, j);
            squareBoard[i][j] = square;
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

    //i = x, j = y
    for (int i = 0; i < SQUARE_SIZE; ++i) {
        for (int j = 0; j < SQUARE_SIZE; ++j) {

            //check square
            square.checkSquare(hash);
            //check column
            checkColumn(square.getX() * SQUARE_SIZE + i, hash);
            //check row
            checkRow(square.getY() * SQUARE_SIZE + i, hash);

            //now based on hash decide randomly what number should go in this spot
            do{
                int random = (rand() % 9);
                if(!hash[random]) { //if it's valid to insert
                    fullBoard[i][j] = random;
                }
            }while(fullBoard[i][j] == -1);

            square.insertNumber(fullBoard[i][j]);

        }
    }

    delete[] hash;
}

void Board::checkColumn(int column, bool*& hash) {
    for (int i = 0; i < SIDE_SIZE; ++i) {
        hash[fullBoard[column][i]] = true;
    }
}

void Board::checkRow(int row, bool*& hash) {
    for (int i = 0; i < SIDE_SIZE; ++i) {
        hash[fullBoard[i][row]] = true;
    }
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
