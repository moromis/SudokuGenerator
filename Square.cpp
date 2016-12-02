//
// Created by Kevin on 11/30/2016.
//

#include "Square.h"

Square::Square(){
    x = 0;
    y = 0;
}

Square::Square(int _x, int _y) {
    x = _x;
    y = _y;
}

void Square::checkSquare(bool h[9]) {
    for (int i = 0; i < 9; ++i) {
        h[i] = hash[i];
    }
}

void Square::insertNumber(int i, int _x, int _y) {
    hash[i] = true;
    square[_x][_y] = i;
}

int Square::getX() {
    return x;
}

int Square::getY() {
    return y;
}
