/*
Description
实现一个函数，void printMatrix(int m, int n)，其功能是打印 m 行 n 列的弓形矩阵。

例如，当 m=3, n=4 时，结果如下：

  1  2  3  4
  8  7  6  5
  9 10 11 12
Input
两个数，m (0<m<10) 和 n (0<n<10)，分别表示行数和列数

Output
m 行 n 列的弓形矩阵（每个数字宽度为 3，右对齐）

Sample Input
3 4
Sample Output
  1  2  3  4
  8  7  6  5
  9 10 11 12
*/

#include <stdio.h>
void printMatrix(int m,int n){
    int j;
    for (int i = 1; i <= m;i++){
        if(i%2==0){
            for (j = i*n; j>i*n-n;j--){
                printf("%3d", j);
            }
        }
        else{
            for (j = (i - 1) * n + 1; j < (i - 1) * n + 1 + n;j++){
                printf("%3d", j);
            }
        }
        printf("\n");
    }
}
int main() {
	int m, n;
	scanf("%d%d", &m ,&n);
	printMatrix(m, n);
    return 0;
}