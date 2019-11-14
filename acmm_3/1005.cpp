/*
http://soj.acmm.club/show_problem.php?pid=1005&cid=2825
*/
#include <bits/stdc++.h>
using namespace std;
int r[100005];
int fa(int now){
    if(r[now]==now)
        return now;
    r[now] = fa(r[now]);
    return r[now];
}
void make(int a,int b){
    r[fa(b)] = fa(a);
}
int main(){
    int m, n,a,b,t;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++){
        r[i] = i;
    }
    for (int i = 0; i < m;i++){
        scanf("%d%d", &a, &b);
        make(a, b);
    }
    scanf("%d", &t);
    for (int i = 0; i < t;i++){
        scanf("%d%d", &a, &b);
        printf("%s\n",fa(a)==fa(b)?"Yes":"No");
    }
    return 0;
}