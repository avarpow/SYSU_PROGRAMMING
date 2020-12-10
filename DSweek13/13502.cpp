#include <iostream>
#include <vector>
#include <queue>
#define Vertex int
using namespace std;
class Graph
{
public:
    int vertexCount;
    vector<vector<int>> weight;
};
Graph mkGraph()
{
    Graph ret;
    int n,m;
    cin>>n;
    cin>>m;
    ret.vertexCount=n;
    ret.weight.resize(n+1);
    for(int i=0;i<=n;i++){
        ret.weight[i].resize(n+1,0x3fffffff);
    }
    for(int i=0;i<=n;i++){
        ret.weight[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b,wei;
        cin>>a>>b>>wei;
        ret.weight[a][b]=wei;
        //ret.weight[b][a]=wei;
    }
    return ret;
}
vector<int> dijkstra(Graph g, Vertex source)
{
    vector<int> ok;
    vector<int> ret;
    ret.resize(g.vertexCount+1);
    ok.resize(g.vertexCount+1,0);
    for(int i=0;i<=g.vertexCount;i++){
        ret[i]=0x3fffffff;
    }
    ret[source]=0;
    int now_vertex=source;
    for(int i=0;i<g.vertexCount;i++){
        for(int j=1;j<=g.vertexCount;j++){
            if(ok[j]==0 && (ret[j]<ret[now_vertex] || ok[now_vertex]==1)){
                now_vertex=j;
            }
        }
        ok[now_vertex]=1;
        //cout<<"solve now_vertex: "<<now_vertex<<endl;
        for(int j=1;j<=g.vertexCount;j++){
            if(ret[now_vertex]+g.weight[now_vertex][j]<ret[j]){
                ret[j]=ret[now_vertex]+g.weight[now_vertex][j];
            }
        }
    }
    return ret;
}
void print(vector<int> d, Vertex source)
{
    for(int i=1;i<d.size();i++){
        if(d[i]!=0x3fffffff){
            cout<<source<<"-"<<i<<":"<<d[i]<<endl;
        }
    }
    
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Graph t = mkGraph();
        int sourse;
        cin >> sourse;
        vector<int> ans = dijkstra(t, sourse);
        print(ans, sourse);
    }
    return 0;
}
/*
Shortest Path (Dijkstra's Algorithm) 定时评测
 2020-12-03 22:48
 1000 ms
 32 MB
 乔海燕 (qiaohy@mail.sysu.edu.cn)
Problem
Given a directed graph, compute all the shortest paths from the source to other vertices.

Input
The first line is the number of test cases.

For every test case, the first line is the number of node n, meaning nodes are 1,2,…,n.

The next line is the number of edges m, then m lines are followed, where each line is in the form of u v w, meaning (u,v) is an edge and it has weight w (>0).

The last line is the source vertex.

Output
For each test case, print all the shortest paths from the source s to other vertices (if the shortest path is finite) in the order of vertices in the following form （no spaces between）:

s-1:d1

s-2:d2

…

Sample Input
2
2
1
1 2 5
1
5
6
1 2 4
1 3 6
2 3 1
4 5 1
3 1 1
5 4 2
2
Sample Output
1-1:0
1-2:5
2-1:2
2-2:0
2-3:1
Hint
Suggested solution: again, write a few functions.

A function which constructs the graph:
Graph mkGraph();

A function which computes all the shortest paths, for example,
vector<int> dijkstra(Graph g, Vertex source);

A print function which prints the result as required.
void print(vector<int> d, Vertex source);
*/