//
// Created by LiJun on 2022/10/9.
//

/**
 * stack 堆栈：
 *  一种【先进后出】的容器，底层数据结构是使用的deque；
 * queue 队列：
 *  一种【先进先出】的容器，底层数据结构是使用的deque；
 * priority_queue 优先队列：
 *  一种特殊队列，能够在队列中进行排序（堆排序），底层实现结构是vector或者deque；
 *
 * 队列：一端只能出或进
 * 栈：一端同时能出或进
 * */

#include <functional>
#include <queue>
#include <stack>

#include <iostream>

using namespace std;

int demo_adapter_test()
{
//    stack<int> s;
//    queue<int> q;

    priority_queue<int> pQueue;     //  默认是最大值优先
    priority_queue<int, vector<int>, less<> >pQueueLess;                //  默认是最大值优先
    priority_queue<int, vector<int>, greater<> >pQueueGreater;          //  默认是最小值优先

    pQueueGreater.push(2);
    pQueueGreater.push(1);
    pQueueGreater.push(3);
    pQueueGreater.push(0);

//    while(!pQueue.empty())      //  3210
//    while(!pQueueLess.empty())  //  3210
    while(!pQueueGreater.empty()) //  0123
    {
        int top = pQueueGreater.top();
        cout << top;
        pQueueGreater.pop();
    }
    cout << endl;

    return 0;
}