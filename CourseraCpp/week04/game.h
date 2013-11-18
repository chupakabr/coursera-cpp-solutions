//
// Created by Valeriy Chevtaev on 11/18/13.
// Copyright (c) 2013 7bit. All rights reserved.
//


#include "board.h"

#ifndef __game_H_
#define __game_H_

using namespace std;

namespace week04 {
class game {
private:
    unique_ptr<board> main_board_;

    inline void init_board(int size) {
        main_board_ = unique_ptr<board>(new board(size));
    }

public:
    game() {
    };

    void run(int argc, const char ** argv);

}; // class game
}; // namespace week04


#endif //__game_H_
