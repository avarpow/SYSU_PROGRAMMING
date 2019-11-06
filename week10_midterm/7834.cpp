/*
Description
输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）

Input
输入一个整数n (2 <= n <= 1000000)

Output
按照从小到大的顺序输出它的所有质数的因子，以空格隔开。最后一个数后面也有空格。

Sample Input
180

Sample Output
2 2 3 3 5
*/
#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n;i++){
            if(n%i==0){
                n = n / i;
                printf("%d%s",i,n==1?"\n":" ");
                i = 1;
        }
    }
    return 0;
}
