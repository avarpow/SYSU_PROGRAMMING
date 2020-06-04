//Myinterge.hpp
#ifndef MYINTEGER_HPP
#define MYINTEGER_HPP

#include <stddef.h>
class MyInteger
{
private:
    int value;

public:
    MyInteger(int);
    int getValue() const;
    bool isEven() const;
    bool isOdd() const;
    bool isPrime() const;
    static bool isEven(int);
    static bool isOdd(int);
    static bool isPrime(int);
    static bool isEven(const MyInteger &);
    static bool isOdd(const MyInteger &);
    static bool isPrime(const MyInteger &);
    bool equals(int) const;
    bool equals(const MyInteger &) const;
};

#endif
//Myinteger.cpp
//#include "MyInteger.hpp"
MyInteger::MyInteger(int x) : value(x)
{
}
int MyInteger::getValue() const { return value; }
bool MyInteger::isEven() const { return !(value & 1); }
bool MyInteger::isOdd() const { return !isEven(); }
bool MyInteger::isPrime() const
{
    if (value == 1)
    {
        return false;
    }
    int flag = 0;
    for (int i = 2; i * i <= value; i++)
    {
        if (value % i == 0)
        {
            flag = 1;
            break;
        }
    }
    return !flag;
}
bool MyInteger::isEven(int x) { return !(x & 1); }
bool MyInteger::isOdd(int x) { return !isEven(x); }
bool MyInteger::isPrime(int x)
{
    if (x == 1)
    {
        return false;
    }
    int flag = 0;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            flag = 1;
        }
    }
    return !flag;
}
bool MyInteger::isEven(const MyInteger &x) { return !(x.value & 1); }
bool MyInteger::isOdd(const MyInteger &x) { return !isEven(x); }
bool MyInteger::isPrime(const MyInteger &x)
{
    if (x.value == 1)
    {
        return false;
    }
    int flag = 0;
    for (int i = 2; i * i <= x.value; i++)
    {
        if (x.value % i == 0)
        {
            flag = 1;
        }
    }
    return !flag;
}
bool MyInteger::equals(int x) const { return value == x; }
bool MyInteger::equals(const MyInteger &x) const { return value == x.value; }
/*实现头文件中的声明的函数。

class MyInteger
{
private:
    int value;

public:
    MyInteger(int);
    int getValue() const;
    bool isEven() const;                    //判断value是否为偶数
    bool isOdd() const;                     //判断value是否为奇数
    bool isPrime() const;                   //判断value是否为质数
    static bool isEven(int);                //判断一个数是否为偶数
    static bool isOdd(int);                 //判断一个数是否为奇数
    static bool isPrime(int);               //判断一个数是否为质数
    static bool isEven(const MyInteger &);  //判断一个MyInteger类是否为偶数
    static bool isOdd(const MyInteger &);   //判断一个MyInteger类是否为奇数
    static bool isPrime(const MyInteger &); //判断一个MyInteger类是否为质数
    bool equals(int) const;                 //判断一个数跟value是否相等
    bool equals(const MyInteger &) const;   //判断一个MyInteger类是否跟这个类相等
};
输入 ：无输入

    输出：无输出*/