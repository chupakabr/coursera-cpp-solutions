//
// Created by Valeriy Chevtaev on 11/4/13.
// Copyright (c) 2013 7bit. All rights reserved.
//


#include <iostream>
#include <vector>
#include "task1.h"
#include "random_graph.h"

using namespace std;

void week02::task1::run() {
    cout << "Running Week 02 Task 1..." << endl;

    // Generate test list of pairs: number of vertices_ -> graph density in percent
    vector<pair<int, int>> test_data;
    test_data.push_back(pair<int, int>(2, 20));
    test_data.push_back(pair<int, int>(2, 40));
    test_data.push_back(pair<int, int>(3, 20));
    test_data.push_back(pair<int, int>(3, 40));
    test_data.push_back(pair<int, int>(3, 70));
    test_data.push_back(pair<int, int>(5, 20));
    test_data.push_back(pair<int, int>(5, 40));
    test_data.push_back(pair<int, int>(5, 70));
    test_data.push_back(pair<int, int>(8, 20));
    test_data.push_back(pair<int, int>(8, 40));
    test_data.push_back(pair<int, int>(8, 70));
    test_data.push_back(pair<int, int>(50, 20));
    test_data.push_back(pair<int, int>(50, 40));

    // Iterate through all test situations and simulate
    for (pair<int, int> graph_data : test_data) {
        random_graph g(graph_data.first, graph_data.second);
        int tmp;
        cout << endl << "--------------------------------" << endl << g << endl;
        for (int i = 1; i < g.size(); ++i) {
            tmp = g.shortest(0, i);
            if (tmp != graph::INFINITY) {
                cout << " * shorted distance from first vertex to " << i << " vertex is " << g.shortest(0, i) << endl;
            }
        }
        cout << " * average distance from first vertex to all reachable vertices is " << g.avg(0) << endl;
    }

    cout << endl << "Week 02 Task 1 has been finished." << endl;
}
