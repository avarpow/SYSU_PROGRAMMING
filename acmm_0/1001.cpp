/*
http://soj.acmm.club/show_problem.php?pid=22433
*/
#include<stdio.h>
using namespace std;
int main()
{
    int n,k,t;
    int max = 0;
    scanf("%d %d", &n, &k);
    if(n%(k+1) ==0)
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}