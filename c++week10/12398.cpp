#include <iostream>
using namespace std;
template <typename T>
void demoFunc(const T v1, const T v2)
{
    cout << "the first generic version of demoFunc()" << endl;
    cout << "the arguments: " << v1 << " " << v2 << endl;
}
template <typename T>
void demoFunc(const T v)
{
    cout << "the second generic version of demoFunc()" << endl;
    cout << "the argument: " << v << endl;
}

void demoFunc(const int v1, const int v2)
{
    cout << "the ordinary version of demoFunc()" << endl;
    cout << "the arguments: " << v1 << " " << v2 << endl;
}
//main.cpp
//#include "demo.hpp"

int main()
{
    char ch1 = 'A', ch2 = 'B';
    int iv1 = 3, iv2 = 5;
    double dv1 = 2.8, dv2 = 8.5;

    // 调用第一个函数模板的实例
    demoFunc(dv1, dv2);

    // 调用第二个函数模板的实例
    demoFunc(iv1);

    // 调用非模板函数demoFunc(int, int)
    demoFunc(iv1, iv2);

    // 调用非模板函数demoFunc(int, int)（进行隐式类型转换）
    demoFunc(ch1, iv2);

    return 0;
}
