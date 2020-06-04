//complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

class COMPLEX
{
public:
    COMPLEX(double r = 0, double i = 0); // 构造函数
    COMPLEX(const COMPLEX &other);       // 拷贝构造函数
    void print();                        // 打印复数
                                         // 重载加法运算符（二元）
    COMPLEX operator+(const COMPLEX &other);
    // 重载减法运算符（二元）
    COMPLEX operator-(const COMPLEX &other);
    COMPLEX operator-(); // 重载求负运算符（一元）
                         // 重载赋值运算符（二元）
    COMPLEX operator=(const COMPLEX &other);

    COMPLEX &operator++();   //重载前置++
    COMPLEX operator++(int); //重载后置++
    COMPLEX &operator--();   //重载前置--
    COMPLEX operator--(int); //重载后置--
protected:
    double real, image; // 复数的实部与虚部
};
#endif
//complex.cpp
//#include <COMPLEX.h>
#include <iostream>
#include <iomanip>
using namespace std;
COMPLEX::COMPLEX(double r, double i) : real(r), image(i) {}
COMPLEX::COMPLEX(const COMPLEX &other) : real(other.real), image(other.image) {}
void COMPLEX::print()
{
    using namespace std;
    if (real == 0 && image == 0)
    {
        cout << 0 << endl;
    }
    else if (real == 0)
    {
        cout << image << "i" << endl;
    }
    else if (image == 0)
    {
        cout << real << endl;
    }
    else
    {
        cout << real << std::showpos << image << "i" << std::noshowpos << endl;
    }
}

COMPLEX COMPLEX::operator+(const COMPLEX &other)
{
    COMPLEX res;
    res.real = this->real + other.real;
    res.image = this->image + other.image;
    return res;
}

COMPLEX COMPLEX::operator-(const COMPLEX &other)
{
    COMPLEX res;
    res.real = this->real - other.real;
    res.image = this->image - other.image;
    return res;
}
COMPLEX COMPLEX::operator-()
{
    COMPLEX res;
    res.real = -real;
    res.image = -image;
    return res;
}
COMPLEX COMPLEX::operator=(const COMPLEX &other)
{
    real = other.real;
    image = other.image;
    return *this;
}

COMPLEX &COMPLEX::operator++()
{
    real++;
    image++;
    return *this;
}

COMPLEX COMPLEX::operator++(int)
{
    COMPLEX res = *this;
    real++;
    image++;
    return res;
}
COMPLEX &COMPLEX::operator--()
{
    real--;
    image--;
    return *this;
}
COMPLEX COMPLEX::operator--(int)
{
    COMPLEX res = *this;
    real--;
    image--;
    return res;
}
//main.cpp
#include <vector>
#include <numeric>
#include <iostream>
#include <cstdlib>
//#include "COMPLEX.h"
using namespace std;

int main()
{
    COMPLEX c1(1, 2); // 定义一个值为1 + 2i的复数c1
    COMPLEX c2(2);    // 定义一个值为2的复数c2
    COMPLEX c3(c1);   // 用拷贝构造函数创建一个值同c1的新复数

    c3.print();        // 打印c3的值
    c1 = c1 + c2 + c3; // 将c1加上c2再加上c3赋值给c1
    c2 = -c3;          // c2等于c3求负
    c3 = c2 - c1;      // c3等于c2减去c1
    c3.print();        // 再打印运算后c3的值

    COMPLEX temp = c3++;
    temp.print();
    c3.print();

    temp = c3--;
    temp.print();
    c3.print();

    temp = --c3;
    temp.print();
    c3.print();

    temp = ++c3;
    temp.print();
    c3.print();

    return 0;
}
/*
Description
实现复数的操作符重载，你需要做的是，将complex.h文件的函数声明，全部在complex.cpp中实现
函数的声明如下：
class COMPLEX
{
public:
    COMPLEX(double r = 0, double i = 0); // 构造函数
    COMPLEX(const COMPLEX &other);       // 拷贝构造函数
    void print();                        // 打印复数
                                         // 重载加法运算符（二元）
    COMPLEX operator+(const COMPLEX &other);
    // 重载减法运算符（二元）
    COMPLEX operator-(const COMPLEX &other);
    COMPLEX operator-(); // 重载求负运算符（一元）
                         // 重载赋值运算符（二元）
    COMPLEX operator=(const COMPLEX &other);
        COMPLEX & operator++();     //重载前置++
        COMPLEX operator++(int);     //重载后置++
        COMPLEX & operator--();        //重载前置--
        COMPLEX operator--(int);        //重载后置--
protected:
    double real, image; // 复数的实部与虚部
};
输出格式为：
1+2i
-5-6i
-5-6i
-4-5i
-4-5i
-5-6i
-6-7i
-6-7i
-5-6i
-5-6i
*/