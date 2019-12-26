/*
http://soj.acmm.club/show_problem.php?pid=1004&cid=2829
*/
#include<stdio.h>
using namespace std;
int a[200055],dp[200055];
int abs(int i){
    return i > 0 ? i  :  - i;
}
inline int read(){
   int ans = 0;
   char last = ' ',ch = getchar();
   while(ch<'0'||ch>'9')  last=ch,ch=getchar();
   while(ch>='0'&&ch<='9') ans = ans*10+ch-'0',ch=getchar();
   if(last=='-') ans = -ans;
   return ans;
}

int main()
{
    int n,k;
    int max = 0;
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n;i++){
        a[i] = read();
    }
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int mincost = 1999999999;
        for (int j = 1; j <= k;j++){
            if(i-j>=0){
                int k = abs(a[i - j] - a[i]) + dp[i - j];
                if(k<=mincost){
                    mincost = k;
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