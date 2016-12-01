//
// Created by Kevin on 11/30/2016.
//

#ifndef SUDOKUGENERATOR_SQUARE_H
#define SUDOKUGENERATOR_SQUARE_H

class Square{

public:

    Square(int _x, int _y);

    void checkSquare(bool*& h);

    int getX();
    int getY();

    void insertNumber(int i);

private:

    int x;
    int y;

    static const int SQUARE_SIZE = 3;

    int square [SQUARE_SIZE] [SQUARE_SIZE] = { {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1} }; //2d array to represent a square on the board, 3x3

    bool hash [SQUARE_SIZE * SQUARE_SIZE];

};

#endif //SUDOKUGENERATOR_SQUARE_H
