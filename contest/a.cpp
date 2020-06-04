#include <cstdio>
#include <iostream>
using namespace std;
int a[2005][2005] = {0};
long long ans = 0;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 0)
            {
                continue;
            }
            ans += 2;
            if (a[i][j] > a[i - 1][j])
            {
                ans += (a[i][j] - a[i - 1][j]);
            }
            if (a[i][j] > a[i + 1][j])
            {
                ans += (a[i][j] - a[i + 1][j]);
            }
            if (a[i][j] > a[i][j + 1])
            {
                ans += (a[i][j] - a[i][j + 1]);
            }
            if (a[i][j] > a[i][j - 1])
            {
                ans += (a[i][j] - a[i][j - 1]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}