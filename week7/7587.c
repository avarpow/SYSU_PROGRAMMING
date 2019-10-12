/*
Description
对于给定的一个百分制分数，输出成绩等级A、B、C、D、E，其中90-100分为A，80-89分为B，70-79分为C，60-69分为D，0-59分为E。如果输入的成绩不合理，则输出error

Input
输入数据第一行为一个整数n，表示有n个百分制分数需要处理。

第二行至第n+1行，每行为一个整数，表示对应的分数。

Output
 对于每一个输入的分数，输出其对应的等级或者错误信息error，单独占一行。
*/
#include<stdio.h>
int main(){
    char s[11][10]={"E\n","E\n","E\n","E\n","E\n","E\n","D\n","C\n","B\n","A\n","A\n"};
    int n,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        (t>=0 && t<=100)?printf("%s",s[t/10]):printf("error\n");
    }
}