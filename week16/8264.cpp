/*
Description
输入一个数字n（1<=n<=10), 不在范围内的n输出“Out Of Range.\n" 输出杨辉三角的前n行

Sample Input
6

Sample Output
1

1 1

1 2 1

1 3 3 1

1 4 6 4 1

1 5 10 10 5 1

Sample Input
16

Sample Output
Number 16 is Out Of Range.
*/
#include<stdio.h>
int a[12][12]={0};
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= 10;i++){
        a[i][0] = 1;
        a[i][i] = 1;
    }
    if (n <= 10)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
            }
        }
        for (int i = 0; i < n;i++){
            for (int j = 0; j <= i;j++){
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("Number %d is Out Of Range.\n", n);
    }
    return 0;
}