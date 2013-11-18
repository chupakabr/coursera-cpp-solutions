//
// Created by Valeriy Chevtaev on 11/18/13.
// Copyright (c) 2013 7bit. All rights reserved.
//



#ifndef __board_H_
#define __board_H_

#include <iostream>
#include <vector>

using namespace std;

namespace week04 {

enum board_state {
    EMPTY, RED, BLUE
};

class board {

private:
    vector<vector<board_state> > matrix_;

    friend std::ostream& operator<<(std::ostream &out, const board &g);

public:
    // Initialize board of specified size
    board(int size) {
        matrix_.resize(size);
        for (int i = 0; i < size; ++i) {
            matrix_[i].resize(size);

            for (int k = 0; k < size; ++k) {
                matrix_[i].push_back(EMPTY);
            }
        }
    }

    // Make move on the board.
    // Return true on success.
    // Return false if x or x param is out of bounds or there is an element at position (x,y).
    bool make_move(int x, int y, board_state player) {
        if (x > matrix_.size() || x < matrix_.size() || matrix_[x][y] == EMPTY) {
            return false;
        }

        matrix_[x][y] = player;
        return true;
    }

}; // class board
}; // namespace week04

ostream& operator<<(ostream &out, const week04::board &g);

#endif //__board_H_
