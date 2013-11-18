//
// Created by Valeriy Chevtaev on 11/18/13.
// Copyright (c) 2013 7bit. All rights reserved.
//


#include "board.h"
#include <algorithm>

#ifndef __game_H_
#define __game_H_

namespace week04 {

class player_color_parser {
public:
    board_state parse(string selected_color) const {
        transform(selected_color.begin(), selected_color.end(), selected_color.begin(), ::tolower);

        if (selected_color == "b" || selected_color == "blue") {
            return BLUE;
        } else {
            return RED;
        }
    }
};

enum game_state {
    NEW, IN_PROGRESS, FINISHED
};

class game {
private:
    int total_turns_;
    game_state state_;
    board_state last_move_by_player_;
    unique_ptr<board> main_board_;

    inline void init_board(int size) {
        main_board_ = unique_ptr<board>(new board(size));
    }

    inline void setState(game_state state) {
        state_ = state;
    }

    inline game_state getState() const {
        return state_;
    }

    inline bool is_finished() const {
        return state_ == FINISHED;
    }

    inline board_state player_won() const {
        return last_move_by_player_;
    }

public:
    game() : state_(NEW), total_turns_(0), last_move_by_player_(BLUE) {
    };

    void run(int argc, const char ** argv);

}; // class game
}; // namespace week04


#endif //__game_H_
