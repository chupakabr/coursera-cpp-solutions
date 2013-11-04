//
// Created by Valeriy Chevtaev on 10/18/13.
// Copyright (c) 2013 7bit. All rights reserved.
//
// Week 01 Task 1 Solution
//
// Convert this program to C++
// change to C++ io
// change to one line comments
// change defines of constants to const
// change array to vector<>
// inline any short function
//
// code:
//    #include <stdio.h>
//    #define N 40
//    void sum(int*p, int n, int d[])
//    {
//        int i;
//        *p = 0;
//        for(i = 0; i < n; ++i)
//            *p = *p + d[i];
//    }
//    int main()
//    {
//        int i;
//        int accum = 0;
//        int data[N];
//        for(i = 0; i < N; ++i)
//
//            data[i] = i;
//
//        sum(&accum, N, data);
//        printf("sum is %d\n", accum);
//        return 0;
//    }

#include <vector>

#ifndef __week01_task1_H_
#define __week01_task1_H_

class week01_task1 {
private:
    static const int DEFAULT_ARRAY_SIZE = 40;

public:
    void run();

protected:
    template<typename T>
    inline void sum(T& accum, std::vector<T>& data) {
        accum = 0;
        for (typename std::vector<T>::const_iterator it = data.begin(); it != data.end(); ++it) {
            accum += *it;
        }
    }
};


#endif //__week01_task1_H_
