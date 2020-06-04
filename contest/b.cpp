#include <cstdio>
#include <iostream>
using namespace std;
int n, m;
long long ans;
long long a[30], b[101];

void sb(long long k)
{
    for (int i = 31; i >= 0; i--)
    {
        int now = k >> i;
        if (now == 0 && (!b[i]))
        {
            b[i] = k;
            break;
        }
        k ^= b[i];
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sb(a[i]);
    }
    for (int i = 31; i >= 0; i--)
    {
        int use = 0;
        if ((ans ^ b[i]) > ans && use < m)
        {
            ans ^= b[i];
        }
    }
    cout << ans << endl;

    return 0;
}