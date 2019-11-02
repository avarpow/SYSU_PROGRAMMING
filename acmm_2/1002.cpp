/*
http://soj.acmm.club/show_problem.php?pid=1002&cid=2824
*/
#include<bits/stdc++.h>
using namespace std;
int a[110000];
int b[110000];
int vis[110000] = {0};
int n;
int find(int key){
    int l = 0, r = n-1;
    while(r-l>=1){
        if(b[(r+l)/2]==key){
            return (r + l) / 2;
        }
        else if(b[(r+l)/2]>key){
            r = (r + l) / 2;
        }
        else {
            l = (r + l) / 2 + 1;
        }
    }
    return r;
}
int main(){
    int ans = 0;
    //freopen("in.txt", "r", stdin);
    scanf("%d",&n);
    for (int i = 0; i < n;i++){
        scanf("%d", &a[i]);
    }
    memcpy(b, a, sizeof(a));
    sort(b, b + n);
    for (int i = 0;i<n;i++){
        if(vis[i]==0){
            int t=a[i];
            vis[i] = 1;
            while(t!=b[i]){
                ans++;
                int index = find(t);
                vis[index] = 1;
                t = a[index];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}