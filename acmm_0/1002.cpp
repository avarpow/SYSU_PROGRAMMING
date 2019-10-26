/*
http://soj.acmm.club/show_problem.php?pid=22434
*/
#include<stdio.h>
using namespace std;
int main()
{
    int n,k,t,mod=998244353;
    long long ans = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        ans = (i * (ans % mod) ) + (i % 2 ?  998244352: 1);
        ans = ans % mod;
    }
    printf("%d\n", ans);
        return 0;
}