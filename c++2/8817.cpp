//COMPLEX.h
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
class COMPLEX
{
public:
    COMPLEX(double r = 0, double i = 0);
    COMPLEX(const COMPLEX &other);
    void print();

    COMPLEX operator+(const COMPLEX &other);

    COMPLEX operator-(const COMPLEX &other);
    COMPLEX operator-();
    COMPLEX operator=(const COMPLEX &other);

    COMPLEX &operator++();
    COMPLEX operator++(int);
    COMPLEX &operator--();
    COMPLEX operator--(int);

protected:
    double real, image;
};
#endif
//COMPLEX.cpp
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
//test.cpp
#include <vector>
#include <numeric>
#include <iostream>
#include <cstdlib>
#include "COMPLEX.h"
using namespace std;

int main()
{
    COMPLEX c1(1, 2);
    COMPLEX c2(2);
    COMPLEX c3(c1);

    c3.print();
    c1 = c1 + c2 + c3;
    c2 = -c3;
    c3 = c2 - c1;
    c3.print();

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
