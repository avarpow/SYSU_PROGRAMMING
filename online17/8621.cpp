#include <stdio.h>
#include <time.h>
char s[10004];
int n;
int maxx = 0;
int ans = 0;
int maxlen = 5;
char now[10];
void check(int allstep)
{
    int curr = 0, nowans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == now[curr])
        {
            curr++, nowans++;
            if (curr == allstep)
            {
                curr = 0;
            }
        }
    }
    nowans -= curr;
    ans = nowans / allstep * nowans;
    if (ans > maxx)
        maxx = ans;
}
int dfs(int step, int allstep)
{
    if (step == allstep)
    {
        check(allstep);
    }
    else
    {
        now[step] = 'a';
        dfs(step + 1, allstep);
        now[step] = 'b';
        dfs(step + 1, allstep);
        now[step] = 'c';
        dfs(step + 1, allstep);
    }
}
int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 1; i <= 7; i++)
    {
        dfs(0, i);
    }
    clock_t begin, end;
    double cost;
    //开始记录
    begin = clock();
    printf("%d", maxx);
    end = clock();
    cost = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("constant CLOCKS_PER_SEC is: %ld, time cost is: %lf secs", CLOCKS_PER_SEC, cost);
    return 0;
}