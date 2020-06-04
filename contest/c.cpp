#include <cstdio>
#include <iostream>
using namespace std;
long long b[10005];
int a, d, n;
int check(int m)
{
    for (int i = 0; i < n; i++)
    {
        if ((b[i] % m) != 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    cin >> a >> d >> n;
    b[0] = a;
    for (int i = 1; i < n; i++)
    {
        b[i] = b[i - 1] + d;
    }
    if (a == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        int minn = min(a, d);
        int ans = 1;
        for (int i = 2; i <= minn; i++)
        {
            if (check(i))
            {
                ans = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}