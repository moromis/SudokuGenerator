//
// Created by Kevin on 11/28/2016.
//

#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <fstream>

#include "Board.h"

/*
 * Default constructor for Board
 */
Board::Board() {

    //create the seed for our random number generation later in the program
    int  r;
    srand(time(0));
    r = rand(); //throw away the first value for truly random results (rand() with time(0) as a seed diverges quickly)

    initialize();
}

void Board::initialize() {

    for (int i = 0; i < SIDE_SIZE; i++) {
        for (int j = 0; j < SIDE_SIZE; j++) {
            solvedBoard[j][i] = -1;
        }
    }

    for (int i = 0; i < SQUARE_SIZE; i++) {
        for (int j = 0; j < SQUARE_SIZE; j++) {
            Square square(j, i);
            squareBoard[j][i] = square;
        }
    }

}

void Board::generate() {
    bool success;
    do{
        success = createSolvedBoard(); //attempt to make a board
    }while(!success); //keep attempting till we are successful

    createUnsolvedBoard(); //one we have a solved board we "unsolve" it by removing a fraction of the numbers.

    outputToFile();
}

bool Board::createSolvedBoard() {

    initialize(); //reset the board to default values

    bool success;
    for (int i = 0; i < SQUARE_SIZE; i++) {
        for (int j = 0; j < SQUARE_SIZE; j++) {

            success = createSquare(squareBoard[j][i], j, i); //attempt to create a board

            if(!success) return false; //if we ever fail to create a square we need to start again.
        }
    }

    return true; //if we made it here we successfully made a board
}

/*
 * O(n^2)
 */
bool Board::createSquare(Square& square, int x, int y) {

    //j = x, i = y
    for (int i = 0; i < SQUARE_SIZE; i++) {
        for (int j = 0; j < SQUARE_SIZE; j++) {

            int relativeX = square.getX() * SQUARE_SIZE + j;
            int relativeY = square.getY() * SQUARE_SIZE + i;

            bool hash[9] = {false, false, false, false, false, false,false, false, false};

            //check square
            square.checkSquare(hash);
            //check column
            checkColumn(relativeX, hash);
            //check row
            checkRow(relativeY, hash);

            bool canInsert = false; //start with the idea that we cannot in fact insert
            for (int k = 0; k < SIDE_SIZE; k++) {
                if(!hash[k]) canInsert = true; //if we find a false in our hash, we can insert
            }

            //if we have found that we are still able to insert
            if(canInsert) {

                do { //now based on hash decide randomly what number should go in this spot
                    int random = (rand() % 9);
                    if (!hash[random]) { //if it's valid to insert
                        solvedBoard[relativeX][relativeY] = random;
                    }
                } while (solvedBoard[relativeX][relativeY] == -1);

            }else{  //in this case our has is composed entirely of true, which means we cannot insert. we need to rerun
                //the program.

                return false;

            }

            square.insertNumber(solvedBoard[relativeX][relativeY], j, i);


        }
    }

    return true; //we made it all the way to the end, return that we successfully made a square

}

void Board::checkColumn(int column, bool hash[9]) {
    for (int i = 0; i < SIDE_SIZE; i++) {
        hash[solvedBoard[column][i]] = true;
    }
}

void Board::checkRow(int row, bool hash[9]) {
    for (int i = 0; i < SIDE_SIZE; i++) {
        hash[solvedBoard[i][row]] = true;
    }
}

void Board::createUnsolvedBoard(){

    for(int i = 0; i < SIDE_SIZE; i++){
        for(int j = 0; j < SIDE_SIZE; j++){
            int random = rand() % 3;
            if(random == 1 || random == 2) unsolvedBoard[j][i] = -1;
            else unsolvedBoard[j][i] = solvedBoard[j][i];
        }
    }
}

/*
 * Print out the board
 *
 *      j ---------------->
 *
 *  i
 *  |     0,0  .  .  .  8,0
 *  |
 *  |      .             .
 *  |      .  [.  .  .]  .
 *  |      .             .
 *  |
 *  v     8,0  .  .  .  8,8
 *
 *
 * O(n^2)
 */
string Board::printSolvedBoard() {

    stringstream ss;

    ss << " -----------------------------------\r" << endl;

    for (int i = 0; i < SIDE_SIZE; i++) {

        ss << "|  ";
        for (int j = 0; j < SIDE_SIZE; j++) {

            ss << (solvedBoard [j] [i] + 1) << "  ";

            if ((j+1) % 3 == 0) ss << "|  ";

        }

        ss << "\r" << endl;
        ss << "|                                   |\r" << endl;
        if((i+1) % 3 == 0) ss << " -----------------------------------\r" << endl;

    }

    return ss.str();
}

string Board::printUnsolvedBoard() {

    stringstream ss;

    ss << " -----------------------------------\r" << endl;

    for (int i = 0; i < SIDE_SIZE; i++) {

        ss << "|  ";
        for (int j = 0; j < SIDE_SIZE; j++) {

            if(unsolvedBoard[j][i] == -1){
                ss << "   ";
            }else {
                ss << (unsolvedBoard[j][i] + 1) << "  ";
            }

            if ((j+1) % 3 == 0) ss << "|  ";

        }

        ss << "\r" << endl;
        ss << "|                                   |\r" << endl;
        if((i+1) % 3 == 0) ss << " -----------------------------------\r" << endl;

    }

    return ss.str();
}

/*
 * overload of operator<<
 */
ostream& operator<<(ostream& stream, Board& sudoku) {
    stream << sudoku.printSolvedBoard() << endl << endl << sudoku.printUnsolvedBoard();
    return stream;
}

void Board::outputToFile() {
    ofstream stream;
    stream.open(to_string(time(0)) + ".txt");
    if(stream.is_open()) {
        stream << printUnsolvedBoard();
        for(int i = 0; i < 6; i++) stream << "\r" << endl;
        stream << printSolvedBoard();
    }
    stream.close();
}
