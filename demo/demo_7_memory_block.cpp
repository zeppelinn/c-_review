//
// Created by LiJun on 2022/10/2.
//

/**
 * 栈和队列
 *
 *  栈：先进后出
 *  队列：先进先出
 *
 * 动态分配资源--堆
 *  一般情况下使用new关键字来在堆上分配内训，delete关键字则可以来释放分配的内存
 * */
//    每行代码在内存单元中的地址位置

int a = 0;                      //  (GVAR)全局初始化区
int* p1;                        //  (bss)全局未初始化区

int demo_7_test()                      //  (text)代码区
{
//    内存空间按照高地址到低地址的方式的方式分配
//    越早声明的变量地址越高

    int b;                      //  (stack)栈区变量
    char s[] = "abc";           //  (stack)栈区变量，此处的"abc"保存在栈区，意味着该块内存区域可以改动
    int* p2 = nullptr;          //  (stack)栈区变量
    char *p3 = "123456";        //  "123456\0"在常量区，不同于字符数组s，该块内存区域不可改动，p3在(stack)栈区
    static int c = 0;           //  (GVAR)全局(静态)初始化区

//    堆区内存的排布跟栈区的排布方式不同，声明的早的变量地址低
    p1 = new int(10);           //  (heap)堆区变量，地址：0x00007f851a600480
    p2 = new int(20);           //  (heap)堆区变量，地址：0x00007f851a405430
    return 0;                   //  (text)代码区
}