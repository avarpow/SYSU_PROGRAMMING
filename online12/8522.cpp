//排序
#include <stdio.h>
#define N 100005
int a[N];
void quicksort(int left, int right);
int main()
{
    int n, b = 0, bb = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(0, n - 1);
    int maxx = a[n - 1], index = n - 1;
    while (index >= 0 && (a[index] == maxx))
        index--;
    if (index == -1)
    {
        printf("0");
    }
    else
    {
        printf("%d", a[index]);
    }
    return 0;
}
void quicksort(int left, int right)
{
    //printf("quicksort %d %d\n", left, right);
    if (left >= right)
        return;
    int temp = a[left];
    int l = left, r = right;
    while (l < r)
    {
        while (l < r && (temp <= a[r]))
        {
            r--;
        }
        a[l] = a[r];
        while (l < r && (temp >= a[l]))
        {
            l++;
        }
        a[r] = a[l];
    }
    a[l] = temp;
    quicksort(left, l);
    quicksort(l + 1, right);
}
/*
Background Story
出题人终于取得了艾米莉亚和女仆们的信任。他清楚，村庄里有诅咒，他要替蕾姆接下诅咒，彻底解决这桩事，好过掉这个存档点。

然而接下诅咒搞不好是要死人的，要解除诅咒，必须进森林里把魔兽全部杀光。蕾姆知道后，抢先一步进入了森林。

Description
森林里，蕾姆面对着 n 只魔兽，它们的攻击力分别是 a1,⋯,an。

魔兽会发动组合技。组合技是两只魔兽一起进攻，或者一只魔兽分身成两只魔兽然后一起进攻，设组合的两只魔兽攻击力分别为 x,y，则组合技的杀伤力是 xmody。

蕾姆只需要知道这些魔兽所能达到的最大杀伤力，换句话说，现在有一个序列 a[1…n]=a1,a2,…,an，求aimodaj|1≤i,j≤n 的最大值。

Input
​ 输入第一行为一个整数n (1≤n≤105)，表示序列的长度。

​ 接下来共n个整数，第i个整数表示ai (1≤ai≤109)。

Ouput
​ 输出aimodaj|1≤i,j≤n的最大值。

Example
Input	Output
5
1 1 1 1 1	0
Hint
​ 现代普通计算机1s大约能执行108次操作。
*/