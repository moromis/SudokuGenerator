//
// Created by Kevin on 11/30/2016.
//

#ifndef SQUARE_H
#define SQUARE_H

class Square{

public:

    Square();
    Square(int _x, int _y);

    void checkSquare(bool h[9]);

    int getX();
    int getY();

    void insertNumber(int i, int _x, int _y);

private:

    int x;
    int y;

    static const int SQUARE_SIZE = 3;

    int square [SQUARE_SIZE] [SQUARE_SIZE] = { {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1} }; //2d array to represent a square on the board, 3x3

    bool hash [SQUARE_SIZE * SQUARE_SIZE] = {false, false, false, false, false, false,false, false, false};

};

#endif //SQUARE_H
