/*
Given an odd integer n, please find the rule and print an n x n matrix.

Please complete the program according to the input and output examples.

EXAMPLE INPUT 1
5

EXAMPLE OUTPUT 1
1 2 3  
 123   
88944  
 765   
7 6 5  
EXAMPLE INPUT 2
7

EXAMPLE OUTPUT 2
1  2  3  
 1 2 3   
  123    
8889444  
  765    
 7 6 5   
7  6  5    
*/
#include<stdio.h>
int a[100][100]={0};
int main()
{
    int n;
    scanf("%d", &n);
    n = n % 2 ? n : n + 1;
    for (int i = 0; i < n / 2;i++){
        a[i][i] = 1;
        a[i][n / 2] = 2;
        a[i][n - 1 - i] = 3;
        a[i + n / 2+1][n / 2] = 6;
        a[n / 2][i] = 8;
        a[n / 2][i + n / 2 + 1] = 4;
        a[n - 1 - i][i] = 7;
        a[n - 1 - i][n - 1 - i] = 5;
    }
    a[n / 2][n / 2] = 9;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(a[i][j])
                printf("%d", a[i][j]);
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}