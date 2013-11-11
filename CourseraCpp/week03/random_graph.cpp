//
// Created by Valeriy Chevtaev on 11/4/13.
// Copyright (c) 2013 7bit. All rights reserved.
//


#include "random_graph.h"

unique_ptr<week03::mst> week03::random_graph::build_mst() {
    unique_ptr<week03::mst> tree_ptr(new week03::mst(vertices_, size_));
    return tree_ptr;
}

int week03::random_graph::size() const {
    return size_;
}

int week03::random_graph::density() const {
    return density_;
}

int week03::random_graph::actual_density() const {
    return actual_density_;
}

int **week03::random_graph::vertices_matrix() const {
    return vertices_;
}

int week03::random_graph::shortest(int src_vertex_idx, int dst_vertex_idx) {
    int distances[size()];
    bool marks[size()];
    int min_distance;
    int closest_unmarked_vtx;
    int i = 0;

    fill_n(marks, size(), false);
    fill_n(distances, size(), INFINITY);
    distances[src_vertex_idx] = 0;

    while (i < size()) {
        min_distance = INFINITY;
        closest_unmarked_vtx = 0;
        for (int k = 0; k < size(); ++k) {
            if (!marks[k] && min_distance > distances[k]) {
                min_distance = distances[k];
                closest_unmarked_vtx = k;
            }
        }

        marks[closest_unmarked_vtx] = true;

        for (int k = 0; k < size(); ++k) {
            if (!marks[k] && vertices_[closest_unmarked_vtx][k] > 0) {
                if (distances[k] > (distances[closest_unmarked_vtx] + vertices_[closest_unmarked_vtx][k])) {
                    distances[k] = distances[closest_unmarked_vtx] + vertices_[closest_unmarked_vtx][k];
                }
            }
        }
        ++i;
    }

    return distances[dst_vertex_idx];
}

float week03::random_graph::avg(int src_vertex_idx) {
    int total_distance = 0;
    int meaningful_evaluations = 0;
    int shortest_distance;

    for (int i = 0; i < size(); ++i) {
        if (i == src_vertex_idx) {
            continue;
        }

        shortest_distance = shortest(src_vertex_idx, i);
        if (shortest_distance > 0 && shortest_distance != INFINITY) {
            ++meaningful_evaluations;
            total_distance += shortest_distance;
        }
    }

    if (meaningful_evaluations > 0) {
        return total_distance /meaningful_evaluations;
    } else {
        return 0;
    }
}

