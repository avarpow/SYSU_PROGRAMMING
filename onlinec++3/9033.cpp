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
#include <iostream>

DATE::DATE(int y, int m, int d) : year(y), month(m), day(d)
{
}
DATE::DATE() : year(2020), month(5), day(16) {}

DATE &DATE::Set(int y, int m, int d)
{
    year = y, month = m, day = d;
    return *this;
}
int DATE::getMonth() const { return month; }
int DATE::getDay() const { return day; }
int DATE::getYear() const { return year; }
void DATE::Print() const
{
    char mon[12][10] = {"January", "February", "March", "April",
                        "May", "June", "July", "August",
                        "September", "October", "November", "December"};
    std::cout << mon[month - 1] << " " << day << ", " << year << std::endl;
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
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            days_per_month = 29;
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
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            days_per_month = 29;
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

#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
    DATE date1;
    DATE date2(1976, 12, 20);

    date1.Set(2011, 1, 1).Print();

    date2.Set(2012, 2, 2).Set(2013, 3, 3).Print();

    date2.Print(); // what is the output

    return 0;
}
