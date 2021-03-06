//f(n,k)=k*f(n-1,k-1)+f(n-1,k)
#include <stdio.h>
#define MOD 1000000009
long long a[3050][3050] = {0};
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= k; i++)
    {
        a[1][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        a[i][1] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            a[i][j] = (j * a[i - 1][j] % MOD + a[i - 1][j - 1] % MOD) % MOD;
        }
    }
    printf("%lld", a[n][k]);
    return 0;
}

/*
题目描述
STA在和助教们聊天的时候萌生了出一道项目题的想法。

别的助教说这么做的话一定要分组，以小组为单位做。

STA觉得有道理，于是想要计算一下如果把n个互不相同的同学分成k组的话能有多少种可能。

分组的要求：

小组不能为空
每个同学都会且仅会属于一个小组
不同小组的人数不一定相同
STA试着口算了一下，发现情况有点多，叹了口气，决定还是写个程序算一下。

输入格式
整数n，k，表示把n个同学分成k个小组。

1≤n≤3000，1≤k≤n
输出格式
整数m，表示可行的分组方案数

数字有点大，请输出模1e9+9之后的结果。

样例输入
6 3

样例输出
90
*/