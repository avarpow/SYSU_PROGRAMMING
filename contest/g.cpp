#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int mid = m + 1;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = (x + abs(y - mid));
    }
    sort(a, a + k);
    int nowtime = 0;
    for (int i = 0; i < k; i++)
    {
        if (a[i] <= nowtime)
        {
            nowtime++;
        }
        else
        {
            nowtime = a[i];
        }
    }
    cout << nowtime << endl;
    return 0;
}