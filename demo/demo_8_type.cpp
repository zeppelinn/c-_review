//
// Created by LiJun on 2022/10/3.
//

//#pragma pack(1)       //  次数pack里面的参数指的是内存单元的大小，当此处为1时，下方的结构体s1的大小就从12变成了7

#include <iostream>
using namespace std;

int demo_8_type_test() {
///    union 与 struct
//  在union中，所有的成员共同使用同一份空间
    union Score {
        double ds;
        char level;
    };

    struct Student {
        char name[6];
        int age;
        Score s;
    };

    cout << "sizeof(Score) = " << sizeof(Score) << endl;            //  sizeof(Score) = 8
    cout << "sizeof(Student) = " << sizeof(Student) << endl;        //  sizeof(Student) = 24

/// 结构体数据对齐
//   内存在给结构体分配空间的时候，空间的大小是结构体中占空间最大的成员的整数倍

    struct s1
    {
        char x;         //  4 byte
        int z;          //  4 byte
        short y;        //  4 byte
    };

    struct s2
    {
        char x;         //  1 byte
        short y;        //  2 byte
        int z;          //  4 byte
    };

    cout << "sizeof(s1) = " << sizeof(s1) << endl;      //  sizeof(s1) = 12
    cout << "sizeof(s2) = " << sizeof(s2) << endl;      //  sizeof(s2) = 8

    return 0;
}
