/*
Description
A prime number is a natural number greater that 1 that no positive divisors other than 1 and itself. Please print the n-th prime number.

Input
An integer n (1<=h<=1000).

Output
The n-th prime number.

Sample Input
10
Sample Output
29
*/
#include<stdio.h>
int prime[1000001] = {1,1};
int main()
{
    int n, t, pos=0,count=0;
    scanf("%d", &n);
    for (int i = 2; i <= 500000;i++){
        if(prime[i]==0){
            for (int j = i + i; j <= 1000001;j+=i){
                prime[j] = 1;
            }
        }
    }
    for (pos=0; count!=n;pos++){
        if(prime[pos]==0)
            count++;
    }
    printf("%d\n", pos - 1);
    return 0;
}

