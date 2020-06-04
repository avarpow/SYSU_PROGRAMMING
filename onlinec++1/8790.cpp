//function.h
#ifndef FUNCTION_H
#define FUNCTION_H

int *Array(int);
int **Reshape(int *, int, int);
void FreeArray(int *);
void FreeMatrix(int **, int);

#endif
//function.cpp
int *Array(int len)
{
    int *res = new int[len];
    return res;
}
int **Reshape(int *vec, int row, int col)
{
    int **res = new int *[row];
    for (int i = 0; i < row; i++)
    {
        res[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            res[i][j] = vec[j + i * col];
        }
    }
    return res;
}
void FreeArray(int *vec)
{
    delete[] vec;
}
void FreeMatrix(int **mat, int row)
{
    for (int i = 0; i < row; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}
//main.cpp
// #include <iostream>
#include <stdio.h>

int main()
{
    int *vec = nullptr;
    int len, row, col;
    scanf("%d", &len);
    vec = Array(len);
    for (int i = 0; i < len; ++i)
    {
        scanf("%d", vec + i);
    }
    int **mat = nullptr;
    scanf("%d%d", &row, &col);
    mat = Reshape(vec, row, col);
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            printf("%d%c", mat[i][j], j == col - 1 ? '\n' : ' ');
        }
    }
    FreeArray(vec);
    FreeMatrix(mat, row);
    return 0;
}
/*Week1 Create Array 实时评测
 2020-04-09 19:40
 1000 ms
 32 MB
 黄轩腾 (huangxt57@mail2.sysu.edu.cn)
Create Array
使用C++中的关键字new和delete创建和回收数组。

实现以下四个函数：

int* Array(int len);                            
int** Reshape(int* vec, int row, int col);    
void FreeArray(int* vec);
void FreeMatrix(int** mat, int row);
其中，Array函数创建一个长度为len的一维数组；Reshape函数将上述数组变为一个row×col的矩阵，题目数据保证row×col=len。

已禁用stdlib.h，请勿使用malloc及free。

Input
6
1 2 3 4 5 6
2 3
Output
1 2 3
4 5 6
将长度为6的向量reshape为2×3的矩阵。
*/