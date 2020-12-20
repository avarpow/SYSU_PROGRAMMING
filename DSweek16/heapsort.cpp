#include <iostream>
#include <vector>
using namespace std;
/*转换关系
现在 i  原来则为 i+1
现在的 父节点 (i+1)/2 - 1
原来的 父节点 (i+1)/2
现在的两个子节点 2i+1 2i+2

*/
// //Assuming a max heap
// void push_heap(vector<T> &v, size_t i)
// Pre: v[0..i-1] is a heap
// Post: perculate up v[i] and make v[0..i] a heap, while v[i+1…] unchanged.
void push_heap(vector<int> &v, size_t i)
{
    int now = i;
    while (now + 1 > 1)
    {
        if (v[now] > v[(now + 1) / 2 - 1])
        {
            swap(v[now], v[(now + 1) / 2 - 1]);
            now = (now + 1) / 2 - 1;
        }
        else
        {
            break;
        }
    }
    return;
}
// //Assuming a max heap
// Void pop_heap(vector<T>&v, size_t i)
// Pre: v[0..i] is a heap
// Post: swap v[0] and v[i] and make v[0..i-1] into a heap, while v[i+1...] unchanged.
void pop_heap(vector<int> &v, size_t i)
{
    swap(v[0], v[i]);
    int now = 0;
    while (2 * now + 1 < i)
    {
        if (2 * now + 2 < i)
        {
            if (v[2 * now + 1] > v[now * 2 + 2])
            {
                if (v[2 * now + 1] > v[now])
                {
                    swap(v[2 * now + 1], v[now]);
                    now = 2 * now + 1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (v[2 * now + 2] > v[now])
                {
                    swap(v[2 * now + 2], v[now]);
                    now = 2 * now + 2;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            if (v[2 * now + 1] > v[now])
            {
                swap(v[2 * now + 1], v[now]);
                now = 2 * now + 1;
            }
            else
            {
                break;
            }
        }
    }
}
void heapinsert(vector<int> &s, int val)
{
    s.push_back(val);
    int now = s.size() - 1;
    while (now > 1)
    {
        if (s[now] < s[now / 2])
        {
            swap(s[now], s[now / 2]);
            now = now / 2;
        }
        else
        {
            break;
        }
    }
}
void heapinsert(vector<int> &s, size_t i)
{
    int now = i;
    while (now + 1 > 1)
    {
        if (s[now] < s[(now + 1) / 2 - 1])
        {
            swap(s[now + 1], s[(now + 1) / 2 - 1]);
            now = (now + 1) / 2 - 1;
        }
        else
        {
            break;
        }
    }
}

void mpop_heap(vector<int> &s, size_t i)
{
    int len = i - 1;
    if (len <= 0)
        return;
    //int ret=s[0];
    s[0] = s[len];
    int now = 1;
    while (now * 2 <= len)
    {
        if (now * 2 + 1 <= len)
        { //两个比较
            if (s[now * 2] < s[now * 2 + 1])
            {
                if (s[now] > s[now * 2])
                { //交换
                    swap(s[now], s[now * 2]);
                    now = now * 2;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (s[now] > s[now * 2 + 1])
                { //交换
                    swap(s[now], s[now * 2 + 1]);
                    now = now * 2 + 1;
                }
                else
                {
                    break;
                }
            }
        }
        else
        { //一个比较
            if (s[now] > s[now * 2])
            { //交换
                swap(s[now], s[now * 2]);
                now = now * 2;
            }
            else
            {
                break;
            }
        }
    }
    s.pop_back();
    return;
}
int heapdeletetop(vector<int> &s)
{
    int len = s.size() - 1;
    if (len <= 0)
        return -1;
    int ret = s[1];
    s[1] = s[len];
    int now = 1;
    while (now * 2 <= len)
    {
        if (now * 2 + 1 <= len)
        { //两个比较
            if (s[now * 2] < s[now * 2 + 1])
            {
                if (s[now] > s[now * 2])
                { //交换
                    swap(s[now], s[now * 2]);
                    now = now * 2;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (s[now] > s[now * 2 + 1])
                { //交换
                    swap(s[now], s[now * 2 + 1]);
                    now = now * 2 + 1;
                }
                else
                {
                    break;
                }
            }
        }
        else
        { //一个比较
            if (s[now] > s[now * 2])
            { //交换
                swap(s[now], s[now * 2]);
                now = now * 2;
            }
            else
            {
                break;
            }
        }
    }
    s.pop_back();
    return ret;
}
vector<int> heapsort(vector<int> &s)
{
    vector<int> ret;
    vector<int> temp;
    int len = s.size();
    ret.resize(1);
    temp.resize(1);
    for (auto &i : s)
    {
        heapinsert(temp, i);
    }
    for (int i = 0; i < len; i++)
    {
        ret.push_back(heapdeletetop(temp));
    }
    return ret;
}
void heapsort_v2(vector<int> &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        push_heap(s, i);
    }
    for (auto &i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    for(int i=s.size()-1;i>=0;i--){
        pop_heap(s, i);
    }
    return;
}
int main()
{
    vector<int> s = {1, 5, 9, 6, 3, 8, 5, 7, 6, 2, 4};
    heapsort_v2(s);
    for (auto &i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}