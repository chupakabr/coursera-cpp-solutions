//
// Created by Valeriy Chevtaev on 11/4/13.
// Copyright (c) 2013 7bit. All rights reserved.
//


#include <iostream>
#include <vector>
#include "task1.h"
#include "random_graph.h"

using namespace std;

void week03::task1::run(int argc, const char** argv) {
    if (argc < 1) {
        cerr << "Path to a file having test data should be specified as an argument to the command..." << endl;
        return;
    }

    cout << "Running Week 03 Task 1 with file " << argv[1] << "..." << endl;

    const bool useTestDataFile = true;
    if (!useTestDataFile) {
        // Generate test list of pairs: number of vertices_ -> graph density in percent
        vector<pair<int, int>> test_data;
        test_data.push_back(pair<int, int>(2, 100));
        test_data.push_back(pair<int, int>(3, 100));
        test_data.push_back(pair<int, int>(5, 100));
        test_data.push_back(pair<int, int>(8, 100));

        // Iterate through all test situations and simulate
        for (pair<int, int> graph_data : test_data) {
            random_graph g(graph_data.first, graph_data.second);
            cout << endl << "--------------------------------" << endl << g << endl;
            cout << " * MST: " << *g.build_mst().get() << endl;
        }
    } else {
        // Load data from specified file
        random_graph g(argv[1]);
        cout << endl << "--------------------------------" << endl << g << endl;
        cout << " * MST: " << *g.build_mst().get() << endl;
    }

    cout << endl << "Week 03 Task 1 has been finished." << endl;
}
