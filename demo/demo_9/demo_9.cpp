//
// Created by LiJun on 2022/10/5.
//

#include "demo_9_function.h"

inline int max_value(int a, int b)
{
    return (a < b) ? b : a;
}

int demo_9_test()
{
///    函数指针
//  在头文件里发现，int test(int a = 1, double b = 2.0);定义了两个默认参数，此时会与int test(int a);产生冲突
//  为了解决这个问题，引入函数指针，创建一个指针指向一个函数
//  函数指针的签名：返回值类型 (*指针名) (参数列表)
    int(*pFunc)(int);
    pFunc = test;
    int result = pFunc(1);

    result = test(2.0);
    result = test(1, 2.0);

///    指向函数的指针 和 返回指针的函数
//  每个函数都占用一段内存单元，它们有一个起始地址，指向函数入口地址的指针称为函数指针
//  一般形式：数据类型(*指针变量名)(参数表)
    int(*pFun)(int);    //  指针变量，返回的是一个函数的入口地址
    bool processNum(int i, int j, int(*p)(int a, int b));       //  此处的 int(*p)(int a, int b)就是一个回调函数

//  返回指针的函数
    int* pVal(int);     //  函数，返回的是一个指针
    char* str_cpy(char *dest, const char *src);

/// 命名空间
    result = hello_space::test(1);

/// 内联函数
//   引入内联函数的目的是为了解决程序中函数调用的效率问题，汇编代码可以发现每次在调用函数的时候，后需要提前为函数的调用开辟栈空间，所以使用内联函数可以直接将内联函数中的实现植入到调用的地方，省略了上述栈空间的开辟和回收
//   内联函数内部不能有太过复杂的操作，编译器有时会自己优化策略，所以内联函数也不是每次都有用
    result = max_value(1, 2);
    return 0;
}