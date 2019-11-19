/*
http://soj.acmm.club/show_problem.php?pid=1000&cid=2826
*/
#include <bits/stdc++.h>
using namespace std;
char s[23][15];
int tu[20][20];
char nong[3000];
int slen[20];
int vis[23] = {0};
char max_long[300];
int ans = 0;
int now_len = 0;
stack<int> ans_t;
int last;
int n;
int wadd(char *nong,char *s){
    int len_nong = strlen(nong);
    int len_s = strlen(s);
    int result = 1;
    while( result<len_nong && result<len_s ){
        int flag = 0;
        for (int i = 0; i < result;i++){
            if(nong[len_nong-1-i]!=s[result-i-1])
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
            return result;
        result++;
    }
    return 0;
}
void dfs(int step){
    if(step==2*n)
        return;
    for (int i = 0; i < 2*n;i++){
        if(vis[i]==0){
            int t = tu[ans_t.top()][i];
            if(t>0){
                vis[i] = 1;
                ans_t.push(i);
                now_len += (slen[i] - t);
                if(now_len>ans){
                    ans = now_len;
                    //strcpy(max_long,nong);
                }
                dfs(step + 1);
                now_len -= (slen[i] - t);
                ans_t.pop();
                vis[i] = 0;
            }
        }
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%s", s[i]);
        strcpy(s[i+n], s[i]);
    }
    char a[20];
    scanf("%s", a);
    for (int i = 0; i < 2*n;i++){
        for (int j = 0; j < 2*n;j++){
            tu[i][j] = wadd(s[i], s[j]);
        }
    }
    for (int i = 0; i < 2*n;i++){
        slen[i] = strlen(s[i]);
    }
    for (int i = 0; i < 2 * n; i++)
    {
        if (s[i][0] == a[0] && vis[i]==0)
        {
            vis[i] = 1;
            ans_t.push(i);
            now_len += slen[i];
            if(now_len>ans){
                ans = now_len;
                //strcpy(max_long,nong);
            }
            dfs(1);
            now_len -= slen[i];
            ans_t.pop();
            vis[i] = 0;
        }
    }
    printf("%d\n", ans);
   //printf("%s\n", max_long);
    return 0;
}