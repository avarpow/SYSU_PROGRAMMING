//complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
    int r;
    int i;
    Complex();
    Complex(int r_, int i_);
    Complex(const Complex &other);
    ~Complex();

    double Distanceof(const Complex &other) const;
    void Print() const;

    static int getCounter();

private:
    static int counter;
};
int Complex::counter = 0;
#endif

//complex.cpp
#include <iostream>
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
    counter++;
    cout << "Create an empty complex." << endl;
}

Complex::~Complex()
{
    counter--;
    cout << "Destroy an complex whose real is " << r << ", image is " << i << "." << endl;
}

Complex::Complex(int r_, int i_)
{
    counter++;
    r = r_;
    i = i_;
    cout << "Create an complex whose real is " << r_ << ", image is " << i_ << "." << endl;
}

Complex::Complex(const Complex &other)
{
    counter++;
    r = other.r;
    i = other.i;
    cout << "Copy from an complex whose real is " << other.r << ", image is " << other.i << "." << endl;
}

void Complex::Print() const
{
    if (r == 0 && i == 0)
    {
        cout << 0 << endl;
    }
    else if (r == 0)
    {
        cout << i << "i" << endl;
    }
    else if (i == 0)
    {
        cout << r << endl;
    }
    else
    {
        cout << r << std::showpos << i << "i" << std::noshowpos << endl;
    }
}
double Complex::Distanceof(const Complex &other) const
{
    return sqrt(pow(i - other.i, 2) + pow(r - other.r, 2));
}

int Complex::getCounter()
{
    return counter;
}
//main.cpp
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void printCounter()
{
    cout << "The number of complexes is: " << Complex::getCounter() << endl;
}

int main()
{
    Complex c0;
    printCounter();
    int r, i;
    cin >> r >> i;
    auto c1 = new Complex(r, i);
    c1->Print();
    printCounter();
    Complex c2(*c1);
    printCounter();
    delete c1;
    printCounter();
    cin >> r >> i;
    Complex c3(r, i);
    cout << "The distance is " << c2.Distanceof(c3) << endl;
    printCounter();
    return 0;
}
/*
Complex Class 实时评测
 2020-04-12 19:40
 1000 ms
 32 MB
 黄轩腾 (huangxt57@mail2.sysu.edu.cn)
Complex Class
实现一个复数类，其结构如下：

class Complex {
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
其中，调用Complex()时需将复数的实部和虚部初始化为0，并输出：

Create an empty complex.
调用Complex(int, int)时，将实部和虚部分别初始化为r,i，并输出以下内容：

Create an complex whose real is r, image is i.
调用Complex(const Complex)时，用传入的复数初始化当前复数，输出：

Copy from an complex whose real is r, image is i.
在调用析构函数时，输出：

Destroy an complex whose real is r, image is i.
函数Distanceof返回两个复数对应的复平面上的点的距离。

Print()函数输出当前复数，格式为：
a+bi
(注意某些特殊情况下的输出)。

除了上面这些内容，懒惰的计数君想要统计当前已经定义了多少复数，函数getCounter()返回当前复数的个数。

Hint
请查阅函数重载，类的成员属性，类中的静态成员等内容。
*/