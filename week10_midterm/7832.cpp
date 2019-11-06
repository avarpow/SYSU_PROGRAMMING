/*
Description
Please print a height h hollow isosceles triangle.
The hollow isosceles triangle(空心等腰三角形） is shown in the example.

Input
An integer h (2<=h<=100).

Output
The hollow isosceles triangle（空心等腰三角形）.
There is a new line at the end of output.

Sample Input
10
Sample Output
         *
        * *
       *   *
      *     *
     *       *
    *         *
   *           *
  *             *
 *               *
*******************
*/
#include<stdio.h>
int main()
{
    int n;
    int a[100][100] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        a[n - 1][i] = '*';
        a[n - 1][i + n-1] = '*';
        a[n - 1 - i][i] = '*';
        a[i][n + i-1] = '*';
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n + i;j++){
            if(a[i][j])
                printf("%c", a[i][j]);
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
