/*
http://soj.acmm.club/show_problem.php?pid=1005&cid=2828
*/
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
vector<int> dao[2];
int cmp(int a,int b){
    return b < a;
}
int main(){
    int n, H;
    scanf("%d%d", &n, &H);
    for (int i = 0; i < n;i++){
        int t, y;
        scanf("%d%d", &t, &y);
        dao[0].push_back(t);
        dao[1].push_back(y);
    }
    sort(dao[0].begin(), dao[0].end(), cmp);
    sort(dao[1].begin(), dao[1].end(), cmp);
    int ans = 0,mb=0;
    while(H>0){
        if(mb<dao[1].size() && dao[1][mb]>dao[0][0]){
            H -= dao[1][mb++];
            ans++;
        }
        else{
            H -= dao[0][0];
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}