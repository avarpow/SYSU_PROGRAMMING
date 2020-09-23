#include <iostream>
#include <vector>
using namespace std;
void mergesort(int left, int right, vector<int> &v, vector<int> &temp)
{
    if (left >= right)
        return;
    else
    {
        int mid = (left + right) / 2;
        mergesort(left, mid, v, temp);
        mergesort(mid + 1, right, v, temp);
        int l = left, m = mid + 1, c = left;
        while (l <= mid && m <= right)
        {
            if (v[l] <= v[m])
                temp[c++] = v[m++];
            else
                temp[c++] = v[l++];
        }
        while (l <= mid)
            temp[c++] = v[l++];
        while (m <= right)
            temp[c++] = v[m++];
        for (int i = left; i <= right; i++)
        {
            v[i] = temp[i];
        }
    }
}
void sort(vector<int> &v)
{
    vector<int> temp;
    temp.resize(v.size());
    mergesort(0, v.size() - 1, v, temp);
    return;
}
int select_kth_biggest(vector<int> v, size_t k)
{
    if (k <= 0 || k > v.size())
    {
        return -1;
    }
    else
    {
        sort(v);
        return v[k - 1];
    }
}

void test()
{
    int a[10] = {2, 4, 3, 5, 1, 7, 6, 8, 9, 0};
    vector<int> t(a, a + 10);
    cout << select_kth_biggest(t, 3);
    return;
}
int main()
{
    test();
    return 0;
}
/*
K-th Biggest Element （Simple version） 实时评测
 2020-09-06 18:00
 1000 ms
 32 MB
 乔海燕 (qiaohy@mail.sysu.edu.cn)
实现下列返回一个向量中第k个最大元素的函数，1<= k <= n.

int select_kth_biggest(vector<int> v, size_t k);
*/