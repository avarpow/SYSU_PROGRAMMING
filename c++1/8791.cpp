//function.h
#ifndef FUNCTION_H
#define FUNCTION_H

void swap(int &, int &);
void addsub(int, int, int &, int &);

#endif
//function.cpp
void addsub(int x, int y, int &sum, int &diff)
{
    sum = x + y;
    diff = x - y;
}
void swap(int &x, int &y)
{
    int t = x;
    x = y, y = t;
}
//main.cpp
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int x, y, sum, diff;
    cin >> x >> y;
    addsub(x, y, sum, diff);
    cout << sum << '\t' << diff << endl;
    swap(x, y);
    cout << x << '\t' << y << endl;
    swap(sum, diff);
    cout << sum << '\t' << diff << endl;
    return 0;
}
/*
Week1 Call by Reference 实时评测
 2020-04-09 19:40
 1000 ms
 32 MB
 黄轩腾 (huangxt57@mail2.sysu.edu.cn)
Call by Reference
引用传递函数参数是C++区别于C的一大特性，可看作是指针的语法糖。通过引用传递参数主要有以下两个好处：

减少内存开销
设想有一个庞大的自定义结构体，当你想要将其作为函数参数时，若直接传入函数：

void f(struct HugeStruct hugestruct);
实际上是进行了将实参赋值给形参这样的内存拷贝，对于int，bool这样的类型来说可以忽略，但对于某些庞大的结构来说，这样的内存开销是不可接受的；

多个返回值
C++中的函数不支持多个返回值，假设你的函数想返回多个值，一种可行的解决方法是返回一个结构体，但某些情况下这样做可能不太优雅，因此可以通过使用引用作为函数参数，来支持多值返回。

void g(int x, int& y1, int& y2);                // y1, y2是返回值
请同学们自行查阅相关资料，完成以下两个函数：

void addsub(int x, int y, int& sum, int& diff);    // 将x, y相加结果储存在sum中，相减结果储存在diff中
void swap(int& x, int& y);                        // 交换x, y的值

*/