/*
http://soj.acmm.club/show_problem.php?pid=1003&cid=2826
*/
#include <bits/stdc++.h>
using namespace std;
long long ji[35][35]={0};
int max_index[35][35] = {0};
long long ans = 0;
int a[100];
int n;
int count_t = 0;
long long dfs(int left,int right){
    if(ji[left][right]!=0)
        return ji[left][right];
    else{
        if(right-left==1){
            ji[left][right] = a[left] + a[left + 1];
            max_index[left][right] = right;
        }
        else if(right==left){
            ji[left][right] = a[left];
            max_index[left][right] = left;
        }
        else{
            long long maxx = 0;
            for (int i = left+1; i <= right;i++){
                long long t = dfs(left, i - 1) * dfs(i + 1, right)+a[i];
                if(t>maxx){
                    max_index[left][right] = i;
                    maxx = t;
                }
            }
            ji[left][right] = maxx;
        }
        return ji[left][right];
    }
}
void p(int left,int right){
    if(right-left>=2){
        printf("%d%s",max_index[left][right]+1,(++count_t)==n?"":" ");
        p(left, max_index[left][right]-1);
        p(max_index[left][right] + 1, right);
    }
    else if(right-left==1){
        printf("%d%s", left + 1, (++count_t) == n ? "" : " ");
        printf("%d%s", right + 1, (++count_t) == n ? "" : " ");
    }
    else if(right==left){
        printf("%d%s", left + 1, (++count_t) == n ? "" : " ");
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1;i++){
        for (int j = i + 1; j <= n - 1;j++){
            dfs(i, j);
        }
    }
    printf("%lld\n", dfs(0, n - 1));
    p(0,n-1);
    printf("\n");
    return 0;
}