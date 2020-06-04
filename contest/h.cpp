#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define N 100
vector<int> air[N];
vector<int> road[N];
int vis[N] = {0};
struct ss
{
    int day;
    int city;
};
queue<ss> que;
int ans = 1;
int main()
{
    int n, m, s, a, b, u, v, w;
    cin >> n >> m >> s >> a >> b;
    ss temp;
    temp.day = 0;
    temp.city = s;
    vis[s] = 1;
    que.push(temp);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        if (w == 0)
        {
            air[u].push_back(v);
            air[v].push_back(u);
        }
        else
        {
            road[u].push_back(v);
            road[v].push_back(u);
        }
        int temp = 0;
    }
    while (!que.empty())
    {
        ss temp;
        ss front = que.front();
        if (front.day < a)
        { //air
            for (int i = 0; i < air[front.city].size(); i++)
            {
                if (vis[air[front.city][i]] == 0)
                {
                    vis[air[front.city][i]] = 1;
                    ans++;
                    temp.city = air[front.city][i];
                    temp.day = front.day + 1;
                    que.push(temp);
                }
            }
        }
        if (front.day < b)
        { //road
            for (int i = 0; i < road[front.city].size(); i++)
            {
                if (vis[road[front.city][i]] == 0)
                {
                    vis[road[front.city][i]] = 1;
                    ans++;
                    temp.city = road[front.city][i];
                    temp.day = front.day + 1;
                    que.push(temp);
                }
            }
        }
        //cout << "pop the city " << que.front().city << "day " << que.front().day << endl;
        que.pop();
    }
    cout << ans << endl;
    return 0;
}