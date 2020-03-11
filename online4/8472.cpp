/*
之前大家应该做过高精度加法的题目，那么现在有更加进阶的题目，那就是大整数乘法。大整数乘法，顾名思义就是能够实现很大的整数相乘。比如12345678x12345678=152415765279684。那么现在请大家来写出两个大整数相乘的程序。 输入的两行代表两个大整数，输出相乘后的结果。大整数的长度小于等于100。

输入
2
4
输出
8
*/
#include<stdio.h>
#include<string.h>
void rev(char s[]){
    int len=strlen(s);
    for(int i=0,j=len-1;i<j;j--,i++){
        char t=s[i];
        s[i]=s[j];
        s[j]=t;
    }
}
int main(){
    char t1[108],t2[108];
    int a[108]={0},b[108]={0},ans[208]={0};
    scanf("%s%s",t1,t2);
    rev(t1);
    rev(t2);
    for(int i=0;i<strlen(t1);i++){
        a[i]=t1[i]-'0';
    }
    for(int i=0;i<strlen(t2);i++){
        b[i]=t2[i]-'0';
    }
    for(int i=0;i<strlen(t1);i++){
        for(int j=0;j<strlen(t2);j++){
            ans[i+j]+=(a[i]*b[j]);
        }
    }
    for(int i=0;i<203;i++){
        if(ans[i]>=10){
            ans[i+1]+=(ans[i]-ans[i]%10)/10;
            ans[i]=ans[i]%10;
        }
    }
    int now=205;
    while(ans[now]==0)now--;
    for(int i=now;i>=0;i--){
        printf("%d",ans[i]);
    }
    return 0;
}