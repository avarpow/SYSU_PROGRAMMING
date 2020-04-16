#include <stdio.h>
int last = 0, maxx = 0;
int main()
{
    int n, m, t, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t);
        if (last >= 0)
        {
            last += t;
            if (last > maxx)
            {
                maxx = last;
            }
        }
        else
        {
            last = t;
            if (last > maxx)
            {
                maxx = last;
            }
        }
    }
    printf("%d", maxx);
}

/*
题目描述
回到了学校的俊俊，又开始了在食堂排队的日子。

窗口里有n道菜，一字排开，每道菜俊俊都给了一个“美味度”a，当然美味度有正有负，负的自然吃起来不开心。

因为一些原因，俊俊只能从这n道菜里面拿连续的k道菜去吃。于是俊俊思考，怎么样能让吃的菜的美味度之和最大，有的话又是多少。

输入格式
第一行为菜的数量n
第二行为n道菜各自的美味度a1,a2,a3,…,an
输出格式
美味度之和的最大值

输入样例
9
-2 1 -3 4 -1 2 1 -5 4 
输出样例
6
数据范围
n≤5000
1≤k≤n
−1000≤ai≤1000
*/