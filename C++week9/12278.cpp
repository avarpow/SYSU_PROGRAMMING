
//Figure.h
#ifndef FIGURE_H
#define FIGURE_H
const double PI = 3.14159; // 圆周率常量

class FIGURE
{
public:
    void set_size(double x, double y = 0);
    virtual double get_area() const = 0; // get_area()被声明为纯虚函数
protected:
    double x_size, y_size;
};

void FIGURE::set_size(double x, double y)
{
    x_size = x;
    y_size = y;
}
#endif
// Triangle.h
#ifndef TRIANGLE_H
#define TRIANGLE_H
class TRIANGLE : public FIGURE
{
public:
    virtual double get_area() const override
    {
        return x_size * y_size / 2;
    }
};

#endif
// Rectangel.h
#ifndef RECTANGLE_H
#define RECTANGLE_H
class RECTANGLE : public FIGURE
{
public:
    double get_area() const override
    {
        return x_size * y_size;
    }
};

#endif
// Circle.h
#ifndef CIRCLE_H
#define CIRCLE_H
class CIRCLE : public FIGURE
{
public:
    double get_area() const override
    {
        return x_size * x_size * PI;
    }
};

#endif
//main.cpp
// #include "Figure.h"
// #include "Triangle.h"
// #include "Rectangel.h"
// #include "Circle.h"
#include <iostream>
using namespace std;

int main()
{
    TRIANGLE triangle;
    RECTANGLE rectangle;
    CIRCLE circle;

    // 处理三角形
    triangle.set_size(15, 8); // 设置三角形的底和高
    cout << "Area of triangle is " << triangle.get_area() << "\n";

    // 处理矩形
    rectangle.set_size(15, 8); // 设置矩形的长和宽
    cout << "Area of rectangle is " << rectangle.get_area() << "\n";

    // 处理圆
    circle.set_size(15); // 设置圆的半径
    cout << "Area of circle is " << circle.get_area() << "\n";
    return 0;
}
/*
[Polymorphism]abstract class from lecture 5 实时评测
 2020-07-08 23:59
 1000 ms
 32 MB
 尹阁麟 (732591466@qq.com)
Description
There are 4 classes, Figure is the base class，both Triangle, Rectangle and Circle are all inherited from it. Figure class is like following:

class FIGURE {
public:
    void set_size(double x, double y = 0);
    virtual double get_area() = 0 const ;   // get_area()被声明为纯虚函数
protected:
    double x_size, y_size;
};
You should implement Figure, Triangle, Rectange, Circle class.

Output
Area of triangle is 60
Area of rectangle is 120
Area of circle is 706.858
*/