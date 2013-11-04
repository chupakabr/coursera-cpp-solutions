//
// Created by Valeriy Chevtaev on 10/18/13.
// Copyright (c) 2013 7bit. All rights reserved.
//


#include "week01_task1.h"
#include <iostream>

void week01_task1::run() {
    std::cout << "Running Week 01 Task 1..." << std::endl;

    std::vector<int> data;
    for (int i = 0; i < DEFAULT_ARRAY_SIZE; ++i) {
        data.push_back(i);
    }

    int accum;
    sum(accum, data);

    std::cout << "Sum is " << accum << std::endl;
}
