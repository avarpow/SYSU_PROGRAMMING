/*
http://soj.acmm.club/show_problem.php?pid=1003&cid=2826
*/
#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x, y;
};
queue<point> s;
int m[50][50];
int n;
int main(){
    int row, col;
    point t;
    t.x = 0;
    t.y = 0;
    int te;
    scanf("%d", &n);
    
    for (int i = 0; i <= n+1;i++){
        for (int j = 0; j <= n+1;j++){
            if(i==0||i==n+1||j==0||j==n+1){
                m[i][j] = 2;
                continue;
            }
            scanf("%d", &te);
            if(te==0)
                te = 2;
            m[i][j] = te;
        }
    }
    s.push(t);
    while(!s.empty()){
        point t = s.front();
        s.pop();
        for (int i = 0; i < 4;i++){
            point op;
            op.x = t.x + dis[i];
            op.y = t.y + dis2[i];
            if(op.x>=0 && op.x<=n+1 && op.y>=0 && op.y<=n+1 && m[op.x][op.y]==2){
                m[op.x][op.y] = 0;
                s.push(op);
            }
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            printf("%d%s", m[i][j],j==n?"":" ");
        }
        printf("\n");
    }
    return 0;
}