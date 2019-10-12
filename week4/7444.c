/*
Description
Write a program that reads in the radius and length of a cylinder and computes volume using the following formulas: area = radius * radius * PI volume = area * length PI = 3.14159 
*/
#include <stdio.h>
int main(){
    double pi = 2,now=2.0/3,r,l;
    scanf("%lf%lf",&r,&l);
    for (int i = 1; i < 30;pi = pi + now,now = now * (i + 1) / ((2 * (i + 1)) + 1),i++);
    printf("%.4lf",pi*r*r*l);
    return 0;
}