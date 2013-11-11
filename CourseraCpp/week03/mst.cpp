//
// Created by Valeriy Chevtaev on 11/11/13.
// Copyright (c) 2013 7bit. All rights reserved.
//


#include <vector>
#include "mst.h"

bool week03::edge_cmp_function(const edge &e1, const edge &e2) {
    return e1.distance < e2.distance;
}

ostream& operator<<(ostream &out, const week03::mst &tree) {
    cout << "MST(cost=" << tree.cost() << ", tree=[" << endl;

    vector<week03::edge> edges = tree.get_edges();
    for (vector<week03::edge>::iterator it = edges.begin(); it != edges.end(); ++it) {
        cout << "edge(" << it->src_vertex << "->" << it->dst_vertex << "=" << it->distance << ")" << endl;
    }

    cout << "])";

    return out;
};

