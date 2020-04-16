#include <stdio.h>
#include <time.h>
int a[30];
int tong[30] = {0};
int now[30] = {0};
int ans = 0;
int n;
void dfs(int step)
{
    if (step == n)
    {
        ++ans;
        return;
    }
    else
    {
        int i = 0;
        while (now[i] != 0)
            i++;
        if (i >= 2 * n)
            return;
        for (int j = 1; i + j + 1 < 2 * n; j++)
        {
            if (tong[j] > 1 && now[i + j + 1] == 0)
            {
                now[i] = j;
                now[i + j + 1] = j;
                tong[j] -= 2;
                dfs(step + 1);
                tong[j] += 2;
                now[i + j + 1] = 0;
                now[i] = 0;
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
    {
        scanf("%d", &a[i]);
        tong[a[i]]++;
    }
    clock_t begin, end;
    double cost;
    //开始记录
    begin = clock();
    dfs(0);
    printf("%d", ans);
    end = clock();
    cost = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("constant CLOCKS_PER_SEC is: %ld, time cost is: %lf secs", CLOCKS_PER_SEC, cost);
    return 0;
}