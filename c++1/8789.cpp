#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int n, w;
    char c;
    cin >> n >> c >> w;
    cout.width(w);
    cout << showpos << setfill(c) << left << n;
}
/*
Week1 Basic iostream 实时评测
 2020-04-09 19:40
 1000 ms
 32 MB
 黄轩腾 (huangxt57@mail2.sysu.edu.cn)
Basic iostream
使用<iostream>以及<iomanip>库操纵输入输出流。

输入一行，包含一个整数n，一个字符c，一个整数w。

输出这个整数n，要求控制输出宽度为w，左对齐，空白部分用字符c填充，且n为非负整数时显示+号。

保证n的宽度小于w。

Input
4 c 6
0 v 6
-45 u 8
Output
+4cccc
+0vvvv
-45uuuuu
*/