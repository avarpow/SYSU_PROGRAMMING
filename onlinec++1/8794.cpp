//date.h
#ifndef DATE_H_
#define DATE_H_

typedef struct
{
    int year, month, day;
} Date;

Date *CreateDate(int year, int month, int day);
void DestroyDate(Date **p);
Date *CopyDate(const Date *date);

int GetYear(const Date *date);
int GetMonth(const Date *date);
int GetDay(const Date *date);
void SetYear(Date *date, int year);
void SetMonth(Date *date, int month);
void SetDay(Date *date, int day);
void SetDate(Date *date, int year, int month, int day);

char *GetDateString(const Date *date);
void DestroyDateString(char **p);

void IncreaseDate(Date *date);
void DecreaseDate(Date *date);

#endif
//date_client.c
#include "date.h"
#include <stdio.h>
#include <assert.h>

void TestDate(Date *date, int after, int before)
{
    printf("Year: %d\n", GetYear(date));
    printf("Month: %d\n", GetMonth(date));
    printf("Day: %d\n", GetDay(date));

    char *date_string = GetDateString(date);
    printf("Formatted: %s\n", date_string);

    DestroyDateString(&date_string);
    assert(date_string == NULL);
    DestroyDateString(&date_string);

    IncreaseDate(date);
    date_string = GetDateString(date);
    printf("1 day later: %s\n", date_string);
    DestroyDateString(&date_string);

    int i;
    for (i = 0; i < after; ++i)
    {
        IncreaseDate(date);
    }
    date_string = GetDateString(date);
    printf("Another %d day(s) later: %s\n", after, date_string);
    DestroyDateString(&date_string);

    for (i = 0; i < before; ++i)
    {
        DecreaseDate(date);
    }
    date_string = GetDateString(date);
    printf("Another %d day(s) earlier: %s\n", before, date_string);
    DestroyDateString(&date_string);
}

int main()
{
    int year, month, day;
    int after, before;
    scanf("%d%d%d%d%d", &year, &month, &day, &after, &before);

    Date *date1 = CreateDate(year, month, day);
    assert(sizeof(*date1) == sizeof(Date));

    Date *date2 = CopyDate(date1);
    assert(date1 != date2);
    assert(date1->month == date2->month);

    SetDate(date1, year + 1, month, day);
    SetYear(date1, year);
    SetMonth(date1, month);
    SetDay(date1, day);

    TestDate(date1, after, before);

    DestroyDate(&date1);
    DestroyDate(&date2);

    assert(date1 == NULL);
    DestroyDate(&date2);

    return 0;
}

/*
One probable test case:

1900 2 28 365 366
Year: 1900
Month: 2
Day: 28
Formatted: 1900-02-28
1 day later: 1900-03-01
Another 365 day(s) later: 1901-03-01
Another 366 day(s) earlier: 1900-02-28

*/
//date.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "date.h"
/*
typedef struct {
  int year, month, day;
} Date;

Date* CreateDate(int year, int month, int day);
void DestroyDate(Date** p);
Date* CopyDate(const Date* date);

int GetYear(const Date* date);
int GetMonth(const Date* date);
int GetDay(const Date* date);
void SetYear(Date* date, int year);
void SetMonth(Date* date, int month);
void SetDay(Date* date, int day);
void SetDate(Date* date, int year, int month, int day);

char* GetDateString(const Date* date);
void DestroyDateString(char** p);

void IncreaseDate(Date* date);
void DecreaseDate(Date* date);
*/
Date *CreateDate(int year, int month, int day)
{
    Date *res = (Date *)malloc(sizeof(Date));
    res->year = year;
    res->month = month;
    res->day = day;
    return res;
}
void DestroyDate(Date **p)
{
    free(*p);
    *p = NULL;
}
Date *CopyDate(const Date *date)
{
    Date *res = (Date *)malloc(sizeof(Date));
    res->year = date->year;
    res->month = date->month;
    res->day = date->day;
    return res;
}

