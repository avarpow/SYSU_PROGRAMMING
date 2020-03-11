//逆序数对
#include <stdio.h>
#define N 2000000
int a[N];
int b[N];
long long mergesort(int l, int r);
int main()
{
    int m, n;
    long long ans = 0;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }
        ans = mergesort(0, n - 1);
        //printf("ans=%lld\n", ans);
        printf("%s\n", ans & 1 ? "-" : "+");
    }
    return 0;
}
long long merge(int l, int r)
{
    long long ans = 0;
    int left = l, right = (l + r) / 2 + 1, cur = l;
    while (left <= (l + r) / 2 && right <= r)
    {
        if (a[left] < a[right])
        {
            b[cur++] = a[left++];
        }
        else
        {
            b[cur++] = a[right++];
            ans += (l + r) / 2 - left + 1;
        }
    }
    while (left <= (l + r) / 2)
    {
        b[cur++] = a[left++];
    }
    while (right <= r)
    {
        b[cur++] = a[right++];
    }
    for (int i = l; i <= r; i++)
    {
        a[i] = b[i];
    }
    return ans;
}
long long mergesort(int l, int r)
{
    long long ans = 0;
    if (l < r)
    {
        ans += mergesort(l, (l + r) / 2);
        ans += mergesort((l + r) / 2 + 1, r);
    }
    else
        return 0;
    ans += merge(l, r);
    return ans;
}
/*
Chino's preview
Description
为了庆祝小豆子队的毕业，智乃一行人开始了她们的毕业旅行。

斯德哥尔摩

在前往斯德哥尔摩的列车上，勤奋的智乃正预习着新的课本——《糕灯带兔》，其中讲到了一个行列式的东西：

∣∣∣∣∣∣x11x21⋮xn1x12x22⋮xn2⋯⋯⋯x1nx2n⋮xnn∣∣∣∣∣∣=∑p1p2…pn(−1)τ(p1p2…pn)x1p1x2p2…xnpn
其中p1p2…pn是关于1到n的一个排列，τ(p1p2…pn)表示排列p1p2…pn逆序对的数量。一个二元组(i,j)(1≤i<j≤n)是一组逆序对，当且仅当pi>pj。

很显然，一个n阶行列式的值就是n!项形如(−1)τ(p1p2…pn)x1p1x2p2…xnpn的和。

看到这个奇怪的定义，智乃忽然有了一个疑问：如果我从里面随便取一项，它的符号是加号的概率是多少？

但是智乃并不会算qwq，所以她决定进行m次操作，每次操作取出一项(−1)τ(p1p2…pn)x1p1x2p2…xnpn，然后计算出它的符号，并记下来。只要m足够大，智乃就能无限地接近答案。

但是智乃并不想算qwq，由于心算能力强的心爱早上起太早给智乃做三明治而睡着了。



于是智乃就把这个计算交给你了，希望你能在1s内回答。

但是智乃觉得有点于心不忍，于是她简化了下问题，保证了每一项xij(1≤i,j≤n)>0，然后她会告诉你m个关于1−n的排列p1p2…pn来代表她取出来的m项(−1)τ(p1p2…pn)x1p1x2p2…xnpn，你需要依次回答每一项的符号。正号回答"+"(没有引号),负号回答"-"(没有引号)。

Input
第一行有两个整数m,n(1≤m≤100,2≤n≤500000)，表示有m个关于1−n的排列。

接下来m行每行n个整数p1p2…pn，表示一个排列，满足pi≠pj(i≠j),且∀i∈[1,n],1≤pi≤n。

输入数据保证m×n≤1000000。

Output
输出有m行，第i行包括一个符号'+'或'-'（没有引号），表示第i个排列对应的项的符号是正号或负号。

Sample input
2 4

1 3 4 2

2 4 1 3

Sample output
+

-

Hint：智乃还是觉得有点于心不忍，于是她告诉你可以用归并排序来解决。
*/