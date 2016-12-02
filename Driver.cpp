//
// Created by Kevin on 11/28/2016.
//

#include <iostream>
#include "Board.h"

using namespace std;

int main(){

    Board board;

    cout << board;

    board.generate();

    cout << board;

    return 0;
}