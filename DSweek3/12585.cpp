//Polynomial.h
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> Term; // 绗?涓€涓?鍒嗛噺琛ㄧず绯绘暟锛岀??浜屼釜鍒嗛噺琛ㄧず鎸囨暟
typedef vector<Term> Polynomial;
//poly_sum.cpp
#include <algorithm>
Polynomial sum(const Polynomial &p, const Polynomial &q)
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
    ret.erase(remove_if(ret.begin(), ret.end(), [](const Term &a) { return a.first == 0; }), ret.end());
    sort(ret.begin(), ret.end(), [](const Term &a, const Term &b) { return a.second > b.second; });
    return ret;
}
int solve()
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
    Polynomial r = sum(p, q);
    cout << r.size() << endl;
    for (auto &i : r)
    {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
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
//
/*
问题
假定多项式按降幂排列， 并用其系数指数对的序列表示，试实现多项式的加法。

输入
第一行是测试样例数n, 接下来是n个测试样例。 每个测试样例包含两个多项式，每个多项式的第一行是一个非负整数，表示多项式的项数，然后是按照降幂排列的多项式各项系数及指数对，系数和指数间用空格分隔。

输出
对每个测试样例，计算并输出两个多项式的和，第一行输出多项式和的项数，然后按照降幂排列输出各项系数和指数对，每对系数和指数各占一行，中间用一个空格分隔。

输入样例
2
2
1 2
-1 0
0
3
1 2
2 1
9 0
3
-1 2
-1 1
-8 0
输出样例
2
1 2
-1 0
2
1 1
1 0
*/