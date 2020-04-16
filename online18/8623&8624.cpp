#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int val;
    int step;
};
int *biao[100002];
int count[100002] = {0};
int vis[100002] = {0};
struct node que[100005];
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
    vis[1] = 1;
    int flag = 0;
    while (end - top > 0)
    {
        if (que[top].val == n)
        {
            printf("%d\n", que[top].step);
            flag = 1;
            break;
        }
        int now = que[top].val;
        int co = count[now];
        for (int i = 0; i < co; i++)
        {
            if (vis[biao[now][i]] == 0)
            {
                vis[biao[now][i]] = 1;
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
    return 0;
}