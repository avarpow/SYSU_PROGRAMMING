#include <stdio.h>
#include <string.h>
struct dat
{
    char s[50];
    int y, m, d;
} ds[100];
int countday(int y, int m, int d)
{
    int ms[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0))
        ms[3]++;
    int ans = 1, nowm = 1, nowd = 1;
    while (nowm != m || nowd != d)
    {
        nowd++;
        if (nowd > ms[nowm])
        {
            nowm++;
            nowd = 1;
        }
        ans++;
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d%d%d", ds[i].s, &ds[i].y, &ds[i].m, &ds[i].d);
    }
    char s[50];
    scanf("%s", s);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(ds[i].s, s) == 0)
        {
            printf("%d", countday(ds[i].y, ds[i].m, ds[i].d));
        }
    }
}
/*
Description
There are n students in the class. The name and birthday of each student is recorded by Teacher Lisa. So Lisa can easily calculate which day of the year that each student born.（e.g., 2019.2.1 is the 32th day of the year.） Now given the record of students' names and birthdays, besides one quired student name, please help Lisa calculate which day of the year that the student born.

Input Description
The first line is a positive integer t for the number of student records. (1 <= t <=10)

Each record contains 4 lines: name, year of birth, month of birth, day of birth.

The last line is the quired student name.

(The length of each name is less than or equal to 15, and all the inputting date is valid. The quired student name is one of the name in student records. No student has the same name.)

Output Description
Which day of the year that the student born.

Sample Input
4
Jennie
1996
1
16
Jisoo
1995
1
3
Lisa
1997
3
27
Rose
1997
2
11
Lisa
Sample Output
86
*/