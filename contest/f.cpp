#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int> small;
priority_queue<int, vector<int>, greater<int>> big;
const long long MOD = 1e9 + 7;
long long num = 2333333;
long long qqq = 2333333;
int main()
{
    int n, t;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        int mid;
        if (i == 0)
        {
            small.push(t);
            mid = t;
        }
        else if (i == 1)
        {
            if (t > small.top())
            {
                big.push(t);
            }
            else
            {
                big.push(small.top());
                small.pop();
                small.push(t);
            }
            mid = small.top();
        }
        else if ((i % 2) == 0)
        {
            if (t < small.top())
            {
                small.push(t);
            }
            else
            {
                big.push(t);
                small.push(big.top());
                big.pop();
            }
            mid = small.top();
        }
        else if ((i % 2) == 1)
        {
            if (t > big.top())
            {
                big.push(t);
            }
            else
            {
                small.push(t);
                big.push(small.top());
                small.pop();
            }
            mid = small.top();
        }
        //cout << "test " << mid << endl;
        ans += ((mid % MOD) * (num % MOD)) % MOD;
        ans = ans % MOD;
        num = (num * qqq) % MOD;
    }
    cout << ans << endl;
    return 0;
}