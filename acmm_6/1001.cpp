/*
http://soj.acmm.club/show_problem.php?pid=1001&cid=2828
*/
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
vector<int> xuan[5]; //00 01 10 11
int ans = 0;
int cmp(int a,int b){
    return a > b;
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0;i<n;i++){
        int t, an,k;
        scanf("%d%d", &t, &an);
        if(t==1){
            k = 1;
        }
        else if(t==11){
            k = 3;
        }
        else if(t==10){
            k = 2;
        }
        else if(t==0){
            k = 0;
        }
        xuan[k].push_back(an);
    }
    for (int i = 0; i < 4;i++){
        sort(xuan[i].begin(), xuan[i].end(), cmp);
    }
    int len11 = xuan[3].size();
    for (int i = 0; i < len11;i++){
        ans += xuan[3][i];
    }
    int lenm = min(xuan[1].size(), xuan[2].size());
    for (int i = 0; i < lenm;i++){
        ans += xuan[1][i];
        ans += xuan[2][i];
    }
    for (int i = lenm; i < xuan[1].size(); i++)
    {
        xuan[4].push_back(xuan[1][i]);
    }
    for (int i = lenm; i < xuan[2].size();i++){
        xuan[4].push_back(xuan[2][i]);
    }
    for (int i = 0; i < xuan[0].size();i++){
        xuan[4].push_back(xuan[0][i]);
    }
    sort(xuan[4].begin(), xuan[4].end(), cmp);
    for (int i = 0; i < len11 && i<xuan[4].size();i++){
        ans += xuan[4][i];
    }
        printf("%d", ans);
    return 0;
}