/*
Description
You are given two integers, A and B.  Just output all the odd numbers from A to B (A and B are inclusive). Odd number is what we call 奇数.

Input
Two integers, A and B.     ( 0<= A <= B <=100000 )

Output
All the odd numbers in interval [A,B] in increasing order.  Each line contains one number.
*/
#include<stdio.h>
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(a=a%2?a:a+1;a<=b;a+=2)
		printf("%d\n",a);
}