int GetYear(const Date *date)
{
    return date->year;
}
int GetMonth(const Date *date)
{
    return date->month;
}
int GetDay(const Date *date)
{
    return date->day;
}
void SetYear(Date *date, int year)
{
    date->year = year;
}
void SetMonth(Date *date, int month)
{
    date->month = month;
}
void SetDay(Date *date, int day)
{
    date->day = day;
}
void SetDate(Date *date, int year, int month, int day)
{
    date->year = year;
    date->month = month;
    date->day = day;
}

char *GetDateString(const Date *date)
{
    char *res = (char *)malloc(sizeof(char) * 100);
    sprintf(res, "%d%d-%d%d-%d%d", date->year / 10, date->year % 10, date->month / 10, date->month % 10, date->day / 10, date->day % 10);
    return res;
}
void DestroyDateString(char **p)
{
    free(*p);
    *p = NULL;
}

void IncreaseDate(Date *date)
{

    date->day++;
    int days_per_month = 31;
    if (date->month == 4 || date->month == 6 || date->month == 9 || date->month == 11)
    {
        days_per_month = 30;
    }
    else if (date->month == 2)
    {
        days_per_month = 28;
        if (date->year % 4 == 0)
        {
            days_per_month = 29;
            if (date->year % 100 == 0)
            {
                days_per_month = 28;
                if (date->year % 400 == 0)
                {
                    days_per_month = 29;
                }
            }
        }
    }
    if (date->day > days_per_month)
    {
        date->day = 1;
        date->month++;
        if (date->month > 12)
        {
            date->month = 1;
            date->year++;
        }
    }
}
void DecreaseDate(Date *date)
{
    date->day--;
    int days_per_month = 31;
    if (date->month - 1 == 4 || date->month - 1 == 6 || date->month - 1 == 9 || date->month - 1 == 11)
    {
        days_per_month = 30;
    }
    else if (date->month - 1 == 2)
    {
        days_per_month = 28;
        if (date->year % 4 == 0)
        {
            days_per_month = 29;
            if (date->year % 100 == 0)
            {
                days_per_month = 28;
                if (date->year % 400 == 0)
                {
                    days_per_month = 29;
                }
            }
        }
    }
    if (date->day == 0)
    {
        date->day = days_per_month;
        date->month--;
        if (date->month == 0)
        {
            date->month = 12;
            date->year--;
        }
    }
}
/*
Week1 ADT in C (Date Class) 实时评测
 2020-04-20 00:00
 1000 ms
 32 MB
 matrix (vmatrix@aliyun.com)
Task
学习如何用C模仿C++的类：
How do you implement a class in C?
根据给出的文件实现C中的“Date class”。

Hints
先认真阅读上面的链接。
void DestroyDate(Date** p); 中，传入Date**的作用是避免“空悬指针”问题。

One more step
试试在client代码中直接访问或修改Date的year等变量，跟C++版本有何不同？这会与“封装”原则冲突吗？

仔细辨别void SetDate(Date* date, int year, int month, int day)和void Date::setDate(int year, int month, int day);两者的异同， 包括参数数量，参数类型，命名风格等（关于命名风格可参照前面提到的《Google C++ Style Guide》）。

大胆猜想早期C++编译器是如何把C++程序转换为C程序的。另外，本题只是一种思路，有兴趣可以进一步了解

这种做法有必要吗？请查阅资料了解其应用场景。

如果void DestroyDate(Date** p); 传入Date*，可行吗？可能会导致什么问题？

为什么要把free()封装到Destroy()里？直接让client代码调用free()合适吗？

内存资源释放要求调用者调用Destroy*，可能会有什么问题？有兴趣的同学可以了解C++的解决方案（需要超前学习，选做）。

如果调用者写出date2 = date1这种代码，即两个指针指向同个“对象”，在内存资源释放上会有问题吗？有兴趣的同学可以了解C++的解决方案（需要超前学习，选做）。
*/