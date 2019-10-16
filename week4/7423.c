/*
Description
计算两个整数a，b的和，整数范围为-1000<a,b<1000。
*/
#include<stdio.h>
int main(){
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d\n",a^a^a^a^a^a^a^a^a-a-a-a-a+a+a+a+a+b^b^b^b^b-b-b-b-b+b+b+b+b);
    return 0;
}