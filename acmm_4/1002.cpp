/*
http://soj.acmm.club/show_problem.php?pid=1002&cid=2826
*/
#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x, y,step;
};
queue<point> s;
int dis[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dis2[8] = {2, -2, 1, -1, 2, -2, 1, -1};
int m[500][500];
int main(){
    int row, col;
    point t;
    t.step = 0;
    scanf("%d%d%d%d", &row, &col, &t.x, &t.y);
    memset(m, -1, sizeof(m));
    m[t.x][t.y] = 0;
    s.push(t);
    while(!s.empty()){
        point t = s.front();
        s.pop();
        for (int i = 0; i < 8;i++){
            point op;
            op.x = t.x + dis[i];
            op.y = t.y + dis2[i];
            op.step = t.step + 1;
            if(op.x>=1 && op.x<=row && op.y>=1 && op.y<=col && m[op.x][op.y]==-1){
                m[op.x][op.y] = op.step;
                s.push(op);
            }
        }
    }
    for (int i = 1; i <= row;i++){
        for (int j = 1; j <= col;j++){
            printf("%-5d", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}