//
// Created by LiJun on 2022/9/29.
//

/**
 * 字符串变量
 *  1.字符串是以空字符（'\0'）结束的字符数组
 *  2.空字符'\0'会自动添加到字符串的内部表示中
 *  3.在声明字符变量时，应当为这个空结束符预留一个额外的元素，如：
 *      char strHelloWorld[11] = {"helloworld"};
 *
 * 字符串常量
 *  1.字符串常量是一对双括号括起来的字符序列
 *  2.字符串中每个字符作为一个数组元素存储
 *  3.例如字符串 "helloworld"，其在内存中的保存方式其实是 h e l l o w o r l d \0
 * */

#include <iostream>
#include <string>
using namespace std;

int demo_5_test() {
    char strHelloWorld[11] = {"helloworld"};
    char strHelloWorld1[] = {"helloworld"};

    char c1 = 0;            //  0x00
    char c2 = '\0';         //  0x00
    char c3 = '0';          //  0x30


//    字符串的指针表示
    char* pStrHelloWorld = "helloworld";    //  定义一个指针变量，指向字符串 "helloworld"的地址

//    char[] 和 char* 的区别:
//  1.strHelloWorld不可变，strHelloWorld[index]的值可变
//  2.pStrHelloWorld可变，但是pStrHelloWorld[index]的值是否可变取决于所指向的区域的存储区域是否可变

    for (int i = 0; i < 10; ++i) {
        strHelloWorld[i] += 1;
        cout << strHelloWorld[i] << endl;       // 可以改变
    }

//    for (int i = 0; i < 10; ++i) {
//        pStrHelloWorld[i] += 1;             //  Exception: EXC_BAD_ACCESS，不可更改；指针指向的区域是一块不可写的区域（常量区）
//        cout << pStrHelloWorld[i] << endl;
//    }

    char* pStrHelloWorld1 = strHelloWorld1;
    for (int i = 0; i < 10; ++i) {
        pStrHelloWorld1[i] += 1;
        cout << pStrHelloWorld1[i] << endl;
    }

/// 字符串基本操作
//  字符串长度 strlen(s)，注意strlen计算的结果不包含'\0'
    cout << strlen(strHelloWorld1) << endl;     //  10

//  字符串比较，strcmp(s1, s2)，
//  如果s1 和 s2 相同，则返回0；
//  如果s1 < s2，返回值小于0；
//  如果s1 > s2，返回值大于0
//  s1、s2两个字符串自左向右逐个字符比较（按ASCII码值比较大小），直到出现不同的字符或者遇到'\0'为止；
//  如 "A" < "B"；"A" < "AB"；"Apple" < "Banana"；"A" < "a"； "compare" < "computer";

    cout << (strcmp("Apple", "AppleB")) << endl;

//  字符串拷贝 strcpy(s1, s2)，非安全操作，如果拼接的字符过长可能会导致缓冲区溢出，将下一内存的内容冲掉；可以使用高安全性的函数strcpy_s替代strcpy，下方类似
//  赋值字符串s2 到字符串s1

//  复制指定长度的字符串：strncpy(s1, s2, n)
//  将字符串s2中的前n个字符拷贝gets1的前n个字符
    char s1[] = {"hello"};
    char s2[] = {"world"};
    strncpy(s1, s2, 2);
    cout << s1 << endl;         //  wollo

//  字符串拼接：strcat(s1, s2) _CRT_SECURE_NO_WARNING
//  将字符串s2拼接到s1后面
    strcat(s1, s2);
    cout << s1 << endl;     //  wolloworld

//  查找字符：strchr(s1, ch)
//  指向字符串s1 中字符ch的第一次出现的位置

//  查找字符串：strstr(s1, s2)
//  指向字符串s1 中字符串s2的第一次出现的位置


/// Redis字符串的设计，参考 https://redis.io/
//  sdshdr结构 free（未被使用的空间） + len（字符串长度） + buf（字符串内容）


/// string 的使用，方便安全的管理字符串
/// string结合了C++的新特性，使用起来比原始的C风格更安全方便，对性能要求不是特别高的常见应用可以使用。
//  定义字符串变量
    string str;
    string str1 = "helloworld";
    string str2 = ("helloworld");
    string str3 = string("helloworld");

//  获取字符串的长度 str.length()
    cout << str1.length() << endl;      //  10
    cout << str1.size() << endl;        //  10
    cout << str1.capacity() << endl;    //  22

//  字符串比较  == != > >= < <=
    cout << (str1 == str2) << endl;     //  1，相等

//  转换c风格的字符串
    const char *c_str1 = str1.c_str();
    cout << "The C-style string c_str1 is: " << c_str1 << endl;

//  随机访问（获取字符串中某个字符）：[]
    cout << str1[0] << endl;            //  h

//  字符串拷贝
    string str_cpy = str1;

//  字符串连接   +、+=
    string str_cat1 = str1 + str2;

    return 0;
}