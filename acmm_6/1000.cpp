/*
http://soj.acmm.club/show_problem.php?pid=1000&cid=2828
*/
#include<stdio.h>
using namespace std;
int main()
{
    int n,k,t;
    int max = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        int ans = 0;
        for (int j = 0; j < k;j++){
            scanf("%d", &t);
            ans += t * t;
        }
        if(ans>max)
            max = ans;
    }
    printf("%d\n",max);
    return 0;
}