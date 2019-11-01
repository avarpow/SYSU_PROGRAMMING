/*
http://soj.acmm.club/show_problem.php?pid=1003&cid=2823
*/
#include<stdio.h>
int main()
{
    int magic = 0,n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        float x, y;
        scanf("%f %f", &x, &y);
        if(((int)(x*10)+(int)(y*10))%10==0){
            magic++;
        }
    }
    if(magic*2==n)
        printf("O_O\n");
    else if(magic*2 > n)
        printf("Lose\n");
    else
        printf("Win\n");
    return 0;
}