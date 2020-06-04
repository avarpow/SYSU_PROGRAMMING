class DATE // DATE.h----Specification file of class DATE
{
public:
    DATE(int, int, int);
    DATE();

    DATE &Set(int, int, int);
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

//DATE.cpp
//the implementation of each member function of DATE.

//#include "DATE6.h"
#include <iostream>
using namespace std;

int DaysInMonth(int, int);

DATE::DATE(int initYear, int initMonth, int initDay)
{
    year = initYear;
    month = initMonth;
    day = initDay;
}

DATE::DATE()
{
    year = 2000;
    month = 1;
    day = 1;
}

DATE &DATE::Set(int newYear, int newMonth, int newDay)
{
    month = newMonth;
    day = newDay;
    year = newYear;
    return *this;
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

void DATE::Print() const
{
    switch (month)
    {
    case 1:
        cout << "January";
        break;
    case 2:
        cout << "February";
        break;
    case 3:
        cout << "March";
        break;
    case 4:
        cout << "April";
        break;
    case 5:
        cout << "May";
        break;
    case 6:
        cout << "June";
        break;
    case 7:
        cout << "July";
        break;
    case 8:
        cout << "August";
        break;
    case 9:
        cout << "September";
        break;
    case 10:
        cout << "October";
        break;
    case 11:
        cout << "November";
        break;
    case 12:
        cout << "December";
    }
    cout << ' ' << day << ", " << year << endl;
}

void DATE::Increment()
{
    day++;
    if (day > DaysInMonth(month, year))
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
    if (day == 0)
    {
        if (month == 1)
        {
            day = 31;
            month = 12;
            year--;
        }
        else
        {
            month--;
            day = DaysInMonth(month, year);
        }
    }
}

int DaysInMonth(int mo, int yr)
{
    switch (mo)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if ((yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0)
            return 29;
        else
            return 28;
    }
}
//main.cpp
//#include "DATE6.h"
#include <iostream>
using namespace std;

int main()
{
    //1. 在下面一行，实现定义对象指针变量date1；
    DATE *date1;
    DATE date2(1989, 6, 4);
    //2. 在下面一行，实现将date1指向对象date2；
    date1 = &date2;
    date2.Print();
    //3. 在下面一行，实现date1指向对象的Print；
    date1->Print();
    date2.Set(2013, 3, 3);
    date2.Print();

    DATE *date_ptr;
    //4. 在下面一行，实现动态创建一个DATE对象，初始化为1976年12月20日。方法：对象指针 = new 类名( 1976, 12, 20 );
    date_ptr = new DATE(1976, 12, 20);
    if (date_ptr == NULL)
    {
        cout << "error";
        return 1;
    }
    else
    {
        date_ptr->Increment();
        date_ptr->Print();
    }

    //5. 在下面一行，实现撤销对象；
    delete date_ptr;
    return 0;
}