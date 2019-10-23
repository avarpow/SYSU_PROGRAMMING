/*
Description
A prime number is a natural number greater that 1 that no positive divisors other than 1 and itself.
You are given an integer number P. You should judge whether P is a prime number.

Input
First line is the integer t∈[1,100], which indicates how many tests will be performed. Next, each line of the n lines is integer Pi∈[1,100000]
Output
If P is a prime number, just output "Yes". Otherwise you should output "No".

Sample Input
2
1
2
Sample Output
No
Yes
*/
#include<stdio.h>
int prime[100001] = {1,1};
int main()
{
    int n,t;
    scanf("%d", &n);
    for (int i = 2; i <= 50000;i++){
        if(prime[i]==0){
            for (int j = i + i; j <= 100001;j+=i){
                prime[j] = 1;
            }
        }
    }
    for (int i = 0; i < n;i++){
        scanf("%d", &t);
        printf("%s\n", prime[t] ? "No" : "Yes");
    }
}

