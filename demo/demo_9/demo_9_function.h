//
// Created by LiJun on 2022/10/5.
//

#ifndef IMOOC_DEMO_DEMO_9_FUNCTION_H
#define IMOOC_DEMO_DEMO_9_FUNCTION_H

#endif //IMOOC_DEMO_DEMO_9_FUNCTION_H

#include <iostream>

using namespace std;

int test(int a);
int test(double a);
int test(int a = 1, double b = 2.0);

//  自定义命名空间
namespace hello_space
{
    int test(int a);
}