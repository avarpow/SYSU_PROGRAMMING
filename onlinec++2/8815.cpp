#include <cmath>
#include <iostream>

//point.h
class point
{
public:
    double x, y;
    point(double _x, double _y);
    ~point();
    static int count;
    bool judge(const point &a, const point &b);
    void print();
};
int point::count = 0;
point::point(double _x, double _y) : x(_x), y(_y) { count++; }
bool point::judge(const point &a, const point &b)
{
    return fabs((a.y - y) * (b.x - x) - (b.y - y) * (a.x - x)) < 10e-6;
}
void point::print()
{
    std::cout << '(' << x << ',' << y << ')' << std::endl;
}
point::~point()
{
    count--;
}
//main.cpp
#include <iostream>
using namespace std;

int main()
{
    double x, y;
    cin >> x >> y;
    point p1(x, y);
    p1.print();
    cout << point::count << endl;
    cin >> x >> y;
    point p2(x, y);
    cin >> x >> y;
    point p3(x, y);
    if (p1.judge(p2, p3))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    cout << point::count << endl;
    return 0;
}
/*
Week2 实现一个简单point类 实时评测
 2020-04-18 19:40
 1000 ms
 32 MB
 周玉飞 (18340232)
Description
实现一个point类，它具有以下特征：

point有一个静态数据成员，count，记录了一共创建了多少个point对象
point有两个基本属性x，y分别记录了x和y轴的坐标，x，y的初始值为0；
point有一个方法，judge可以判断三个点是否在一条直线上
point可以打印出点的坐标(x,y)
Sample Input
1 1
2 2
3 3
Sample Output
(1,1)
1
True
3
Hint
``` 观察给出的main函数，实现point
*/