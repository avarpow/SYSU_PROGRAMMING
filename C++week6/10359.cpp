//fraction.h
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class fraction
{
private:
    int _numerator, _denominator;
    int gcd(const int &, const int &) const;
    // If you don't need this method, just ignore it.
    void simp();
    // To get the lowest terms.
public:
    fraction(const int & = 0, const int & = 1);
    // The numerator and the denominator
    // fraction(5) = 5/1 = 5 :)
    fraction(const fraction &);
    // copy constructor

    void operator=(const fraction &);

    // You must know the meaning of +-*/, don't you ?
    fraction operator+(const fraction &) const;
    fraction operator-(const fraction &) const;
    fraction operator*(const fraction &)const;
    fraction operator/(const fraction &) const;

    void operator+=(const fraction &);
    void operator-=(const fraction &);
    void operator*=(const fraction &);
    void operator/=(const fraction &);

    // Comparison operators
    bool operator==(const fraction &) const;
    bool operator!=(const fraction &) const;
    bool operator<(const fraction &) const;
    bool operator>(const fraction &) const;
    bool operator<=(const fraction &) const;
    bool operator>=(const fraction &) const;

    friend std::istream &operator>>(std::istream &, fraction &);
    // Input Format: two integers with a space in it
    // "a b" is correct. Not "a/b"
    friend std::ostream &operator<<(std::ostream &, const fraction &);
    // Normally you should output "a/b" without any space and LF
    // Sometims you may output a single integer (Why? Guess XD)
    // If it is not a number (den = 0), output "NaN"
};

#endif
//fraction.cpp
int fraction::gcd(const int &a, const int &b) const
{
    int tempa = abs(a), tempb = abs(b);
    return tempb == 0 ? tempa : gcd(tempb, tempa % tempb);
}
void fraction::simp()
{
    int _gcd = gcd(_numerator, _denominator);
    if (_gcd != 0)
    {
        _numerator /= _gcd;
        _denominator /= _gcd;
    }
    if (_numerator > 0 && _denominator < 0 || _numerator < 0 && _denominator < 0)
    {
        _numerator *= -1;
        _denominator *= -1;
    }
    if (_denominator == 0)
    {
        _numerator = 0;
    }
    return;
}
fraction::fraction(const int &numerator, const int &denominator) : _numerator(numerator), _denominator(denominator)
{
    this->simp();
}

// The numerator and the denominator
// fraction(5) = 5/1 = 5 :)
fraction::fraction(const fraction &other) : _numerator(other._numerator), _denominator(other._denominator)
{
    this->simp();
}
// copy constructor

void fraction::fraction::operator=(const fraction &other)
{
    _numerator = other._numerator, _denominator = other._denominator;
}

// You must know the meaning of +-*/, don't you ?
fraction fraction::fraction::operator+(const fraction &other) const
{

    int newnumerator = this->_numerator * other._denominator + other._numerator * this->_denominator;
    int newdenominator = other._denominator * this->_denominator;
    fraction temp(newnumerator, newdenominator);
    temp.simp();
    return temp;
}
fraction fraction::fraction::operator-(const fraction &other) const
{
    int newnumerator = this->_numerator * other._denominator - other._numerator * this->_denominator;
    int newdenominator = other._denominator * this->_denominator;
    fraction temp(newnumerator, newdenominator);
    temp.simp();
    return temp;
}
fraction fraction::operator*(const fraction &other) const
{
    int newnumerator = this->_numerator * other._numerator;
    int newdenominator = other._denominator * this->_denominator;
    fraction temp(newnumerator, newdenominator);
    temp.simp();
    return temp;
}
fraction fraction::operator/(const fraction &other) const
{
    int newnumerator = this->_numerator * other._denominator;
    int newdenominator = other._numerator * this->_denominator;
    fraction temp(newnumerator, newdenominator);
    temp.simp();
    return temp;
}

void fraction::operator+=(const fraction &other)
{
    int newnumerator = this->_numerator * other._denominator + other._numerator * this->_denominator;
    int newdenominator = other._denominator * this->_denominator;
    _numerator = newnumerator;
    _denominator = newdenominator;
    this->simp();
}
void fraction::operator-=(const fraction &other)
{
    int newnumerator = this->_numerator * other._denominator - other._numerator * this->_denominator;
    int newdenominator = other._denominator * this->_denominator;
    _numerator = newnumerator;
    _denominator = newdenominator;
    this->simp();
}
void fraction::operator*=(const fraction &other)
{
    int newnumerator = this->_numerator * other._numerator;
    int newdenominator = other._denominator * this->_denominator;
    _numerator = newnumerator;
    _denominator = newdenominator;
    this->simp();
}
void fraction::operator/=(const fraction &other)
{
    int newnumerator = this->_numerator * other._denominator;
    int newdenominator = other._numerator * this->_denominator;
    _numerator = newnumerator;
    _denominator = newdenominator;
    this->simp();
}

// Comparison operators
bool fraction::operator==(const fraction &other) const
{
    return (_denominator == other._denominator && _numerator == other._numerator);
}
bool fraction::operator!=(const fraction &other) const
{
    return !(*this == other);
}
bool fraction::operator<(const fraction &other) const
{
    if (other._denominator == 0 || this->_denominator == 0)
    {
        return false;
    }
    fraction temp = *this / other;
    return temp._numerator < temp._denominator;
}
bool fraction::operator>(const fraction &other) const
{
    if (other._denominator == 0 || this->_denominator == 0)
    {
        return false;
    }
    return !(*this == other || *this < other);
}
bool fraction::operator<=(const fraction &other) const
{
    return !(*this > other);
}
bool fraction::operator>=(const fraction &other) const
{
    return !(*this < other);
}

std::istream &operator>>(std::istream &in, fraction &fra)
{
    in >> fra._numerator >> fra._denominator;
    return in;
}
// Input Format: two integers with a space in it
// "a b" is correct. Not "a/b"
std::ostream &operator<<(std::ostream &out, const fraction &fra)
{
    if (fra._denominator == 0)
    {
        out << "NaN";
    }
    else
    {
        out << fra._numerator << " " << fra._denominator;
    }
    return out;
}
//main.cpp
//#include "fraction.h"

void print(const bool &f)
{
    if (f)
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
}

int main()
{
    fraction f1, f2;
    std::cin >> f1 >> f2;
    std::cout << f1 + f2 << ' ' << f1 - f2 << ' '
              << f1 * f2 << ' ' << f1 / f2 << std::endl;
    f1 += f2;
    std::cout << f1 << std::endl;
    f1 -= f2;
    std::cout << f1 << std::endl;
    f1 *= f2;
    std::cout << f1 << std::endl;
    f1 /= f2;
    std::cout << f1 << std::endl;
    print(f1 == f2);
    print(f1 != f2);
    print(f1 < f2);
    print(f1 > f2);
    print(f1 <= f2);
    print(f1 >= f2);
    return 0;
}
/*
Description
In this assignment you are required to complete a class for fractions.

It stores the numerator and the denominator, with the lowest terms.

It is able to communicate with iostreams by the fraction::operator << and >>.

For more details, read the header file.

Sample Input
1 0 2 3
Sample Output
NaN NaN NaN NaN
NaN
False
True
False
False
True
True
Hint:
输入的数据大小为short

如果分母为0，那么进行四则运算时返回一个0/0.

==操作符 相等的情况是 两个数分母都为0或者两个数本身相等。

 > <的操作就按正常的比较即可。即样例输入输出<>都为false的原因
选自zion.出题人:彭勃(TA)
*/