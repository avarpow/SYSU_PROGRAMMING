/*
Description
Write a program that reads an unspecified number of scores and determines how many scores are above or equal to the average and how many scores are below the average. Enter a negative number to signify the end of the input. Assume the maximum number of scores is 100.

Input
The first line is a positive integer t for the number of test cases. Each test case contains unspecified number of integers, ended by a negative integer.

Output
For each test case, outputs the count of numbers above or equal to the average and count of number below the average, seperated by one blank.

Sample Input
2
1 2 -1
2 2 2 2 -1
Sample Output
1 1
4 0
*/
#include<stdio.h>
int main()
{
    int n,a[105],t,tot,sum,c;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        tot = sum = c = 0;
        while(scanf("%d",&t),t>=0){
            a[tot++] = t;
            sum += t;
        }
        double avg = 1.0 * sum / tot;
        for (int i = 0;i<tot;i++){
            if(a[i]<avg)
                c++;
        }
        printf("%d %d\n", tot - c, c);
    }
    return 0;
}