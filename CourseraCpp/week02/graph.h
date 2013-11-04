//
// Created by Valeriy Chevtaev on 11/4/13.
// Copyright (c) 2013 7bit. All rights reserved.
//


#ifndef __graph_H_
#define __graph_H_

#import <iostream>

using namespace std;

namespace week02 {

class graph {
protected:
    static const int DEFAULT_MIN_DISTANCE_ = 1;
    static const int DEFAULT_MAX_DISTANCE = 10;

public:
    static const int INFINITY = 99999;

    virtual ~graph(){}

    // Get size of the graph
    virtual int size() const = 0;

    // Get desired density of the graph
    virtual int density() const = 0;

    // Get actual density of the graph
    virtual int actual_density() const = 0;

    // Get vertices_ matrix of the graph
    virtual int **vertices_matrix() const = 0;

    // Evaluate shortest distance from one specified vertex to another specified vertex
    virtual int shortest(int srcVertexIdx, int dstVertexIdx) = 0;

    // Evaluate average shortest distance from specified vertex to all other vertices_
    virtual float avg(int srcVertexIdx) = 0;

}; // class graph

}; // namespace week02

// Pretty string representation of the graph
ostream& operator<<(ostream &out, const week02::graph &g);

#endif //__graph_H_
