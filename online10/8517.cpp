//快速排序
#include <stdio.h>
#define N 25
void quicksort(int left, int right);

struct t
{
    int a, b, c;
} ts[N];
int same(const struct t a, const struct t b)
{
    return a.a == b.a && a.b == b.b && a.c == b.c;
}
int cmp(const struct t a, const struct t b)
{
    if (a.c != b.c)
    {
        return a.c < b.c;
    }
    else if (a.b != b.b)
    {
        return a.b > b.b;
    }
    else if (a.a != b.a)
    {
        return a.a < b.a;
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &ts[i].a, &ts[i].b, &ts[i].c);
    }
    quicksort(0, n - 1);
    printf("%d %d %d\n", ts[0].a, ts[0].b, ts[0].c);
    for (int i = 1; i < n; i++)
    {
        if (!(ts[i].a == ts[i - 1].a && ts[i].b == ts[i - 1].b && ts[i].c == ts[i - 1].c))
            printf("%d %d %d\n", ts[i].a, ts[i].b, ts[i].c);
    }
    return 0;
}
void quicksort(int left, int right)
{
    if (left >= right)
        return;
    struct t temp = ts[left];
    int l = left, r = right;
    while (l < r)
    {
        while (l < r && cmp(temp, ts[r]) == 0)
        {
            r--;
        }
        ts[l] = ts[r];
        while (l < r && cmp(temp, ts[l]) == 1)
        {
            l++;
        }
        ts[r] = ts[l];
    }
    ts[l] = temp;
    quicksort(left, l);
    quicksort(l + 1, right);
}
/*
Chino's Records
Description
没想到在异国里，也能遇到好多兔子！但与自己小镇的兔子不同的是，这里的兔子竟然会说兔语~~(哪只兔子不会说兔语)~~。



智乃从她们的兔语中惊奇地知道了兔子的一些属性——战斗力，敏捷力，还有毛茸茸性！智乃忽然有一个想法，但她先不告诉你嘿嘿嘿，不过她会告诉你的是接下来她要记录一下各自兔子的属性，而你要做的事情很简单：帮忙对兔子进行排序！ 智乃想要的排序规则是这样子的：

毛茸茸性大的兔子，要排在前面
毛茸茸性相同的兔子，敏捷力小的排在前面
毛茸茸性和敏捷力相同的兔子，战斗力大的排在前面
毛茸茸性、敏捷力、战斗力都相同的兔子，智乃认为是同一只兔子，只是她不小心多记了qwq，所以你保留一个就好啦。
最后按照顺序输出就可以了！

Input
第一行有一个正整数n(1≤n≤233333)，表示有n只兔子。

接下来n行。第i行包括三个整数CEi,AGLi,MOFUMOFUi(1≤CEi,AGLi,MOFUMOFUi≤100000000)，分别表示第i只兔子的战斗力，敏捷力和毛茸茸性。

Output
输出若干行，第i行包括三个整数，分别表示排序去重后第i只兔子的战斗力，敏捷力和毛茸茸性。

Sample input
5

1 2 3

2 1 3

1 3 4

2 2 3

1 2 3

Sample output
1 3 4

2 1 3

2 2 3

1 2 3

Hint：智乃说她喜欢用快速排序来解决出这道题的人。
*/