#include <stdio.h>
long long a[30];
long long now = 0;
int ans = 0;
int n;
long long t;
void dfs(int step)
{
    if (step == n)
    {
        ++ans;
        return;
    }
    else
    {
        dfs(step + 1);
        now += a[step];
        if (now <= t)
        {
            dfs(step + 1);
        }
        now -= a[step];
    }
}
int main()
{
    scanf("%d%lld", &n, &t);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    dfs(0);
    printf("%d", ans);
    return 0;
}