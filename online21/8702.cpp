#include <stdio.h>
int sum[100005] = {0};
int main()
{
    int n, m, t, a, b;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t);
        sum[i] = sum[i - 1] + t;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", sum[b] - sum[a - 1]);
    }
}

/*
题目描述
食堂吃多了，俊俊也慢慢放弃了追求。

今天来到食堂，窗口里还是有n道菜，编号从1到n一字排开。每道菜俊俊都给了一个“美味度”a，而a一定为正。

俊俊依旧只能从这n道菜里面拿连续的k道菜去吃。但俊俊今天思考的是这k道菜的美味度的和是多少。

当然了，这样的思考，他每顿饭要重复m次。

输入格式
第一行为菜的数量n和思考的次数m
第二行为n道菜各自的美味度a1,a2,a3,…,an
接下来的m行，每行包含两个整数L和R，代表选取的k道菜最左边编号为L，最右边编号为R

输出格式
每次思考之后，给定的菜的美味度之和，一次一行

输入样例
10 5
1 2 3 4 5 6 7 8 9 10
1 5
4 8
9 10
2 2
3 7
输出样例
15
30
19
2
25
数据范围
n≤100000
1≤k≤100000
0≤ai≤1000*/