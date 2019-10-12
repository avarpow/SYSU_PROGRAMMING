/*
Description
实现两个函数，分别用于计算浮点数n的二次方和三次方。
主函数main.c已经给出，要求在main.c文件中实现double Square(double n);和double Cube(double n);这两个函数。
double Square(double n);中的参数n为给定的浮点数，返回值为n的二次方
double Cube(double n);中的参数n为给定的浮点数，返回值为n的三次方
*/
#include <stdio.h>
double Square(double n);
double Cube(double n);

int main()
{
    double n;
    scanf("%lf", &n);
    double square_n = Square(n);
    double cube_n = Cube(n);
    printf("%.4f %.4f\n", square_n, cube_n);
    return 0;
}

double Square(double n){
    return n * n;
}

double Cube(double n){
    return n * n * n;
}