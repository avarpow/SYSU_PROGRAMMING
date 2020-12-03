#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void dfs(int k, vector<vector<int>> &g, vector<int> &vis)
{
    for (int i = 0; i < g[k].size(); i++)
    {
        if (vis[g[k][i]] == 0)
        {
            vis[g[k][i]] = 1;
            dfs(g[k][i], g, vis);
        }
    }
}
void solve()
{
    vector<vector<int>> g;
    vector<int> vis;
    int n, m;
    cin >> n >> m;
    g.resize(n, vector<int>());
    vis.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a = a - 1, b = b - 1;
        g[b].push_back(a);
        g[a].push_back(b);
    }
    int ret = 0;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            s.push(i);
            vis[i]=1;
            ret++;
            while (!s.empty())
            {
                int now = s.top();
                s.pop();
                //cout<<now<<" pop"<<endl;
                for (int i = 0; i < g[now].size(); i++)
                {
                    if (vis[g[now][i]] == 0)
                    {
                        vis[g[now][i]] = 1;
                        s.push(g[now][i]);
                    }
                }
            }
        }
    }
    if (ret == 1)
    {
        cout << "YES, 1 component." << endl;
    }
    else
    {
        cout << "NO, " << ret << " components." << endl;
    }
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

/*
DFS (Non-Recursive) 定时评测
 2020-12-08 22:17
 1000 ms
 32 MB
 乔海燕 (qiaohy@mail.sysu.edu.cn)
Problem
Given an undirected graph, compute the number of components.

Note: You must use recursion
Input
The first line is the number of test cases.

For every test case, the first line is the number of node n, meaning nodes are 1,2,…,n.

The next line is the number of edges m, then m lines are followed, where each line is in the form of u v, meaning (u,v) is an undirected edge.

Output
For each test case, print whether the graph is connected and the number of components:

 YES, 1 component.
 NO, 2 components.
Sample Input
2

3
1
3 2

3
3
2 1
3 1
3 2
Sample Output
NO, 2 components.
YES, 1 component.
Note
Don't write only the main function.
Don't use global variables.
*/