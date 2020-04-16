#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
struct node
{
    int val;
    int step;
};
int *biao[N];
int count[N] = {0};
int vis[N][2] = {0};
struct node que[N];
int top = 0, end = 0;
int main()
{
    int n, k, t;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        count[i] = k;
        biao[i] = (int *)malloc(sizeof(int) * k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &t);
            biao[i][j] = t;
        }
    }
    struct node first;
    first.val = 1;
    first.step = 0;
    que[end++] = first;
    vis[1][0] = 1;
    int flag = 0;
    while (end - top > 0)
    {
        if (que[top].val == n)
        {
            flag = 1;
        }
        if (que[top].val == n && (que[top].step & 1) == 0)
        {
            printf("%d\n", que[top].step);
            flag = 2;
            break;
        }
        int now = que[top].val;
        int nowstep = que[top].step + 1;
        int co = count[now];
        for (int i = 0; i < co; i++)
        {
            if (vis[biao[now][i]][nowstep & 1] == 0)
            {
                vis[biao[now][i]][nowstep & 1] = 1;
                struct node temp = que[top];
                temp.step++;
                temp.val = biao[now][i];
                que[end++] = temp;
            }
        }
        top++;
    }
    for (int i = 0; i < n; i++)
    {
        free(biao[i]);
    }
    if (flag == 0)
    {
        printf("QAQ\n");
    }
    else if (flag == 1)
    {
        printf("QwQ\n");
    }
    return 0;
}