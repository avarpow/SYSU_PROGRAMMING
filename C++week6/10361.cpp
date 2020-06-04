//source.h
class Point
{
    int x, y;

public:
    Point(int x, int y);
    void Move(int x, int y);
    int Getx() const;
    int Gety() const;
};
Point::Point(int _x, int _y) : x(_x), y(_y) {}
void Point::Move(int _x, int _y)
{
    x = x + _x, y = y + _y;
}
int Point::Getx() const
{
    return x;
}
int Point::Gety() const
{
    return y;
}
class Rectangle : public Point
{
    int width, length;

public:
    Rectangle(int _x, int _y, int _length, int _width) : Point(_x, _y), length(_length), width(_width)
    {
    }
    int Getlength()
    {
        return length;
    }
    int Getwidth()
    {
        return width;
    }
    int Getarea()
    {
        return width * length;
    }
};
//framwork.cpp
#include <iostream>
//#include "source.h"
using namespace std;

int main()
{
    int n;
    double x, y, length, width, xmove, ymove;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        cin >> length >> width;
        Rectangle R(x, y, length, width);
        cin >> xmove >> ymove;
        R.Move(xmove, ymove);
        cout << R.Getx() << " " << R.Gety() << " "
             << R.Getlength() << " " << R.Getwidth()
             << " " << R.Getarea() << endl;
    }
    return 0;
}
/*
Rectangle
Description
1、定义基类 Point，使其能够初始化坐标（x，y），移动坐标，返回坐标

2、定义派生类 Rectangle，有成员变量 width、high；并且有成员函数，使其能够返回矩形相关属性：宽、高、面积

基类：

class Point
{  
    int x,y;
public:
    Point(int x,int y);
    void Move(int x,int y);
    int Getx() const;
    int Gety() const;
};
主函数：

cin>>x>>y;
cin>>length>>width;
Rectangle R(x,y,length,width);
cin>>xmove>>ymove;
R.Move(xmove,ymove);
cout <<R.Getx()<<" "<<R.Gety()<<" "<<R.Getlength() <<" "<<R.Getwidth()<<" "<<R.Getarea()<<endl;
Input
第一行输入n，代表n组测试例子

第二行输入x，y ，表示坐标原点A（x,y）

第三行输入length，width，表示矩形长、宽

第四行输入xmove，ymove，表示原点A在横纵坐标移动的距离。

Output
每组数据，输出一行，分别是：移动后的横坐标、纵坐标；矩形长、宽；面积。

Sample_Input
1
0 0
8 4
10 12
Sample_Ouput
10 12 8 4 32
Hint
you ﻿only need  to submit the class Point and Rectangle.

方法名首字母大写,其余字母小写
*/