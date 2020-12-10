#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void dfs(int k,vector<int> &vis,vector<vector<int>> &g){
    for(int i=0;i<g[k].size();i++){
        if(vis[g[k][i]]==0){
            vis[g[k][i]]=1;
            dfs(g[k][i],vis,g);
        }
    }
}
void findart(int v,int &count,int &ret,vector<int> &vis,vector<int> &num,vector<int> &low,vector<int> &parent,vector<int> &atvis,vector<vector<int>> &g){
    vis[v]=1;
    low[v]=num[v]=count++;
    for(int i=0;i<g[v].size();i++){
        int now=g[v][i];
        if(vis[now]==0){
            vis[now]=1;
            parent[now]=v;
            findart(now,count,ret,vis,num,low,parent,atvis,g);
            if(low[now]>=num[v] && v!=1 && atvis[v]==0){
                atvis[v]++;
                ret++;
                //cout<<"find AT point "<<v<<endl;
            }
            low[v]=min(low[v],low[now]);
        }
        else if(parent[v]!=now){//回边
            low[v]=min(low[v],num[now]);
        }
    }
}
int findat(int n,vector<vector<int>> &g){
    vector<int> vis;
    vis.resize(n+1,0);
    int ret=0;
    //1是at？
    vis[1]=1;
    int con=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            con++;
            dfs(i,vis,g);
        }
    }
    if(con>1){
        ret++;
    }
    //剩余
    for(int i=0;i<=n;i++){
        vis[i]=0;
    }
    vector<int> num,low,parent,atvis;
    num.resize(n+1,0);
    low.resize(n+1,0);
    atvis.resize(n+1,0);
    parent.resize(n+1,0);
    int count=1;
    findart(1,count,ret,vis,num,low,parent,atvis,g);
    
    // cout<<"num"<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<num[i]<<" ";
    // }
    // cout<<endl;

    // cout<<"low"<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<low[i]<<" ";
    // }
    // cout<<endl;
    
    // cout<<"parent"<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<parent[i]<<" ";
    // }
    // cout<<endl;
    return ret;
}
void solve(){
    vector<vector<int>> g;
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans=findat(n,g);
    cout<<"Number of AT:"<<ans<<endl;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        solve();
    }
    return 0;
}
/*
原未通过，是查找at时没有判重
*/