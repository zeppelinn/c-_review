//
// Created by LiJun on 2022/10/8.
//

/**
 * 仿函数
 *  仿函数一般不单独使用，主要是为了搭配STL算法使用
 *  函数指针不能满足STL对抽象性的要求，不能满足软件积木的要求，无法和STL其他组件搭配
 *  本质上就是一个类，其重载了一个operator()，创建一个行为类似于函数的对象
 * */

#include <iostream>
#include <algorithm>
using namespace std;

//  泛型
template<class T>
inline bool MySortT(T const &a, T const &b) {
    return a < b;
}

template<class T>
inline void DisplayT(T const &i)
{
    cout << i << " ";
}

//  ----------------------------------
inline bool MySort(int a, int b) {
    return a > b;
}

inline void Display(int i)
{
    cout << i << " ";
}

//  ----------------------------------
//仿函数
struct SortF
{
    inline bool operator()(int a, int b)
    {
        return a > b;
    }
};

struct DisplayF
{
    inline void operator()(int i)
    {
        cout << i << " ";
    }
};

//  ----------------------------------
//C++仿函数模板
template<class T>
struct SortFT
{
    inline bool operator()(T const &a, T const &b)
    {
        return a < b;
    }
};

template<class T>
struct DisplayFT
{
    inline void operator()(T const& i)
    {
        cout << i << " ";
    }
};


int demo_functor_test()
{
    int arr[] = {4, 5, 3,9, 1};

//    原始写法，只能处理int型
    sort(arr, arr + 5, MySort);     //  MySort函数指针
    for_each(arr, arr + 5, Display);
    cout << endl;

//    泛型方法，可以处理任何类型
    sort(arr, arr + 5, MySortT<int>);
    for_each(arr, arr + 5, DisplayT<int>);
    cout << endl;

//    仿函数
    sort(arr, arr + 5, SortF());
    for_each(arr, arr + 5, DisplayF());
    cout << endl;

//    泛型模板仿函数
    sort(arr, arr + 5, SortFT<int>());
    for_each(arr, arr + 5, DisplayFT<int>());
    cout << endl;

    return 0;
}