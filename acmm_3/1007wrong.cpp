/*
http://soj.acmm.club/show_problem.php?cid=2825&pid=1006
*/
// 为什么错了呢
// 这里是直接把位置的捕食关系设置为3和4
// 但是可能出现
// A类 a c f
// B类 b
// C类 d
// 如果输入为
// 2 a b
// 2 d c
// 2 d f
// 则1 a c 时候，guanxi[a]=3 guanxi[c]=4按照以下方法算是错误的.
        
#include <bits/stdc++.h>
using namespace std;
int guanxi[105]={0},fa[105]={0};//0 5>4>3>5
int find(int k){
    if(fa[k]==k)
        return k;
    else{
        fa[k] = find(fa[k]);
    }
    return fa[k];
}
int make(int i,int j){
    fa[j] = find(i);
}
int check(int i, int j){
    if(i-j==1 ||i-j==-2)
        return 1;
    else
        return 0;
}
int main(){
    int n, k,op,a,b,ans=0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n;i++){
        fa[i] = i;
    }
    for (int i = 0; i < k;i++){
        scanf("%d %d %d", &op,&a,&b);
        if(a>n||b>n){
            ans++;
        }
        else if(op==1){
            if(guanxi[fa[a]]==guanxi[fa[b]]){
                make(a, b);
                
            }
            else{
                ans++;
            }
        }
        else if(op==2){
            if(a==b){
                ans++;
            }
            else if(guanxi[find(a)]==0 && guanxi[find(b)]==0){
                    guanxi[find(a)] = 4;
                    guanxi[find(b)] = 3;
            }
            else if(guanxi[find(a)]!=0 && guanxi[find(b)]!=0){
                if(!check(guanxi[find(a)],guanxi[find(b)])){
                    ans++;
                }
            }
            else{
                if(guanxi[find(a)]==0){
                    guanxi[find(a)] = guanxi[find(b)] + 1;
                    if(guanxi[find(a)]==6)
                        guanxi[find(a)] = 3;
                }
                else if(guanxi[find(b)]==0){
                    guanxi[find(b)] = guanxi[find(a)] - 1;
                    if(guanxi[find(b)]==2)
                        guanxi[find(b)] = 5;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}