/*
http://soj.acmm.club/show_problem.php?pid=1002&cid=2823
*/
#include<stdio.h>
#include<string.h>
int main()
{
    char mi[105],yuan[105],jie[105],ans[105]={0},biao[200]={0},biao2[200]={0},failflag=0;
    scanf("%s%s%s", mi, yuan, jie);
    int milen = strlen(mi);
    for (int i = 0; i < milen;i++){
        if(biao[mi[i]]==0){
            biao[mi[i]] = yuan[i];
        }
        else{
            if(biao[mi[i]]!=yuan[i]){
                failflag = 1;
            }
        }
    }
    for (int i = 0; i < milen;i++){
        if(biao2[yuan[i]]==0){
            biao2[yuan[i]] = mi[i];
        }
        else{
            if(biao2[yuan[i]]!=mi[i]){
                failflag = 1;
            }
        }
    }
    for (int i = 'A'; i <= 'Z';i++){
        if(biao[i]==0){
            failflag = 1;
        }
    }
        int jielen = strlen(jie);
    for (int i = 0; i < jielen;i++){
        if(biao[jie[i]]!=0){
            ans[i] = biao[jie[i]];
        }
        else{
            failflag = 1;
        }
    }
    if(failflag){
        printf("Failed");
    }
    else{
        printf("%s", ans);
    }
        return 0;
}