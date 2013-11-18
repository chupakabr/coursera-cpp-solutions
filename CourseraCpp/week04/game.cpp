//
// Created by Valeriy Chevtaev on 11/18/13.
// Copyright (c) 2013 7bit. All rights reserved.
//


#include "game.h"

using namespace std;

namespace week04 {

    // game state to string
    ostream& operator<<(ostream& out, const game_state& state) {
        switch (state) {
            case week04::NEW:
                out << "NEW";
                break;
            case week04::IN_PROGRESS:
                out << "IN PROGRESS";
                break;
            default:
                out << "FINISHED";
        }
        return out;
    }

    // game entry point
    void game::run(int argc, const char ** argv) {
        cout << "Welcome to Hex Game!" << endl;

        int board_size = 0;
        while (board_size < 3) {
            cout << "Please, enter board size, number more than 3: ";
            cin >> board_size;
        }
        cout << "Great, board size is " << board_size << "x" << board_size << endl;

        cout << "Please enter the color you want to play, (b)lue or (r)ed: ";
        string color;
        player_color_parser color_parser;
        cin >> color;
        board_state selected_color = color_parser.parse(color);
        cout << "Superb! You are playing with " << selected_color << " color" << endl;

        // Init board and start playing
        init_board(board_size);
//        while (!is_finished()) {
//            // TODO implementation should be provided in week 5
//        }

        // Print results
        if (is_finished()) {
            cout << endl << "Player " << player_won() << " won in " << total_turns_ << " turns!" << endl;
        } else {
            cout << endl << "The game has not been finished. Only " << total_turns_ << " turns has been made." << endl;
        }

        cout << "Final board state is " << *main_board_ << endl;
    }

}; // namespace week04
