#include <cmath>
#include <iostream>
using namespace std;
class Point
{
private:
    double x, y;

public:
    Point();
    Point(double vx, double vy);
    Point(Point &pt);
    ~Point();
    double getx();
    double gety();
};

Point::Point() : x(0), y(0) {}
Point::Point(double vx, double vy) : x(vx), y(vy) {}
Point::Point(Point &pt) : x(pt.x), y(pt.y) {}

Point::~Point() {}
double Point::getx() { return x; }
double Point::gety() { return y; }
class Circle : public Point
{
private:
    double r;

public:
    Circle();
    Circle(Circle &c);
    Circle(double rx, double ry, double rr);
    int position(Point &pt);
    ~Circle();
};

Circle::Circle() : Point(), r(0) {}
Circle::Circle(Circle &c) : Point(c.getx(), c.gety()), r(c.r) {}
Circle::Circle(double rx, double ry, double rr) : Point(rx, ry), r(rr) {}
int Circle::position(Point &pt)
{
    double dis = sqrt(pow(pt.getx() - getx(), 2) + pow(pt.gety() - gety(), 2));
    // cout << "dis" << dis << endl;
    if (fabs(dis - r) <= 0.0001)
    {
        return 0;
    }
    else if (dis > r)
    {
        return 1;
    }
    else if (dis < r)
    {
        return -1;
    }
    else
        return 2;
}

Circle::~Circle()
{
}
class Rectangle : public Point
{
private:
    double length, width;

public:
    Rectangle();
    Rectangle(double cx, double cy, double cl, double cw);
    Rectangle(Rectangle &re);
    int position(Point &pt);
    ~Rectangle();
};

Rectangle::Rectangle(double cx, double cy, double cl, double cw) : Point(cx, cy), length(cl), width(cw)
{
}
Rectangle::Rectangle(Rectangle &re) : Point(re.getx(), re.gety()), length(re.length), width(re.width)
{
}
Rectangle::Rectangle() : Point(), length(0), width(0)
{
}
int Rectangle::position(Point &pt)
{
    int onckeck = 0, xcheck = 0, ycheck = 0;
    if (fabs(pt.getx() - getx()) <= 0.0001 && pt.gety() >= gety() && pt.gety() <= gety() + width)
    {
        onckeck = 1;
        // cout << "check x left pass" << endl;
    }
    if (fabs(pt.getx() - (getx() + length)) <= 0.0001 && pt.gety() >= gety() && pt.gety() <= gety() + width)
    {
        onckeck = 1;
        // cout << "check x right pass" << endl;
    }
    if (fabs(pt.gety() - gety()) <= 0.0001 && pt.getx() >= getx() && pt.getx() <= getx() + length)
    {
        onckeck = 1;
        // cout << "check y left pass" << endl;
    }
    if (fabs(pt.gety() - (gety() + width)) <= 0.0001 && pt.getx() >= getx() && pt.getx() <= getx() + length)
    {
        // cout << "check y right pass" << endl;
        onckeck = 1;
    }
    if (onckeck == 1)
        return 0;
    if (pt.getx() >= getx() && pt.getx() <= getx() + length)
    {
        xcheck = 1;
        //   cout << "check x  pass" << endl;
    }
    if (pt.gety() >= gety() && pt.gety() <= gety() + length)
    {
        ycheck = 1;
        //    cout << "check y  pass" << endl;
    }
    if (xcheck && ycheck)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
Rectangle::~Rectangle()
{
}

//main.cpp
#include <iostream>
//#include "Circle_and_Rectangle.h" using namespace std;
using namespace std;
int main()
{
    int cx, cy, cr;
    int rx, ry, rl, rw;
    int px, py;
    cin >> cx >> cy >> cr;
    cin >> rx >> ry >> rl >> rw;
    cin >> px >> py;
    Circle cc1(cx, cy, cr);
    Rectangle rt1(rx, ry, rl, rw);
    Point p1(px, py);
    switch (rt1.position(p1))
    {
    case 0:
        cout << "on-rectangle" << endl;
        break;
    case -1:
        cout << "inside-rectangle" << endl;
        break;
    case 1:
        cout << "outside-rectangle" << endl;
        break;
    }
    switch (cc1.position(p1))
    {
    case 0:
        cout << "on-circle" << endl;
        break;
    case -1:
        cout << "inside-circle" << endl;
        break;
    case 1:
        cout << "outside-circle" << endl;
        break;
    }
    return 0;
}
/*
[Inheritance]Circle and Rectangle 实时评测
 2020-06-24 23:59
 1000 ms
 32 MB
 陈德和 (chendh26@mail2.sysu.edu.cn)
Circle and Rectangle
Description
以点（Point）类为基类，重新派生类 Rectangle、Circle。（坐标系中坐标原点为(0,0)）
矩形水平放置，由左下方的顶点和长宽定义。
圆由圆心和半径定义。
派生类操作判断任一坐标点是在图形内，还是在图形的边缘上，还是在图形外。
基类：
class Point{
private:
    double x,y;
public:
    Point();
    Point(double vx,double vy);
    Point(Point &pt);
    double getx();
    double gety();
}; 
派生类Circle：
public:
    Circle();
    Circle(double rx,double ry,double rr);//通过圆心、半径定义一个圆
    Circle(Circle &c);//拷贝构造一个圆
    int position(Point &pt);//返回状态码，表示点与圆的关系：0:点在圆上; -1:点在圆内; 1:点在圆外.
private:
    double r;   
派生类Rectangle：
public:
    Rectangle();
    Rectangle(double cx,double cy,double cl,double cw);//通过左下方的顶点坐标、长、宽定义一个矩阵
    Rectangle(Rectangle &re);//拷贝构造一个矩阵
    int position(Point &pt);//返回状态码，表示点与矩阵的关系：同Circle
private:
    double length;
    double width; 
Input
无输入

Output
无输出
*/