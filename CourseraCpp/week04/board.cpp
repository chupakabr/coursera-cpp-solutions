//
// Created by Valeriy Chevtaev on 11/18/13.
// Copyright (c) 2013 7bit. All rights reserved.
//


#include "board.h"

namespace week04 {

    // board state or user color to string
    ostream& operator<<(ostream& out, const board_state& state) {
        switch (state) {
            case week04::BLUE:
                out << "B";
                break;
            case week04::RED:
                out << "R";
                break;
            default:
                out << "x";
        }
        return out;
    }

    // board to string
    ostream& operator<<(ostream &out, const board &g) {
        const int size = g.matrix_.size();
        const string bsym = "(B)";
        const string rsym = "(R)";

        cout << endl << "\t\t";
        for (int i = 0; i < size; ++i) cout << bsym << '\t';
        cout << endl;

        for (int x = 0; x < size; ++x) {
            cout << '\t' << rsym << '\t';
            for (int y = 0; y < size; ++y) {
                cout << g.matrix_[x][y] << '\t';
            }
            cout << rsym;
            cout << endl;
        }

        cout << "\t\t";
        for (int i = 0; i < size; ++i) cout << bsym << '\t';
        cout << endl;

        return out;
    }
}; // namespace week04
