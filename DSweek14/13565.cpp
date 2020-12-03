#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> f;
struct edge{
    int wei,a,b;
    friend bool operator < (edge a,edge b){
    return a.wei>b.wei;
    }
};
int getf(int k)
{
    if (f[k] != k)
    {
        f[k] = getf(f[k]);
    }
    return f[k];
}
void add(int a, int b)
{
    int fa = getf(a);
    int fb = getf(b);
    if (fa != fb)
    {
        f[fb] = fa;
    }
}
void solve(int p, int n)
{
    f.resize(p + 1);
    for (int i = 0; i <= p; i++)
    {
        f[i] = i;
    }
    priority_queue<edge> q;
    for (int i = 0; i < n; i++)
    {
        edge t;
        cin >> t.a >> t.b >> t.wei;
        q.push(t);
    }
    int weight_sum = 0;
    while (!q.empty())
    {
        edge t = q.top();
        q.pop();
        int fa = getf(t.a);
        int fb = getf(t.b);
        if (getf(t.a) != getf(t.b))
        {
            add(fa,fb);
            //cout<<"join "<<fa<<"  "<<fb<<" wei "<<t.wei<<endl;
            weight_sum+=t.wei;
        }
    }
    cout<<weight_sum<<endl;
}
int main()
{
    int p;
    cin >> p;
    while (p != 0)
    {
        int n;
        cin >> n;
        solve(p, n);
        cin >> p;
    }
    return 0;
}
/*
Networking 定时评测
 2020-12-08 22:15
 1000 ms
 32 MB
 乔海燕 (qiaohy@mail.sysu.edu.cn)
题目描述
现在，你被委托在一个广阔区域里面为某些确定的节点设计连接网络。首先，你会给定在区域里面的一系列节点，和连接这些节点的一组线路。对于每条可能使用的线路，你能得到铺设该线路所需要的线缆长度。需要注意的是，在两个给定的节点之间可能存在许多路径。另外，假设给定的线路必定会连接（直接或间接）该区域里面的2个节点。

你的任务是为该区域设计一个网络，使得该区域中的任意2个节点之间都存在（直接或间接的）连接（也就是说，所有给定的节点之间都是连通的，但不一定存在直接相连的线路），同时，使得铺设该网络的线缆总长度最小。

输入格式
输入由多个测试构成。每个测试定义一个要求的网络。每个测试的第一个包含2个整数：第一个整数P给定区域内节点的数目，第二个整数R给出了线路的数目。接下来的R行，给出了两个节点之间的线路，每行包含3个整数：前2个数字表示线路连接的节点，第三个整数表示铺设该线路需要的线缆长度。每个整数之间用一个空格隔开。只给出一个整数P=0的测试表示输入结束。每个测试之间用一个空行隔开。

输入的最大的节点数目是50。给定的线路的最大长度是100。但是，可能存在的线路数目是无限的。给定的节点由整数1~P来标识（包含P）。需要注意，节点i和j之间的线路可能由i到j的线路来表示，也可能由j到i的线路来表示。

输出格式
对于每一个测试，在单独的一行输出一个数字，表示为铺设整个网络所需要的线缆总长度。

样例输入
1 0

2 3
1 2 37
2 1 17
1 2 68

3 7
1 2 19
2 3 11
3 1 7
1 3 5
2 3 89
3 1 91
1 2 32

5 7
1 2 5
2 3 7
2 4 8
4 5 11
3 5 10
1 5 6
4 2 12

0
样例输出
0
17
16
26
*/