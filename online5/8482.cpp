//fun.h
#include <stdio.h>
#include <stdlib.h>
void swap(int *p, int *q);
void print_array(int *p, int size);
void print_matrix(int **mat, int row, int col);

//main.c
#include <stdio.h>
//#include "fun.h"

int main(void)
{
    int a = 1, b = 2;
    swap(&a, &b);
    printf("%d %d\n", a, b);

    int c[5] = {1, 2, 3, 4, 5};
    print_array(c, 5);

    int **d = (int **)malloc(sizeof(int *) * 3);
    int i, j;
    for (i = 0; i < 3; i++)
    {
        *(d + i) = (int *)malloc(sizeof(int) * 3);
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            *(*(d + i) + j) = i + j + 1;
        }
    }
    print_matrix(d, 3, 3);
    for (i = 0; i < 3; i++)
    {
        free(*(d + i));
    }
    return 0;
}
//fun.c
#include <stdio.h>
void swap(int *p, int *q)
{
    int t = *q;
    *q = *p;
    *p = t;
}
void print_array(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", p[i]);
    }
}
void print_matrix(int **mat, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d%s", mat[i][j], j == col - 1 ? "\n" : " ");
        }
    }
}
/*
给出下列函数，大家要用指针的形式实现：

void swap(int* p, int* q);

void print_array(int* p, int size);

void print_matrix(int** mat, int row, int col);

其中swap是交换两个数字，printarray是打印数组，pirntmatrix是打印矩阵。

Input
None
Output
2 1
1
2
3
4
5
1 2 3
2 3 4
3 4 5
大家记得在fun.c里面#include “fun.h”
*/
