//数据结构
#include <stdio.h>
#include <string.h>
struct stu
{
    int time, cost;
} a[10055], b[10055];
int tong[10005];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].time);
        scanf("%d", &a[i].cost);
    }
    memcpy(b, a, sizeof(a));
    for (int j = n - 1; j >= 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (a[i].time > a[i + 1].time)
            {
                struct stu temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr < a[i].time)
        {
            curr = a[i].time;
        }
        tong[a[i].time] = curr + a[i].cost;
        curr += a[i].cost;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tong[b[i].time]);
    }
    return 0;
}
/*
题目描述
小蒟蒻今天去饭堂打饭时，脑子里浮现出这样一个问题： 假设一共有 n 个人到饭堂打饭，知道每个人到达饭堂的时间（保证各不相同）,也知道每个人打饭需要的时间。 但饭堂只有一个窗口，若某个人到达饭堂时有其他人在打饭或者排队，他就要自觉排在队伍的最后面，当前面的人都打完饭后他才开始打饭。 求每个人打完饭的时间。

输入格式
输入的第一行包括一个整数 n (1≤n≤1000)，表示去饭堂吃饭的总人数。 接下来 n 行，每行两个整数，第 i 行包括time[i] 和 cost[i](1≤time[i] 、cost[i] ≤10000)，分别表示第i个人到达饭堂的时间和他打饭耗费的时间。

输出格式
你需要输出一行n个整数 ans[i]，第 i 个整数表示第 i 个人（按照输入顺序的第 i 个人）打完饭的时间。相邻两个数中间有一个空格！

样例输入
2
2 3
3 4
样例输出
5 9
*/