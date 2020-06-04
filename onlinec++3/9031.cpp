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
//Myinterge.cpp
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