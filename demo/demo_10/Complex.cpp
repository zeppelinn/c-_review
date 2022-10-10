//
// Created by LiJun on 2022/10/6.
//

#include "Complex.h"

Complex::Complex() {
    _real = 0.0;
    _image = 0.0;
    cout << "Complex::Complex()" << endl;
}

Complex::Complex(double real, double image) {
    _real = real;
    _image = image;
    cout << "Complex::Complex(double real, double image)" << endl;
}

Complex::~Complex() {
    cout << "Complex::~Complex()" << endl;
}

Complex::Complex(const Complex &x) {
    _real = x._real;
    _image = x._image;
    cout << "Complex::Complex(const Complex& x)" << endl;
}

//  两种写法，1.在头文件中声明函数，在cpp中实现函数
double Complex::getImage() const { return _image; }

void Complex::setImage(double image) { _image = image; }

/**
 * 运算符的重载
 * 拷贝构造：需要注意的是，下方构造的一个tmp对象理论上是在堆上创建的一个变量，其在函数调用结束之后就会被释放，理论上调用该函数的地方是获取不到这个对象的
 *          所以实际上c++做了一次拷贝构造，在外部调用该函数获取到的结果对象跟这里的tmp不是一个对象
 * */
Complex Complex::operator+(const Complex &paramAdd) const {
//    需要拷贝构造的方式
//    Complex tmp;
//    tmp._real = _real + paramAdd._real;
//    tmp._image = _image + paramAdd._image;
//    return tmp;

//    无需拷贝构造的方式(优化)
    return {_real + paramAdd._real, _image + paramAdd._image};
}

Complex &Complex::operator=(const Complex &param) {
    if (this != &param) {
        _real = param._real;
        _image = param._image;
    }
    return *this;
}

ostream& operator<<(ostream &os, const Complex &x) {
    os << "real value is " << x._real << ", image value is " << x._image;
    return os;
}

istream& operator>>(istream& is, Complex& x) {
    is >> x._real >> x._image;
    return is;
}