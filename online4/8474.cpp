/*
Description
从第一个字符串中删除所有在第二个字符串中出现的字符(包括字母、标点、数字等所有字符)，不能改变其它字符的顺序，区分大小写。 程序中可以假设所有字符串的长度都小于100个字符。 例如：两个字符串分别为"a1b2c3hello123"，"123hello"，把第二个字符串中出现的字符全部剔除之后结果为"abc"。

Input
分为两行，分别为两个字符串，字符串中间没有空格

Output
输出剔除后的结果，占一行，字符串末尾有换行符

Sample Input
abcaaadefff
aftt
Sample Output
bcde
*/
#include<stdio.h>
#include<string.h>
int main(){
    char a[200],b[200];
    int vis[200]={0};
    scanf("%s%s",a,b);
    for(int i=0;i<strlen(b);i++){
        vis[b[i]]=1;
    }
    for(int i=0;i<strlen(a);i++){
        if(vis[a[i]]==0)printf("%c",a[i]);
    }
    return 0;
}