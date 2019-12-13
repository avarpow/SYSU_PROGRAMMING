/*
http://soj.acmm.club/show_problem.php?pid=1004&cid=2829
*/
#include<stdio.h>
using namespace std;
int a[205],dp[205];
int abs(int i){
    return i > 0 ? i  :  - i;
}
int main()
{
    int n,k;
    int max = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n;i++){
        scanf("%d", &a[i]);
    }
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int mincost = 1999999999;
        for (int j = 1; j <= k;j++){
            if(i-j>=0){
                if(abs(a[i-j]-a[i])+dp[i-j]<=mincost){
                    mincost = abs(a[i - j] - a[i]) + dp[i - j];
                }
            }
            else{
                break;
            }
        }
        dp[i] = mincost;
    }
    printf("%d\n", dp[n - 1]);
    return 0;
}