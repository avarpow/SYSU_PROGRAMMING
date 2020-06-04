//fruit.h
#ifndef Fruit_H
#define Fruit_H
#include <iostream>
using namespace std;

class Fruit
{
public:
    Fruit();

    friend ostream &operator<<(ostream &out, const Fruit &x);
    friend istream &operator>>(istream &in, Fruit &x);

private:
    string name, color;
};

#endif

//fruit.cpp
//#include "Fruit.h"
Fruit::Fruit()
{
}
ostream &operator<<(ostream &out, const Fruit &x)
{
    out << x.name << " " << x.color << endl;
    return out;
}
istream &operator>>(istream &in, Fruit &x)
{
    in >> x.name >> x.color;
    return in;
}
//main.cpp
#include <iostream>
#include <cstdlib>
//#include "Fruit.h"
using namespace std;

int main()
{
    Fruit fruit1;
    cin >> fruit1;
    cout << fruit1;
    cout << "Finished!";
    return 0;
}
/*
description
使用友元函数实现标准输入和输出函数重载
类的声明如下：
class Fruit
{
public:
    Fruit();

    friend ostream& operator << (ostream& out, const Fruit& x);
    friend istream& operator >> (istream& in,  Fruit& x);

private:
    string name, color;
};
输出格式为：
apple red
Finished!
*/