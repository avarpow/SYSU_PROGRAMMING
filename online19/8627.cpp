#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200002
struct node
{
    int val;
    int step;
};
int *biao[N];
int count[N] = {0};
int vis[N] = {0};
struct node que[N];
int temp[N][2];
int top = 0, end = 0;
int main()
{
    int n, k, t;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        int co1 = 0, co2 = 0;
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &temp[j][0]);
        }
        for (int j = 0; j < k; j++)
        {

            scanf("%d", &temp[j][1]);
            if (temp[j][1] == 1)
            {
                co1++;
            }
        }
        co2 = k - co1;
        co1++;
        count[i] = co1;
        count[n + i] = co2;
        biao[i] = (int *)malloc(sizeof(int) * co1);
        biao[n + i] = (int *)malloc(sizeof(int) * co2);
        biao[i][0] = n + i;
        int fir = 1, sec = 0;
        for (int j = 0; j < k; j++)
        {
            if (temp[j][1] == 1)
            {
                biao[i][fir++] = temp[j][0];
            }
            else
            {
                biao[i + n][sec++] = temp[j][0];
            }
        }
    }
    // for (int i = 1; i <= 2 * n; i++)
    // {
    //     printf("i=%d  ", i);
    //     for (int j = 0; j < count[i]; j++)
    //     {
    //         printf("%d ", biao[i][j]);
    //     }
    //     printf("\n");
    // }
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
    for (int i = 0; i < 2 * n; i++)
    {
        free(biao[i]);
    }
    if (flag == 0)
    {
        printf("QAQ\n");
    }
    return 0;
}