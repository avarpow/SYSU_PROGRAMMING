/*
Description
Write a program that reads in a variable n(-3.14<= n <= 3.14) , and output sin(n)、 cos(n)、fabs(n)

Input
a variable n

Output
sin(n)、 cos(n)、fabs(n). And the outputs are separeated by a space.

Sample Input
1
Sample Output
0.841 0.540 1.000
*/
#include<stdio.h>
#include<math.h>
int main()
{
    double n;
    scanf("%lf", &n);
    printf("%.3lf %.3lf %.3lf\n",sin(n), cos(n),fabs(n));
    return 0;
}