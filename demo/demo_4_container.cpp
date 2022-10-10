//
// Created by LiJun on 2022/9/28.
//

/**
 * 数组：
 *  在内存中一组连续的同类型的存储区
 *  可以用来把多个存储区合并成一个整体
 *
 * 二维数组：
 *  包含行列两个维度的数组
 *
 * 动态数组vector：
 *  vector是面向对象方式的动态数组，支持动态扩容
 * */

#include <vector>
#include <iostream>
using namespace std;

int demo_4_test()
{
///    数组定义
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8};

//    数组元素的访问和修改
//    方式一：使用数组下标的形式访问
    arr[2] = 5;
//    方式二：使用指针的方式访问
    int * p = arr;
    *(p + 2) = 5;

///    二维数组的定义
//  两行四列的元素
    int a[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};

//    二维数组遍历的原则：
//  循环时要尽可能满足"空间局部性"：在一个小的时间窗口内，访问的变量地址越接近越好，这样执行速度更快
//  即需要将最长的循环放在最内层，最短的循环放在最外层，以减少cpu跨切循环层的次数


///    vector的使用
    vector<int> vec = {1, 2, 3, 4};
    cout << vec.capacity() << endl;
    vec.push_back(5);       //  在尾部进行元素插入的操作
//    vector的遍历
    for (int index = 0; index < vec.size(); ++index) {
        cout << vec[index] << endl;
    }
//    vector的capacity和size：
//    capacity：当前vector的容量，即能够存储的元素的个数
//    size：当前已经存储的元素的个数
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;

//    vector的删除操作
    vec.pop_back();                     //  删除尾部的元素
    vec.erase(vec.end() - 2);   //  根据下标（倒数第二个）删除某一个元素，vec.end()代表最后一个元素的位置

//    vector的插入操作
    vec.insert(vec.end(), 6);   //  在尾部添加一个元素6
    for (int index = 0; index < vec.size(); ++index) {
        cout << vec[index] << endl;
    }
    return 0;
}