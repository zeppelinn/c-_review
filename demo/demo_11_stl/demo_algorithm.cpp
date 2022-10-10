//
// Created by LiJun on 2022/10/8.
//

/**
 * 算法
 *  STL中算法大致分为四类：包含于头文件<algorithm>, <numeric>, <functional>
 *  1.非可变序列算法：指不直接修改其所操作的容器内容的算法；
 *  2.可变序列算法：指可以修改其所操作的容器内容的算法；
 *  3.排序算法：包括对序列进行排序和合并的算法、搜索算法以及有序序列上的集合操作；
 *  4.数值算法：对容器内容进行数值计算
 *
 * 常见的算法包括：
 *  查找、排序和通用算法、排列组合算法、数值算法、集合算法等
 * */

#include <iostream>

#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
using namespace std;

//  交换元素
inline void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void Permutation(char* pStr, char* pPosition) {
    //  基准点
    if (*pPosition == '\0') {
        cout << pStr << endl;
    } else {
        for(char* pChar = pPosition; *pChar != '\0'; pChar++) {
            swap(*pChar, *pPosition);
            Permutation(pStr, pPosition + 1);
            swap(*pChar, *pPosition);
        }
    }
}

int demo_algorithm_test()
{
/// transform 和 lambda表达式
    int ones[] = {1, 2, 3, 4, 5};
    int tens[] = {10, 20, 30, 40, 50};
    int result[5];

    //  对两个集合（ones, tens）进行运算（std::plus<>()）并赋值给第三个集合（result）
    transform(ones, ones + 5, tens, result, std::plus<>());

    for_each(result, result + 5, [](int a) -> void {
        //  lambda表达式(匿名函数)
        cout << a << " ";
    });

    cout << endl;

/// 查找
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 6, 7, 7, 7, 8};
    cout << "count of 7 = " << count(arr, arr + (sizeof(arr) / sizeof(arr[0])), 7) << endl;                                              //  统计为7的值的个数
    cout << "count of numbers < 7 = " << count_if(arr, arr + (sizeof(arr) / sizeof(arr[0])), bind2nd(less<int>(), 7)) << endl;    //  统计小于7的值的个数，less<int>()是一个仿函数，用于比较两个数的大小，bind2nd将第二个参数作为右值传入到第一个函数参数运算
    cout << " 7 exist = " << binary_search(arr, arr + (sizeof(arr) / sizeof(arr[0])), 7) << endl;                                     //  二分查找，查询某个元素是否在

    vector<int> iVector(arr + 2, arr + 6);      //  生成一份子序列
    cout << *search(arr, arr + (sizeof(arr) / sizeof(arr[0])), iVector.begin(), iVector.end()) << endl;                         //  search在一串序列中搜索一个子序列，如果搜索到返回搜索到的地址
    cout << endl;

/// 全排列
    char testStr[] = "123";
//    手写全排列
    Permutation(testStr, testStr);
    cout << endl;

//    STL全排列(前提：必须保证数组元素是按照大小顺序排列的)
    do {
        cout << testStr[0] << testStr[1] << testStr[2] << endl;
    } while(next_permutation(testStr, testStr + 3));
    cout << endl;


    return 0;
}