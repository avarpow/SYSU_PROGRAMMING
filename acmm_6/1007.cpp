/*
http://soj.acmm.club/show_problem.php?pid=1006&cid=2828
*/
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<deque>
using namespace std;
int a[500004],b[500004],c[500004];
deque<int> d;
int main(){
    int n;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d", &a[i]);
    }
    sort(a, a + n);

    if(n==1||n==0){
        printf("0\n");
    }
    else if(n%2==0){
        for (int i = 0; i < n/2;i++){
            ans = ans - 2 * a[i];
        }
        for (int i = n / 2; i < n;i++){
            ans = ans + 2 * a[i];
        }
        ans = ans - a[n / 2];
        ans = ans + a[n / 2 - 1];
    }
    else{
        long long maxans = 0;
        for (int i = 0; i <= n / 2;i++){
            ans = ans - 2 * a[i];
        }
        for (int i = n / 2 + 1; i < n;i++){
            ans = ans + 2 * a[i];
        }
        ans += (a[n / 2] + a[n / 2 - 1]);
        if(ans>maxans)
            maxans = ans;


        ans = 0;
        for (int i = 0; i < n / 2;i++){
            ans = ans - 2 * a[i];
        }
        for (int i = n / 2 ; i < n;i++){
            ans = ans + 2 * a[i];
        }
        ans -= (a[n / 2] + a[n / 2 + 1]);
        if(ans>maxans)
            maxans = ans;
        ans = maxans;
    }
    printf("%lld\n", ans);
    return 0;
}