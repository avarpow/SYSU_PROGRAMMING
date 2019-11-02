/*
http://soj.acmm.club/show_problem.php?pid=1001&cid=2823
*/
#include<stdio.h>
int main()
{
    int a[3000], n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n;i++){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 2*n;i+=2){
        int k = a[i];
        int j;
        for (j = i + 1; a[j]!=k;j++);
        for (int k = j; k > i + 1;k--){
            ans++;
            a[k] = a[k - 1];
        }
    }
    printf("%d\n", ans);
    return 0;
}