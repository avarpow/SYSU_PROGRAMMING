/*
http://soj.acmm.club/show_problem.php?pid=1000&cid=2823
*/
#include<stdio.h>
int main()
{
    int a[10], k, ans = 0;
    for (int i = 0; i < 10;i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);
    for (int i = 0; i < 10;i++){
        if(a[i]-30<=k){
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}