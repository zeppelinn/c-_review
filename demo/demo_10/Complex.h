//
// Created by LiJun on 2022/10/6.
//

#ifndef IMOOC_DEMO_COMPLEX_H
#define IMOOC_DEMO_COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
public:
    Complex();                                       //  默认构造函数
    Complex(double real, double image);              //  构造函数
    virtual ~Complex();     //  析构函数l;
    Complex(const Complex& x);                      //  拷贝构造

    //  两种写法，2.在头文件中声明和实现函数
    double getReal() const {return _real;}             //  const 修饰的是函数，表示在函数体内部，成员变量的值不允许做任何的改变
    void setReal(double real) {_real = real;}

    double getImage() const;
    void setImage(double image);

    Complex operator+(const Complex& paramAdd) const;

    Complex& operator=(const Complex& paramAdd);

protected:
    /**
     * 重载标准输出
     * */
    friend ostream& operator<<(ostream& os, const Complex& x);
    friend istream& operator>>(istream& is, Complex& x);


private:
    double _real;           //  复数的实部
    double _image;          //  复数的虚部
};


#endif //IMOOC_DEMO_COMPLEX_H
