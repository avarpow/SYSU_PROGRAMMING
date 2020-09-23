#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
//#include "sort.hpp"
using namespace std;
//v:排序前的vector u:排序后的vector
bool test(vector<int> &v, vector<int> &u)
{
    if (v.size() != u.size()) //统计长度是否相等，这是判断u是v的重排列的先决条件
    {
        return false;
    }
    for (int i = 1; i < u.size(); i++) //判断是否有序，即命题q
    {
        if (u[i - 1] < u[i])
        {
            return false;
        }
    }
    //下面统计u是否是v的重排列，通过统计u中每个出现的值的元素个数是不是与v中该值的元素个数相同
    vector<int> vis;
    vis.resize(u.size());
    for (int i = 0; i < vis.size(); i++)
    {
        vis[i] = 0;
    }
    for (int i = 0; i < u.size(); i++)
    {
        if (vis[i] == 0)
        {
            int value = u[i];
            int count1 = 0, count2 = 0;
            for (int j = 0; j < u.size(); j++)
            {
                if (u[j] == value && vis[j] == 0)
                {
                    vis[j] = 1;
                    count1++;
                }
            }
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j] == value)
                {
                    count2++;
                }
            }
            //printf("\nvalue %d  count1 %d count2 %d\n", value, count1, count2);
            if (count1 != count2) //统计排序后数组和之前的数组中同一值的元素个数是不是都相等。
                return false;
        }
    }
    return true;
}
int main()
{
    int n;
    vector<int> v, u;
    // int a[] = {1, 5, 1, 4, 3, 2, 6};
    // int b[] = {6, 5, 4, 3, 2, 1, 1};
    // v.assign(a, a + 7);
    // u.assign(b, b + 7);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
        u.push_back(t);
    }
    //sort(u); //u是排好序的
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < u.size(); i++)
    // {
    //     cout << u[i] << " ";
    // }
    if (test(v, u))
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "OBS" << endl;
    }
}
/*
排序测试（2） 实时评测
 2020-09-09 18:00
 1000 ms
 32 MB
 乔海燕 (qiaohy@mail.sysu.edu.cn)
任务
测试给定的排序函数是否正确

//sort the vector in descending order 
void sort(vector<int> &v);
输入
第一行是一个表示需要排序的正整数个数n, 接下来是n个需要排序的整数，整数之间用空格分隔

输出
如果排序正确，则打印"OK", 否则打印“OBS”。输出占一行。
*/