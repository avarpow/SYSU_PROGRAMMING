/*
Description
You will be given two positive integers num1 and num2 (which is also the order of input) and are required to output the result according to the following process:

sum them up as the result if their sum is divisible by num2
otherwise keep num1 as the result
Integers given are within [1, 1000000]

A new line \n is also expected after the result.
*/
#include <stdio.h>
int main()
{
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    printf("%d\n",num1%num2==0?num1+num2:num1);
    return 0;
}
