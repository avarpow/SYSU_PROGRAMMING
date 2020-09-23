//Polynomial.h
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> Term; // �?一�?分量表示系数，�??二个分量表示指数
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
int main()
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
    for (auto &i : r)
    {
        cout << "ϵ�� " << i.first << " ָ�� " << i.second << endl;
    }
    return 0;
}
//
/*
多项式相�? 定时评测
 2020-09-14 22:00
 1000 ms
 32 MB
 乔海�? (qiaohy@mail.sysu.edu.cn)
假定多项式按降幂排列�? 并用其系数指数�?�的向量表示，试实现多项式的加法�?

Polynomial sum(const Polynomial &p, const Polynomial &q);
注意:

你只需要在提交的实现中#inlcude "Polynomial.h"即可
你可能考虑�?0多项式�?�何表示。按照你的表示和算法如何表示更自然方便？�?不是空向量表�?0多项式更方便�?然？�?
*/