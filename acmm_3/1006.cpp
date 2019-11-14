/*
http://soj.acmm.club/show_problem.php?cid=2825&pid=1006
*/
#include <bits/stdc++.h>
using namespace std;
struct stone{
    int x, y;
};
stone st[1005];
double dis[1002][1002];
int vis[1005];
int fa(int i){
    if(vis[i]==i)
        return i;
    else{
        vis[i] = fa(vis[i]);
    }
    return vis[i];
}
void make(int i,int j){
    vis[fa(j)] = fa(i);
}
int main(){
    int n,a,b;
    double l = 0,r=30000,mid;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d%d", &st[i].x, &st[i].y);
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            dis[i][j] = sqrt(pow(st[i].x - st[j].x, 2) + pow(st[i].y - st[j].y, 2));
        }
    }
    while(r-l>=0.000001){
        for (int i = 1; i <= n;i++){
            vis[i] = i;
        }
        mid = (l + r) / 2;
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                if(dis[i][j]<mid){
                    make(i, j);
                }
            }
        }
        if(fa(1)==fa(n)){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    printf("%.3lf\n", mid);
    return 0;
}