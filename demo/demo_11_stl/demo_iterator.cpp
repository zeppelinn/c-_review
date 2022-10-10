//
// Created by LiJun on 2022/10/9.
//

/**
 * 迭代器（iterator）
 *  迭代器是一种smart pointer，用于访问顺序容器和关联容器中的元素，相当于容器和操纵容器的算法之间的中介
 *  迭代器按照定义方式分为以下四种：
 *      1.正向迭代器：iterator
 *      2.常量正向迭代器：const_iterator
 *      3.反向迭代器：reverse_iterator
 *      4.常量反向迭代器：const_reverse_iterator
 *
 *          容器                  迭代器
 *         vector               随机访问
 *         deque                随机访问
 *         list                 双向访问
 *         set/multiset         双向访问
 *         map/multimap         双向访问
 *         stack                不支持迭代器
 *         queue                不支持迭代器
 *         priority_queue       不支持迭代器
 * */

#include <iostream>
#include <list>

using namespace std;

int demo_iterator_test()
{
    list<int> v;
    v.push_back(3);         //  从list尾部添加元素
    v.push_back(4);
    v.push_front(2);        //  从list头部添加元素
    v.push_front(1);

    list<int>::const_iterator it;       //  list的迭代器
    for(it = v.begin(); it != v.end(); it++) {      //  用list迭代器遍历  1234
//        *it = *it + 1;    //  常量迭代器，遍历过程中不能修改
        cout << *it;        //  1234
    }
    cout << endl;

//    v.pop_back();       //  从尾部弹出   123
//    v.pop_front();      //  从头部弹出   23

    list<int>::reverse_iterator itR;
    for(itR = v.rbegin(); itR != v.rend(); itR++) {
        *itR = *itR + 1;    //  非常量迭代器，遍历过程中可以修改
        cout << *itR;       //  5432
    }
    cout << endl;

    return 0;
}

//  !!!自定义迭代器必须提供iterator_traits的五种特性，分别是迭代器类型、元素类型、距离类型、指针类型和reference类型
//  template<class Iterator>
//  struct iterator_traits
//  {
//      typedef typename Iterator::difference_type difference_type;
//      typedef typename Iterator::value_type value_type;
//      typedef typename Iterator::pointer pointer;
//      typedef typename Iterator::reference reference;
//      typedef typename Iterator::iterator_category iterator_category;
//  }