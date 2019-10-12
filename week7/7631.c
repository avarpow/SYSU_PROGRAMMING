/*
Description
输入两个数，求这两个数的最大公约数。

Input
两个整数a、b(1 <= a,b <= 10000)，中间用一个空格隔开。

Output
a、b的最大公约数
*/
#include<stdio.h>
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",gcd(a,b));
}