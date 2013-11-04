//
// Created by Valeriy Chevtaev on 11/4/13.
// Copyright (c) 2013 7bit. All rights reserved.
//


#include "graph.h"

// just definition
const int week02::graph::INFINITY;

ostream& operator<<(ostream &out, const week02::graph &g) {
    int ** matrix = g.vertices_matrix();

    cout << "Graph(size=" << g.size() << ", density=" << g.density() << "%, actual density=" << g.actual_density()
        << "%, matrix=[" << endl;

    for (int i = 0; i < g.size(); ++i) {
        cout << " " << i << ":\t";
        for (int k = 0; k < g.size(); ++k) {
            cout << k << "=" << matrix[i][k] << ", ";
        }
        cout << endl;
    }

    cout << "])";

    return out;
};

