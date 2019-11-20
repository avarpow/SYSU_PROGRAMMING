/*
http://soj.acmm.club/show_problem.php?pid=1000&cid=2826
*/
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100],sum=0;
int tong[15] = {0};
int flag = 0;
//int countt = 0;
vector<int> factor[400];
void dfs(int step){
   // printf("step:%d  count:%d flag:%d\n", step,countt,flag);
   // countt++;
    if(step==n || flag==1){
        flag = 1;
        return;
    }
    else
    {
        for (int i = 0; i < factor[sum].size();i++)
        {
            int t = factor[sum][i];
            if(tong[t]>0){
                tong[t]--;
                sum = sum - t;
                dfs(step + 1);
                sum = sum + t;
                tong[t]++;
            }
        }
    }
    
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d", &a[i]);
        tong[a[i]]++;
        sum += a[i];
    }
    for (int i = 1; i < 400;i++){
        int now = i;
        int j = 2;
        factor[i].push_back(1);
        while(j<=13){
            if(now%j==0){
                factor[i].push_back(j);
            }
            j++;
        }
        factor[i].push_back(i);
    }
    dfs(0);
    printf("%s\n", flag ? "Ye5" : "N0");
    return 0;
}