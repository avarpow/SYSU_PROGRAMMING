//source.h
int sum(int a = 0, int b = 100, int c = 0)
{
    return a + b + c;
}
//main.cpp
#include <iostream>
using namespace std;

int main()
{
    cout << sum() << endl;
    cout << sum(6) << endl;
    cout << sum(6, 10) << endl;
    cout << sum(6, 10, 20) << endl;

    return 0;
}
/*
Week2 缺省值的使用 实时评测
 2020-04-18 19:40
 1000 ms
 32 MB
 周玉飞 (18340232)
Description
写一个sum函数,体会函数缺省值的使用.

对于主程序

int main ( ) 
{
cout << sum() << endl;
cout << sum(6) << endl;
cout << sum(6, 10) << endl;
cout << sum(6, 10, 20) << endl;
return 0;
}
有如下的输出

Sample Output
100 106 16 36

Hint
``` 根据函数调用时实参的使用和结果的输出,推测原来函数的声明和实现
*/