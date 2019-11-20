/*
http://soj.acmm.club/show_problem.php?pid=1004&cid=2826
*/
#include <bits/stdc++.h>
using namespace std;
int m[120][120]={0};
int vis[120][120] = {0};
int dis2[4]={0, 0, 1, -1};
int dis[4]={1, -1, 0, 0};
int c, r;
int sum = 0;
int ans = 0;
struct point
{
    int x, y;
};
stack<point> ans_t;
void dfs(int step){
    //printf("step:%d  ans:%d\n", step, ans);
    point t = ans_t.top();
    for (int k = 0; k < 4;k++){
        point t_t;
        t_t.x = t.x + dis[k];
        t_t.y = t.y + dis2[k];
        if(vis[t_t.x][t_t.y]==0 && m[t.x][t.y]>m[t_t.x][t_t.y]){
            ans_t.push(t_t);
            vis[t_t.x][t_t.y] = 1;
            sum++;
            if(sum>ans)
                ans = sum;
            dfs(step + 1);
            ans_t.pop();
            vis[t_t.x][t_t.y] = 0;
            sum--;
        }
    }
}
int main(){
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r;i++){
        for (int j = 1; j <= c;j++){
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i <= r + 1;i++){
        for (int j = 0; j <= c + 1;j++){
            if(i==0||i==r+1||j==0||j==c+1){
                m[i][j] = -1999999999;
                vis[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= r;i++){
        for (int j = 1; j <= c;j++){
            if (m[i][j] >= m[i - 1][j] && m[i][j] >= m[i][j - 1] && m[i][j] >= m[i + 1][j] && m[i][j] >= m[i][j + 1] && vis[i][j] == 0)
            {
                sum ++;
                vis[i][j] = 1;
                point t;
                t.x = i;
                t.y = j;
                ans_t.push(t);
                dfs(0);
                vis[i][j] = 0;
                ans_t.pop();
                sum--;
            }
        }
    }
    printf("%d", ans);
    return 0;
}