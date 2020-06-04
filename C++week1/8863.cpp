//date.h
#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

class DATE // DATE.h----Specification file of class DATE
{
public:
    void Set(int, int, int);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    void Print() const;
    void Increment();
    void Decrement();

private:
    int month;
    int day;
    int year;
};

#endif // FUNCTION_H_INCLUDED

//date.cpp
#include "Date.h"
#include <iostream>
using namespace std;
char mon[12][10] = {"January", "February", "March", "April",
                    "May", "June", "July", "August",
                    "September", "October", "November", "December"};
void DATE::Set(int y, int m, int d) { year = y, month = m, day = d; }
int DATE::getMonth() const { return month; }
int DATE::getDay() const { return day; }
int DATE::getYear() const { return year; }
void DATE::Print() const
{
    cout << mon[month - 1] << " " << day << ", " << year << endl;
}
void DATE::Increment()
{

    day++;
    int days_per_month = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        days_per_month = 30;
    }
    else if (month == 2)
    {
        days_per_month = 28;
        if (year % 4 == 0)
        {
            days_per_month = 29;
            if (year % 100 == 0)
            {
                days_per_month = 28;
                if (year % 400 == 0)
                {
                    days_per_month = 29;
                }
            }
        }
    }
    if (day > days_per_month)
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
}
void DATE::Decrement()
{
    day--;
    int days_per_month = 31;
    if (month - 1 == 4 || month - 1 == 6 || month - 1 == 9 || month - 1 == 11)
    {
        days_per_month = 30;
    }
    else if (month - 1 == 2)
    {
        days_per_month = 28;
        if (year % 4 == 0)
        {
            days_per_month = 29;
            if (year % 100 == 0)
            {
                days_per_month = 28;
                if (year % 400 == 0)
                {
                    days_per_month = 29;
                }
            }
        }
    }
    if (day == 0)
    {
        day = days_per_month;
        month--;
        if (month == 0)
        {
            month = 12;
            year--;
        }
    }
}
//main.cpp
#include "Date.h"
#include <iostream>
using namespace std;
int main()
{
    DATE date1, date2;
    int tmp;

    date1.Set(1949, 10, 1);
    date1.Print();
    date1.Increment();
    date1.Print();
    date2.Set(1997, 7, 1);
    date2.Print();
    date2.Decrement();
    date2.Print();

    tmp = date1.getYear();
    tmp++;
    date1.Set(tmp, 12, 20);
    date1.Print();
    return 0;
}
/*
[classes and objects]Implement Date 实时评测
 2020-04-29 23:59
 1000 ms
 32 MB
 郭凯林 (18214733)
Class: is a user-defined data type that represents an ADT in C++ that have attributes (data members) and behaviors (member functions) that operate on the data members. Variables of the class type are called class objects(对象) or class instances(实例).

question:implement Date with class,the header file is given,please implement the source file Date.cpp.

Output
October 1, 1949
October 2, 1949
July 1, 1997
June 30, 1997
December 20, 1950
*/