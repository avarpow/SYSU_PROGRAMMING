//单调栈，单调队列
#include <stdio.h>
#include <string.h>
#define N 1000005
int a[N];
int maxx[N], minx[N];
//long long sum[N];
typedef struct p
{
    int index, value;
} pp;
pp ps[2000005];
double avrage[N];
struct Node
{
    int id, val;
} que[N];
int counts[N], dui[N];
int size = 0, l = 0, r = 1;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    a[0] = 0;
    //sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        //sum[i] = sum[i - 1] + a[i];
    }
    pp temp;

    int head = 1, tail = 0;
    for (int i = 1; i <= n; i++)
    {
        while (head <= tail && que[tail].val < a[i])
            tail--;
        while (head <= tail && que[head].id < i - k + 1)
            head++;
        que[++tail].val = a[i];
        que[tail].id = i;

        if (i >= k)
        {
            if (i != k)
                printf(" ");
            printf("%d", que[head].val);
        }
    }
    printf("\n");

    head = 1, tail = 0;
    for (int i = 1; i <= n; i++)
    {
        while (head <= tail && que[tail].val > a[i])
            tail--;
        while (head <= tail && que[head].id < i - k + 1)
            head++;
        que[++tail].val = a[i];
        que[tail].id = i;

        if (i >= k)
        {
            if (i != k)
                printf(" ");
            printf("%d", que[head].val);
        }
    }
    printf("\n");
    size = 0;
    for (int i = 1; i <= n; i++)
    {
        avrage[size] = a[i];
        counts[size] = 1;
        size++;
        while (size > 1 && avrage[size - 2] > avrage[size - 1])
        {
            double tempsum = avrage[size - 2] * counts[size - 2] + avrage[size - 1] * counts[size - 1];
            counts[size - 2] = counts[size - 2] + counts[size - 1];
            avrage[size - 2] = tempsum / counts[size - 2];
            size--;
        }
    }
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        while (counts[i]--)
        {
            printf("%.2lf ", avrage[i]);
        }
    }
    return 0;
}
/*
题目描述
小蒟蒻设计完游戏后身心俱疲，于是他从冰箱里拿出他最喜欢的果汁，从左往右倒了 n 杯果汁，第 i 杯果汁有 a[i] 毫升。 现在小蒟蒻很好奇，如果给定一个 k ，则任意连续的 k 杯果汁中，最多的一杯装了多少果汁，最少的一杯装了多少果汁？ 换句话说，你要分别告诉小蒟蒻序号在[1, k],[2, k + 1] …… [n – k + 1, n]区间内果汁的 ai 的最大和最小值。

蒟蒻发现最大值时高时低，他认为这不能给他带来开心，他认为当杯子里的果汁从左到右组成的序列字典序最小时，自己就会很开心。 于是他想进行任意多次操作，每次操作，小蒟蒻先可以将一段连续的杯子内的果汁变得平均，即选择区间[l, r]，l到r序号内所有的杯子里的果汁将变为 (a[l] + a[l + 1] + …… + a[r]) / (r – l + 1)。 可以进行任意次的以上操作，要让最后杯子内果汁的量的字典序最小，求最后每杯内的果汁容量。比如若有两杯果汁，从左到右果汁量为 2和1他就会不开心，因为平均后1.5和1.5的字典序更小，关于字典序详见下面描述 。

[什么是字典序小呢？我们设通过两个方案 B 和C后，杯子内的果汁分别为——方案B： b[1],b[2],……,b[n] 和方案C：c[1],c[2],……,c[n]；若称方案B最后杯子内果汁的量的字典序更小(即方案 B 更优)，当且仅当存在一个整数k(1≤k≤n)，使得对于 i＜k 有 b[i] ＝ c[i]，并且对于i ＝k 有 b[i] ＜ c[i],最后的答案应该为所有方案中最后杯子内果汁的量的字典序最小的那一个！]。

小蒟蒻不太聪明，快帮帮他吧！

输入格式
输入的第一行包括两个整数 n (1≤n≤1000,000) 和 k(1≤k≤n)，分别表示果汁的杯数和题目中要求统计的相邻的果汁数。 输入的第二行包括 n 个数a1，a2……an(ai＜1000,000,000)，其中 ai 表示初始时第 i 杯果汁中果汁的量。

输出格式
你一共需要输出三行。 第一行（n – k + 1） 个整数，第 i 个数代表下标在[i, i + k - 1]的果汁中最大的果汁量是多少。 第二行（n – k + 1） 个整数，第 i 个数代表下标在[i, i + k - 1]的果汁中最少的果汁量是多少。 第三行 n 个实数(保留两位小数)，代表经过若干次操作后得到的字典序最小的每一杯的果汁量。 相邻两个数中间有一个空格！

样例输入
7 3
1 2 3 4 3 2 1
样例输出
3 4 4 4 3
1 2 3 2 1
1.00 2.00 2.60 2.60 2.60 2.60 2.60
*/