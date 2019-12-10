/*
http://soj.acmm.club/show_problem.php?pid=1000&cid=2827
*/
#include <bits/stdc++.h>
using namespace std;
struct node{
    int point,fen,pre;
};
node g[200003];
int fa(int k){
    if(g[k].pre!=-1){
        g[k].pre = fa(g[k].pre);
    }
    else{
        return k;
    }
    return g[k].pre;
}
void join(int a,int b){
    int faa = fa(a);
    int fab = fa(b);
    if(faa==fab){
        g[faa].fen++;
    }
    else{
        g[faa].pre = fab;
        g[fab].point+=g[faa].point;
        g[fab].fen+=g[faa].fen + 1;
    }
}
int main(){
    int n, m, a, b;
    while(scanf("%d%d",&n,&m)!=EOF){
        for (int i = 0; i <= n;i++){
            g[i].point = 1;
            g[i].fen = 0;
            g[i].pre = -1;
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            join(a, b);
        }
        int fen_co = 0, maxfen = 0, max_point = 0;
        for (int i = 1; i <= n;i++){
            if(g[i].pre==-1){
                fen_co++;
                if(g[i].point>=max_point){
                    max_point = g[i].point;
                }
                if(g[i].fen>=maxfen)
                    maxfen = g[i].fen;
            }
        }
        printf("%d %d %d\n", fen_co, maxfen, max_point);
    }
    return 0;
}