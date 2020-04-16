//complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

struct Complex
{
    int r;
    int i;
    Complex();
    Complex(int r_, int i_);
    ~Complex();
};

double Distanceof(const Complex &c1, const Complex &c2);
#endif
//main.cpp
#include "check.h"
#include <iostream>
#include <math.h>
#include "complex.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Complex c1;
    int i, r;
    cin >> r >> i;
    Complex c2(r, i);
    cin >> r >> i;
    auto c3 = new Complex(r, i);
    cout << Distanceof(c2, *c3) << endl;
    delete c3;
    return 0;
}

//complex.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include "complex.h"
using std::cout;
using std::endl;
/*class Complex {
    int r;
    int i;
    Complex();
    Complex(int r_, int i_);
    Complex(const Complex& other);
    ~Complex();

    double Distanceof(const Complex& other) const;
    void Print() const;

    static int getCounter();

private:
    static int counter;
};
*/
Complex::Complex()
{
    r = 0;
    i = 0;
    cout << "Create an empty complex." << endl;
}

Complex::~Complex()
{
    cout << "Destroy an complex whose real is " << r << ", image is " << i << "." << endl;
}

Complex::Complex(int r_, int i_)
{
    r = r_;
    i = i_;
    cout << "Create an complex whose real is " << r_ << ", image is " << i_ << "." << endl;
}

double Distanceof(const Complex &c1, const Complex &c2)
{
    return sqrt(pow(c1.i - c2.i, 2) + pow(c1.r - c2.r, 2));
}
/*
Week1 Complex 实时评测
 2020-04-20 00:00
 1000 ms
 32 MB
 黄轩腾 (huangxt57@mail2.sysu.edu.cn)
Complex
在C++中实现一个复数结构体，并实现相应的构造函数和析构函数。

C++中结构体与C的区别：

拥有继承关系，可以定义public，private，protected等类型的数据成员，可以有虚函数等；
可以直接定义一些简单的函数，如构造函数，运算符重载等；
无需struct关键字即可直接使用结构体名定义新的对象。
本题要求实现一个复数结构体，其成员如下：

struct Complex {
    int r;
    int i;
    Complex();
    Complex(int r_, int i_);
    ~Complex();
};
以及函数：

double Distanceof(const Complex& c1, const Complex& c2);
返回两个复数对应的复平面上的点$p1, p2$的距离。

要求在调用Complex()时，将实部和虚部都初始化为0，并输出以下内容：

Create an empty complex.
在调用Complex(int, int)时，将实部和虚部分别初始化r,i，并输出以下内容：

Create an complex whose real is r, image is i.
在调用析构函数时，输出：

Destroy an complex whose real is r, image is i.
Hint
在结构体或类外定义(实现)相关函数时，需要指出该函数是属于哪个结构体(类)的，请查阅构造函数，析构函数，域作用符的相关知识。
*/