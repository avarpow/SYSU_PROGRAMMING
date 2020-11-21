#include <vector>
using namespace std;
int maxSubSum(const vector<int> &a)
{
    int ans = 0, maxx = -999999999;
    for (int i = 0; i < a.size(); i++)
    {
        ans += a[i];
        maxx = max(maxx, ans);
        if (ans < 0)
            ans = 0;
    }
    maxx = max(maxx, ans);
    return maxx;
}
