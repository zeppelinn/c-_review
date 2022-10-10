//
// Created by LiJun on 2022/9/28.
//

#include <assert.h>
#include <iostream>
using namespace std;

//  位逻辑运算
//  &   与
//  |   或
//  ^   异或，运算符两侧条件不相同为真，否则为假
//  ~   取反

int demo_2_test()
{
    bool a = false;
    bool b = true;

    cout << "using assert" << endl;
//  assert断言的使用
//  assert() 括号内部的条件返回值必须为真，否则就会出错
    assert(!(a || b) != (!a && !b));        //  Assertion failed: (!(a || b) != (!a && !b)), function main, file /Users/lijun/CLionProjects/imooc_demo/demo/demo_2.cpp, line 17.
    assert(!(a && b) == (!a || !b));
    return 0;
}