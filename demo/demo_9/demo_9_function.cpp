//
// Created by LiJun on 2022/10/5.
//

#include "demo_9_function.h"

int test(int a) {
    return a;
}

int test(double a) {
    return int(a);
}

int test(int a, double b) {
    return a + b;
}

namespace hello_space
{
    int test(int a)
    {
        return a + 1;
    }
}