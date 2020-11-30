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
        ret.weight[b][a]=wei;
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
    priority_queue<pair<int,int>> edges;
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