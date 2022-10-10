//
// Created by LiJun on 2022/9/29.
//

/**
 * C++中内存单元内容与地址
 *  1.内存由很多内存单元组成，这些内存单元用于存放各种类型的数据
 *  2.计算机对内存的每个内存单元都进行了编号，即内存地址，地址决定了内存单元在内存中的位置
 *
 * 指针的定义和间接访问操作
 *  1.指针定义的基本形式：指针本身就是一个变量，其符合变量定义的基本形式，他存储的是值的地址。
 *      对类型T，T* 是 "到T的指针"类型，一个类型为T*的变量能保存一个类型T对象的地址
 *      一般情况下指针都是一个4字节的整型数
 *  2.通过一个指针访
 *  问它所指向地址的过程称为间接访问（indirection）或者引用指针（dereferencing the point），这个用于执行间接访问的操作符是单目操作符 *
 *
 * 左值与右值
 *  左值：左值可以放在赋值运算符的左边，编译器为其单独分配了一块存储空间，可以取其地址
 *      最常见的情况如函数和数据成员的名称
 *  右值：右值指数据本身，不能取到其自身地址，右值只能在赋值运算右边
 *      右值是没有标识符、不可取地址的表达式，一般也称之为"临时对象"；
 *      如：a = b + c;
 *          &a是允许的操作，而&(b + c)不能编译通过
 *          因此a是一个左值，而(b + c)是一个右值
 * */

#include <iostream>
#include <string.h>
using namespace std;

int demo_6_test()
{
//    举例：
    int a = 112, b = -1;
    float c = 3.14;
    int* d = &a;
    float* e = &c;

// 关于变量、地址和指针变量的小结
//  1.一个变量有三个重要信息：
//    A.变量的地址位置
//    B.变量所存的信息
//    C.变量的类型
//  2.指针变量是 一个专门用来记录变量的地址的变量；通过指针变量可以间接访问另一个变量的值


/// 一般类型指针T*，T是一种类型，泛指任何一种类型
    int i = 4;
    int* iP = &i;               // int*，此处的*指： 定义了一个指针类型的变量，这个指针指向的数据的类型是int
    cout << (*iP) << endl;      // (*iP)，此处的*指：间接引用，取iP这个变量的所指向地址的值

    double n = 3.14;
    double* nP = &n;
    cout << (*nP) << endl;

    char m = 'a';
    char* mP = &m;
    cout << (*mP) << endl;


    int array[4] = {1, 2, 3, 4};
/// 指针的数组(array of pointers)与数组的指针(a pointer to an array):
//    指针的数组 T* t[]，即一个数组，数组中的所有元素都是int型的指针
    int* pointerArr[4];
    for (int i = 0; i < 4; ++i) {
        pointerArr[i] = &array[i];
    }

//    数组的指针 T(*t) []，一个指向数组的指针，pointOfArray：指指向一个数组的指针
    int(*pointOfArray)[4];  //  []优先级比较高
    pointOfArray = &array;  //  将数组array的地址赋值给pointOfArray

    cout << array[3] << endl;            //  4
    cout << *pointerArr[3] << endl;      //  4
    cout << (*pointOfArray)[3] << endl;  //  4


/// const pointer 与 pointer to const
//  当一个变量被const修饰，那这个变量在运行期间是不允许被改变的
//  关于const修饰的部分：
//   1.看左侧最近的部分；
//   2.如果左侧没有，则看右侧
    char strHello[] = {"helloworld"};
    const char *pStr1 = "helloworld";               //  const修饰char，说明pStr1可变，但是指针pStr1指向的内存空间不可改变
    char* const pStr2 = strHello;                   //  const修饰 *，
    char const * const pStr3 = "helloworld";        //  const既修饰 char又修饰 *，说明指针pStr3的指向不能改变，其指向的"helloworld"这块内存也不能改变
    const char * const pStr4 = "helloworld";
    pStr1 = strHello;
//    pStr2 = strHello;             //  报错，pStr2不可变
//    pStr3 = strHello;             //  报错，pStr3不可变

    unsigned int len = strlen(pStr2);

    for (int i = 0; i < len; ++i) {
//        pStr1[i] += 1;        //  报错，pStr1指向的内存区域不可变
        pStr2[i] += 1;          //  指针pStr2本身不可变，但其指向的内存区域可变
//        pStr3[i] += 1;        //  报错，pStr3指向的内存区域不可变
    }
    cout << "pStr1 = " << pStr1 << endl;    //  pStr1 = ifmmpxpsme
    cout << "pStr2 = " << pStr2 << endl;    //  pStr2 = ifmmpxpsme

    cout << typeid(strHello).name() << endl;    //  A11_c
    cout << typeid(pStr1).name() << endl;       //  PKc
    cout << typeid(pStr2).name() << endl;       //  Pc
    cout << typeid(pStr3).name() << endl;       //  PKc
    cout << typeid(pStr4).name() << endl;       //  PKc

/// 指向指针的指针
//  *操作符居又从右向左的结合性
//  **这个表达式相当于*(*pC)，必须从里向外层逐层求值
//  *pC得到的是c指向的位置，即b
//  **pC相当于*pB，得到变量a的值
    int pA = 123;
    int* pB = &pA;
    int** pC = &pB;

    int multiArray[3][4];

    cout << "*******" << endl;
//    cout << &multiArray << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << multiArray[i][j] << endl;
        }
    }
    cout << "*******" << endl;


/// 未初始化和非法的指针
    int *faultA;        //  此处已经在栈中已经为faultA分配了内存区域，系统会为其随机定义指向内存中的一块地址
    *faultA = 12;       //  如果此时给faultA指向的地址赋值，可能会造成其他内存被非法修改的问题

/// NULL指针
//  一种特殊的指针，表示不指向任何东西
//  给一个指针变量赋值为NULL，可以表示这个指针变量目前没有指向任何东西
//  对于一个指针变量，在初始化是如果不明确其指向的地址，则将其设置为NULL
//  在对一个指针进行间接引用之前，也需要先判断这个指针的值是否为NULL
    int pV = 100;
    int *aPNull = nullptr;
    aPNull = &pV;
    if (aPNull != nullptr) {
        cout << *aPNull << endl;
    }
    aPNull = nullptr;

/// 杜绝【野指针】
//  野指针，指向垃圾内存的指针，不为NULL
//  野指针出现的三种情况
//   1.指针变量没有初始化；
//   2.已经释放不用的指针没有置NULL，如delete和free（释放堆中的内存）之后的指针；
//   3.指针操作超越了变量的作用范围
//  因此：在指针没有初始化、不再使用或者超出范围的时候，请将指针赋值为NULL


/// & 与 * 操作符
    char ch = 'a';
    char* cP = &ch;

/// 左值与右值
//   &操作符
//    &ch = 97;         //  &ch左值 不合法
    char *cp = &ch;     //  &ch右值
//    &cp = 97;         //  &cp左值 不合法
    char** cpp = &cp;   //  &cp右值

//   *操作符
    *cp = 'a';          //  *cp左值取变量ch的位置
    char ch2 = *cp;     //  *cp右值取变量ch存储的值
//    *cp + 1 = 'a';    //  *cp + 1左值不合法
    ch2 = *cp + 1;      //  *cp + 1右值取到的字符做ASCII码 +1 的操作
    *(cp + 1) = 'a';    //  *(cp + 1)左值语法上合法，取ch后面的位置
    ch2 = *(cp + 1);    //  *(cp + 1)右值语法上合法，取ch后面位置的值

    return 0;
}