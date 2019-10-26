/*
http://soj.acmm.club/show_problem.php?pid=22436
*/
#include<stdio.h>
using namespace std;
int main()
{
    int ans = 0,n;
    scanf("%d", &n);
    ans = 0;
    if(n==1 ){
        ans = 0;
    }
    else if(n==2){
        ans = 1;
    }
    else {
        if((n&(n-1))==0)
            n = n - 1;
        while(n){
        ans++;
        n = n / 2;
        }
    }
    printf("%d\n", ans);
        return 0;
}