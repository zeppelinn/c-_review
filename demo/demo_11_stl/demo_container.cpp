//
// Created by LiJun on 2022/10/7.
//

/**
 * 容器（container）
 * 容器用于存放数据；STL的容器分为两大类
 *  1.序列式容器（Sequence Containers）:序列式容器中的所有元素都是可以排序的，STL提供了vector，list，deque等序列式容器；而stack，queue，priority_queue则是容器适配器
 *  2.关联式容器（Associative Containers）：每个数据元素都是由一个键（key）和值（value）组成，当元素被插入到容器中时，按其键以某种特定规则放入适当的位置；常见的STL关联容器如：set，multiset，map，multimap
 * */

#include <iostream>

#include <algorithm>        //  算法库，for_each用到

#include <vector>
#include <list>
#include <queue>
#include <stack>

#include <map>
using namespace std;

//  函数类/仿函数
struct Display
{
//    重载括号运算符，等效于一个函数
    void operator()(int i)
    {
        cout << i << " ";
    }
};

struct DisplayScore
{
//    重载括号运算符，等效于一个函数
    void operator()(const pair<string, double>& info)
    {
        cout << info.first << ":" << info.second << endl;
    }
};

int demo_container_test()
{
    int iArr[] = {1, 2, 3, 4, 5};
/// 序列式容器：
//    创建vector，构造器中传入一个内存区间，first和last两个内存地址
//    需要注意的是这里的iArr + 4并不是指给iArr这个地址值直接+4，而是指偏移n * 4个字节，因为这里的iArr是一个int型的指针，一个int型占4个byte，所以+1表是偏移到下一个元素的位置，即偏移4个字节，改成long的话就是偏移8个字节
    vector<int> iVector(iArr, iArr + 5);
    list<int> iList(iArr, iArr + 5);
    deque<int> iDeque(iArr, iArr + 5);

    queue<int> iQueue(iDeque);                          //  队列      先进先出
    stack<int> iStack(iDeque);                          //  栈       先进后出
    priority_queue<int> iPQueue(iArr, iArr + 5);     //  优先队列  按照优先级

//    一种遍历语法，for_each，接受三个参数，前两个参数为该连续地址的首尾，第三个参数接收一个函数，根据上方结构体Display中对()运算符的重载，可以写成Display()
    for_each(iVector.begin(), iVector.end(), Display());
    cout << endl;
    for_each(iList.begin(), iList.end(), Display());
    cout << endl;
    for_each(iDeque.begin(), iDeque.end(), Display());
    cout << endl;

//    遍历队列
    while(!iQueue.empty())
    {
        cout << iQueue.front() << endl;
        iQueue.pop();
    }
    cout << endl;

    while(!iStack.empty())
    {
        cout << iStack.top() << endl;
        iStack.pop();
    }
    cout << endl;

    while(!iPQueue.empty())
    {
        cout << iPQueue.top() << endl;
        iPQueue.pop();
    }
    cout << endl;

/// 关联式容器：
    map<string, double> studentScores;
    studentScores["stuA"] = 96.0;
    studentScores["stuB"] = 91.0;
    studentScores["stuC"] = 88.0;
    studentScores.insert(pair<string, double>("stuD", 100.0));              //  创建字典插入map
    studentScores.insert(pair<string, double>("stuE", 1.0));
    studentScores.insert(map<string, double>::value_type("stuF", 81.5));   //  value_type 泛型方式插入
//    遍历
    for_each(studentScores.begin(), studentScores.end(), DisplayScore());
    cout << endl;

//    查询
    auto iter = studentScores.find("stuB");
    if (iter != studentScores.end())
    {
        cout << "found " << iter->first << ":" << iter->second << endl;
        cout << "found " << (*iter).first << ":" << iter->second << endl;
    } else {
        cout << "did not find stuB" << endl;
    }

//    修改
    studentScores["stuF"] = 21.9;
    auto iter2 = studentScores.find("stuF");
    if (iter2 != studentScores.end()) {
        cout << "found " << iter2->first << ":" << iter2->second << endl;
    }

//    使用迭代器遍历
    auto iter3 = studentScores.begin();
    while(iter3 != studentScores.end()) {
        if (iter3->second < 90.0) {
//            浮点数的判断，尤其是 == ，不能直接用==判断，而是要将两个浮点数相减，取绝对值，并判断是否小于某一个范围的值
            studentScores.erase(iter3++);       //  先取到遍历的值，然后把迭代器自加，最后抹除掉取到的值；如果不先让迭代器自加就抹除掉，迭代器就会失效，就不能再往下遍历了
        } else {
            iter3++;
        }
    }
    for_each(studentScores.begin(), studentScores.end(), DisplayScore());

    cout << "-------------" << endl;

    for(iter3 = studentScores.begin(); iter3 != studentScores.end(); ) {
        if (iter3->second > 99.0) {
            cout << "erase = " << iter3->second << endl;
            iter3 = studentScores.erase(iter3);     //  调用erase之后会返回下一个迭代器的位置，这样也不会引起迭代器失效的问题
        } else {
            iter3++;
        }
    }
    for_each(studentScores.begin(), studentScores.end(), DisplayScore());
    cout << endl;

//    找到并删除
//    iter3 = studentScores.find("stuA");
//    studentScores.erase(iter3);
//    等效于上方
    int index = studentScores.erase("stuA");
    cout << "erase = " << index << endl;
    for_each(studentScores.begin(), studentScores.end(), DisplayScore());
    cout << endl;

//    一次性清除
    studentScores.erase(studentScores.begin(), studentScores.end());

//    cout << (iArr) << endl;                 //  0x7ffee7aa6970
//    cout << &(iArr) << endl;                 //  0x7ffee7aa6970
//    cout << (iArr + 1) << endl;             //  0x7ffee7aa6974
//    cout << (iArr + 2) << endl;             //  0x7ffee7aa6978
//    cout << (iArr + 3) << endl;             //  0x7ffee7aa697c
//    cout << (iArr + 4) << endl;             //  0x7ffee7aa6980
}