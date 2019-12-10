/*
http://soj.acmm.club/show_problem.php?pid=1002&cid=2828
*/
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
#define N 1005
int g[N][N]={0};
int vis[N] = {0};
int tonext[N] = {0};
int pre[N] = {0};
int n, m;
int match(int k){
    for (int i = 1;i<=m; i++)
    {
        if(vis[i]==0 && g[k][i]==1){
            vis[i] = 1;
            if(pre[i]==0 || match(pre[i])){
                pre[i] = k;
                tonext[k] = i;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        g[i][a] = 1;
        g[i][b] = 1;
        //if (x>=1&&y>=1&&x<=n&&y<=m)
        //g[x][y]=true;
    }
    int ans = 0;
    for (int i = 1; i <= m;i++){
        memset(vis, 0, sizeof(vis));
        if(match(i)){
            ans++;
        }
    }
   // printf("%d\n", ans);
     if(ans==n){
         printf("YES");
     }
     else{
         printf("NO");
     }
    return 0;
}