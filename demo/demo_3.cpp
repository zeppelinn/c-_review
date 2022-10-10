//
// Created by LiJun on 2022/9/28.
//
/**
 * 杂项运算符
 * sizeof                   返回变量的大小，例如sizeof(a)返回4，说明a是整型
 * Condition ? X : Y        条件运算符
 * ,                        逗号运算符，会顺序执行一系列运算，这个逗号表达式的值时以逗号分割的列表中的最后一个表达式的值
 * .和 ->                   成员运算符，用于引用类、结构和共用体的成员
 * cast                     强制转换，将一种数据类型转换成另一种数据类型，例如int(2.2000)将返回2
 * &                        取地址符，返回变量在内存中的地址，例如 &a ，将获得变量a的内存地址
 * *                        指针运算符，指向一个变量，例如 *var，将指向变量var
 * */
#include <iostream>
using namespace std;

int demo_3_test()
{

    int a = 10;
    int b = 20;
    int c = 5;

//    sizeof
    cout << sizeof(a) << endl;

//    逗号运算符
    int e = (a, b, c);
    cout << e << endl;

//    强转（不提倡）
    float f = float(e);
    cout << f << endl;

//    指针
    cout << &f << endl;
    float *p = &f;              //  取变量f的地址，赋值给指针 p，
    cout << p << endl;          //  p即变量f的地址，
    cout << *p << endl;

    typedef struct {
        short sunday;
        short monday;
        short tuesday;
        short wednesday;
        short thursday;
        short friday;
        short saturday;
    } Week;

    Week w;
    w.friday = 5;
    cout << w.friday << endl;
    cout << sizeof(Week) << endl;

    return 0;
}