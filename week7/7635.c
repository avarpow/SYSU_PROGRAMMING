/*
Description
输入一个整数，从最高位起依次输出每一位上的数字，用空格隔开。

Input sample
3
1256
0
1545
Output sample
1 2 5 6
0
1 5 4 5
*/
#include<stdio.h>
int main(){
	char s[20];
	int n;
	scanf("%d",&n);
	for(int i=0,j=0;i<n;i++,j=0){
		scanf("%s",s);
		while(s[j+1]!='\0')
			printf("%c ",s[j++]);
		printf("%c\n",s[j]);
	}
}