//
// Created by Valeriy Chevtaev on 11/11/13.
// Copyright (c) 2013 7bit. All rights reserved.
//

#ifndef __mst_H_
#define __mst_H_

#import <iostream>
#import <vector>

using namespace std;

namespace week03 {

// Tree edge holder (immutable)
struct edge {
    int src_vertex;
    int dst_vertex;
    int distance;

    edge(const edge & e)
    : src_vertex(e.src_vertex), dst_vertex(e.dst_vertex), distance(e.distance)
    {}

    edge(int src_vertex, int dst_vertex, int distance)
    : src_vertex(src_vertex), dst_vertex(dst_vertex), distance(distance)
    {}
}; // class edge

bool edge_cmp_function(const edge &e1, const edge &e2);


// MST class
class mst {
private:
    int cost_;

    int findset(int x, int * parent) {
        if (x != parent[x]) {
            parent[x] = findset(parent[x], parent);
        }
        return parent[x];
    }

protected:
    vector<edge> edges_;

public:
    mst(int ** vertices_matrix, int size) : edges_(vector<edge>()) {
        // Create MST
        vector<edge> graph;
        for (int i = 0; i < size; ++i) {
            for (int k = i; k < size; ++k) {
                if (vertices_matrix[i][k] > 0) {
                    graph.push_back(edge(i, k, vertices_matrix[i][k]));
                }
            }
        }
        sort(graph.begin(), graph.end(), &edge_cmp_function); // increasing weight

        int parent[size];
        for (int i = 0; i < size; ++i) parent[i] = i;

        int pu, pv;
        for (vector<edge>::iterator it = graph.begin(); it != graph.end(); ++it) {
            pu = findset(it->src_vertex, parent);
            pv = findset(it->dst_vertex, parent);
            if (pu != pv) {
                edges_.push_back(*it); // add to tree
                parent[pu] = parent[pv]; // link
            }
        }

        // Calculate the cost
        cost_ = 0;
        for (vector<edge>::iterator it = edges_.begin(); it != edges_.end(); ++it) {
            cost_ += it->distance;
        }
    }

    inline int cost() const {
        return cost_;
    }

    const vector<edge> & get_edges() const {
        return edges_;
    }

}; // class mst
}; // namespace week03

// Pretty string representation of the MST
ostream& operator<<(ostream &out, const week03::mst &g);

#endif //__mst_H_
