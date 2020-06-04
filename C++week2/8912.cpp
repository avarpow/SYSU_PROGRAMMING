//Date.h
#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

class DATE // DATE.h----Specification file of class DATE
{
public:
    DATE();
    DATE(int newYear, int newMonth, int newDay);
    ~DATE();
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
#include <iostream>
using namespace std;
char mon[12][10] = {"January", "February", "March", "April",
                    "May", "June", "July", "August",
                    "September", "October", "November", "December"};
DATE::DATE()
{
    year = 1970;
    month = 1;
    day = 1;
}
DATE::DATE(int newYear, int newMonth = 1, int newDay = 1)
{
    year = newYear;
    month = newMonth;
    day = newDay;
}
int DATE::getMonth() const
{
    return month;
}
int DATE::getDay() const
{
    return day;
}
int DATE::getYear() const
{
    return year;
}

DATE::~DATE()
{
    cout << "The DATE CLASS will be destroyed." << endl;
}
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
//main
//#include "Date.h"
#include <iostream>
using namespace std;
int main()
{
    DATE date1;
    int tmp;

    date1.Print();
    date1.Increment();
    date1.Print();

    int year, month, day;

    cin >> year >> month >> day;

    DATE date2(year, month, day);
    date2.Print();
    date2.Decrement();
    date2.Print();

    tmp = date1.getYear();
    tmp++;

    DATE date3(tmp, 12, 20);
    date3.Print();
    return 0;
}
