//
// Created by LiJun on 2022/9/28.
//

#include <iostream>
using namespace std;        //  命名空间，将iostream中的std库释放到本地，使书写是不引起变量或函数名的命名冲突

int demo_1_test()
{
    int a = 10;
    int b = 20;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << 15 / a << endl;
    cout << 15.0 / a << endl;
    cout << b % a << endl;

    cout << ++a << endl;
    cout << a++ << endl;
    cout << a << endl;
    return 0;
}
