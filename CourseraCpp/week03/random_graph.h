//
// Created by Valeriy Chevtaev on 11/4/13.
// Copyright (c) 2013 7bit. All rights reserved.
//


#import <fstream>
#include "graph.h"

#ifndef __random_graph_H_
#define __random_graph_H_

namespace week03 {

// TODO It's better to use unique_ptr or similar instead of manual memory allocation/deletion
class random_graph : public graph {
private:
    // init vertices matrix
    inline void init_vertices() {
        vertices_ = new int*[size_];
        for (int i = 0; i < size_; ++i) {
            vertices_[i] = new int[size_];
            fill_n(vertices_[i], size_, 0);
        }
    }

protected:
    // vertices matrix with distances to every other vertex.
    // edge with zero distance means it's not an edge at all.
    // TODO make it immutable
    int ** vertices_;

    int size_;
    const int min_distance_;
    const int max_distance_;
    const int density_;
    int actual_density_;

public:
    // Generate a graph from a file
    random_graph(const char * file_path) : density_(100), min_distance_(0), max_distance_(100000000) {
        ifstream datafile(file_path);
        if (!datafile.is_open()) {
            throw string("Cannot read from file ");
        }

        // Initialize vertices matrix
        datafile >> size_;
        if (size_ <= 0) {
            throw string("Graph must be at least of size 1");
        }
        init_vertices();

        // Fill-in vertices matrix
        int src_vertex, dst_vertex, distance;
        while (datafile >> src_vertex >> dst_vertex >> distance) {
            vertices_[src_vertex][dst_vertex] = distance;
        }

        datafile.close();
    }

    // Generate a graph using random values
    random_graph(const int size, const int density, int min_distance = DEFAULT_MIN_DISTANCE_, int max_distance = DEFAULT_MAX_DISTANCE)
            : size_(size), density_(density), min_distance_(min_distance), max_distance_(max_distance)
    {
        init_vertices();

        const int max_number_of_edges = size*(size-1)/2;
        const int edges_limit = 1+max_number_of_edges*density/100;
        int edges_count = 0;
        int tmp;

        srand(time(NULL));
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < size; ++k) {
                if (i != k && edges_count < edges_limit && (rand() % 100 < density)
                        && vertices_[i][k] == 0 && vertices_[k][i] == 0)
                {
                    ++edges_count;
                    tmp = rand() % 10 + 1;
                    vertices_[i][k] = tmp;
                    vertices_[k][i] = tmp;
                }
            }
        }

        actual_density_ = edges_count*100 / max_number_of_edges;
    }

    virtual ~random_graph() {
        for (int i = 0; i < size(); ++i) {
            delete [] vertices_[i];
        }
        delete [] vertices_;
    }

    virtual unique_ptr<mst> build_mst();
    virtual int size() const;
    virtual int shortest(int src_vertex_idx, int dst_vertex_idx);
    virtual float avg(int src_vertex_idx);
    virtual int density() const;
    virtual int actual_density() const;
    virtual int **vertices_matrix() const;
};

};

#endif //__random_graph_H_
