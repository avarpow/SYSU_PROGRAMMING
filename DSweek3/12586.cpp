//#include "Polynomial.h"
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> Term; // ��һ��������ʾϵ�����ڶ���������ʾָ��
typedef vector<Term> Polynomial;
#include <algorithm>
Polynomial sum(const Polynomial &p, const Polynomial &q);
Polynomial mysum(const Polynomial &p, const Polynomial &q)
{
    Polynomial ret(p);
    for (auto &i : q)
    {
        int flag = 1;
        for (auto &j : ret)
        {
            if (i.second == j.second)
            {
                j.first += i.first;
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            ret.push_back(make_pair(i.first, i.second));
        }
    }
    ret.erase(remove_if(ret.begin(), ret.end(), [](const Term &a) { return a.first == 0 && a.second == 0; }), ret.end());
    sort(ret.begin(), ret.end(), [](const Term &a, const Term &b) { return a.second > b.second; });
    return ret;
}
Polynomial sum(const Polynomial &p, const Polynomial &q)
{
    return mysum(p, q);
}
void solve()
{
    Polynomial p, q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Term t;
        cin >> t.first >> t.second;
        p.push_back(t);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Term t;
        cin >> t.first >> t.second;
        q.push_back(t);
    }
    Polynomial r = mysum(p, q);
    Polynomial r2 = sum(p, q);
    Polynomial r3 = r2;
    r3.erase(remove_if(r3.begin(), r3.end(), [](const Term &t) { return t.first == 0; }), r3.end());
    if (r.size() == 0 && r3.size() == 0 && r2.size() > 4)
    {
        cout << "OK" << endl;
        return;
    }
    // cout << "r" << endl;
    // for (auto &i : r)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    // cout << "r2" << endl;
    // for (auto &i : r2)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    if (r.size() != r2.size() || (!equal(r.begin(), r.end(), r2.begin())))
    {
        cout << "OBS" << endl;
    }
    else
        cout << "OK" << endl;
    return;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        solve();
    }
    return 0;
}