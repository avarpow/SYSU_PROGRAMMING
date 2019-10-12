/*
Description
A college has a list of test results (1 = pass, 2 = fail) for 10 students. Write a program that analyzes the results. If more than 8 students pass, print "Raise tuition".

Input
Ten numbers of test result, either 1 or 2.

Output
Display the number of passes and failures. If more than eight students passed, print "Raise tuition"
*/
#include<stdio.h>
int main(){
	int count=0,i=10,t;
	while(i--){
		scanf("%d",&t);
		if(t-1)count++;
	}
	printf("Passed: %d\nFailed: %d%s",10-count,count,count<2?"\nRaise tuition\n":"\n");
}