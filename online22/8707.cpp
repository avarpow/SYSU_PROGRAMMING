#include <stdio.h>
int a[600][600] = {0};
int srr[600];
int maxx = 0, t;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &t);
            a[i][j] = a[i][j - 1] + t;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j <= m; j++)
        {
            int now = 0;
            for (int k = 1; k <= n; k++)
            {
                if (now <= 0)
                {
                    now = a[k][j] - a[k][i - 1];
                }
                else
                {
                    now += a[k][j] - a[k][i - 1];
                }
                if (now > maxx)
                    maxx = now;
            }
        }
    }
    printf("%d", maxx);
}
/*
题目描述
有一天，食堂改革了。窗口里的菜变多了，一共n行m列。

一如既往每道菜俊俊都给了一个“美味度”a，当然美味度有正有负，负的自然吃起来不开心。

因为一些原因，俊俊只能从这些菜里面选取一个大小为p行q列的部分，然后把全部拿去吃。于是俊俊思考，怎么样能让吃的菜的美味度之和最大，有的话又是多少。

输入格式
第一行为菜的行数n和列数m
接下来为一个n行m列的矩阵，表示n×m道菜各自的美味度

输出格式
这样选取得到的美味度之和的最大值

输入样例
4 4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
输出样例
15
数据范围
n≤500
m≤500
−1000≤ai≤1000
*/