/*
Description
In this exercise you need to process a set of data, which has duplicate data and is unsorted. You need to sort them and just print one of the same data.

Input
the first line is a number n(0<n<=50), which stands for the number of test data.

the next 2*n lines contain n group of test data

In each group of test data , the first is a number m(0<m<=50) stands for the size of the test data, and the next line is the test datas.

Output
print sorted data without duplicate data.

Every output item is followed by a space , including the last output item. And each group of output is split by "\n", including the last row.

Sample Input
3
8
5 5 4 4 3 3 2 2
5
-2 -2 -3 -3 0
10
9 4 6 5 7 8 0 1 3 2
Sample Output
2 3 4 5 
-3 -2 0 
0 1 2 3 4 5 6 7 8 9 
*/
#include <stdio.h>
int main(){
    int t,a[60]={0},last,n;
    scanf("%d", &t);
    for (int i = 0; i < t;i++){
        scanf("%d", &n);
        for (int j = 0; j < n;j++){
            scanf("%d", &a[j]);
        }
        for (int j = 0; j < n;j++){
            for (int k = n-1; k > j;k--){
                if(a[k-1]>a[k]){
                    int t = a[k - 1];
                    a[k - 1] = a[k];
                    a[k] = t;
                }
            }
        }
        printf("%d ", last = a[0]);
        for (int j = 0; j < n;j++){
            if(a[j]!=last){
                printf("%d ", last = a[j]);
            }
        }
        printf("\n");
    }
    return 0;
}