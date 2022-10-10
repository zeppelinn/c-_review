//
// Created by LiJun on 2022/10/6.
//

/**
 * C++使用 struct 或 class 来定义一个类
 * struct 的默认成员权限是public
 * class 的默认成员权限是private
 * 除此之外两者基本没有差别
 * */

#include "Complex.h"

int demo_10_test()
{
    Complex c(1.0, 2.0);

    cout << c.getReal() << endl;
    cout << c.getImage() << endl;

    Complex paramAdd(2.0, 3.0);

//    Complex result;
//    result = c + paramAdd;
//      优化的方式，相较于上方的写法，此处直接省略了一次Complex对象的构造
    Complex result = c + paramAdd;

    cout << result.getReal() << endl;
    cout << result.getImage() << endl;

    cout << result << endl;         //  重载标准输出

    cin >> result;                  //  重载标准输入（输入的参数通过空格或者回车隔开）
    cout << result << endl;

    return 0;
}