//
// Created by Kevin on 11/30/2016.
//

#include "Square.h"

Square::Square(int _x, int _y) {
    x = _x;
    y = _y;
}

void Square::checkSquare(bool*& h) {
    h = hash;
}

void Square::insertNumber(int i) {
    hash[i] = true;
}
