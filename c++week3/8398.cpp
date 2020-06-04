//person.h
#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
using namespace std;

class Date
{
public:
    Date(int newYear, int newMonth, int newDay);
    int getYear();
    void setYear(int newYear);
    int getMonth();
    void setMonth(int);
    int getDay();
    void setDay(int);

private:
    int year;
    int month;
    int day;
};

class Person
{
public:
    Person(int _id, int year, int month, int day);
    Person(Person &); // copy constructor
    ~Person();
    int getId();
    Date *getBirthDate();

private:
    int id;
    Date *birthDate;
};

#endif
//person.cpp
Person::Person(int _id, int year, int month, int day)
{
    id = _id;
    birthDate = new Date(year, month, day);
}
Person::Person(Person &other)
{
    id = other.id;
    birthDate = new Date((other.getBirthDate())->getYear(), (other.getBirthDate())->getMonth(), (other.getBirthDate())->getDay());
}
Person::~Person()
{
    delete birthDate;
}
int Person::getId()
{
    return id;
}
Date *Person::getBirthDate()
{
    return birthDate;
}
Date::Date(int newYear, int newMonth, int newDay) : year(newYear), month(newMonth), day(newDay)
{
}
int Date::getYear()
{
    return year;
}
void Date::setYear(int newYear)
{
    year = newYear;
}
int Date::getMonth()
{
    return month;
}
void Date::setMonth(int newmonth)
{
    month = newmonth;
}
int Date::getDay()
{
    return day;
}
void Date::setDay(int newday)
{
    day = newday;
}