/*
http://soj.acmm.club/show_problem.php?pid=1001&cid=2827
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> g[100006];
int sorted[100006];
int main(){
    int n, m, a, b,q,u,k;
    while(scanf("%d%d%d",&n,&m,&q)!=EOF){
        for (int i = 0; i <= n;i++){
            g[i].clear();
            sorted[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            if(a!=b){
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
        for (int i = 0; i < q;i++){
            scanf("%d%d", &u, &k);
            if(sorted[u]!=1){
                sorted[u] = 1;
                sort(g[u].begin(), g[u].end());
                vector<int>::iterator it = unique(g[u].begin(),g[u].end());
                g[u].erase(it,g[u].end());
            }
            printf("%d \n", k<=g[u].size()?g[u][k-1]:-1);
        }
    }
    return 0;
}