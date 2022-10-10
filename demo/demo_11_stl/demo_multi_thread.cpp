//
// Created by LiJun on 2022/10/9.
//

#include <thread>
#include <iostream>

#include <mutex>

using namespace std;

/**
 * 加锁的原则：尽可能将锁的粒度最小化
 * */
mutex g_mutex;          //  定义全局的排它锁

void T1(){
    g_mutex.lock();     //  执行时上锁，其他共享这个锁的线程将等待
    cout << "Hello" << endl;
    g_mutex.unlock();   //  执行结束释放锁，其他等待的线程可以继续执行
}

void T2(const char* str) {
    g_mutex.lock();
    cout << "T2 " << str << endl;
    g_mutex.unlock();
}

int demo_multi_thread_test()
{
    thread t1(T1);   //  主线程（main）创建子线程对象
    thread t2(T2, "Hello, World");

    t1.join();          //  主线程等待，执行子线程t1，待t1执行结束之后恢复执行
    t2.join();

    cout << "main Hi" << endl;
    return 0;
}