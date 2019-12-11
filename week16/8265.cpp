/*
Description
给定n个字符串，请对n个字符串按照字典序排列

Input
输入第一行为一个正整数n(1≤n≤100),下面n行为n个字符串(字符串长度≤30),字符串中只含有大小写字母。

Output
数据输出n行，输出结果为按照字典序排列的字符串。

Sample Input
9
cap
to
cat
card
two
too
up
boat
boot
Sample Output
boat
boot
cap
card
cat
to
too
two
up
*/
#include<stdio.h>
#include<string.h>
char s[134][40],t[40];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%s", s[i]);
    }
    for (int i = n - 2; i >= 0;i--){
        for (int j = 0; j <= i;j++){
            if(strcmp(s[j],s[j+1])==1){
                strcpy(t, s[j]);
                strcpy(s[j], s[j+1]);
                strcpy(s[j+1], t);
            }
        }
    }
    for (int i = 0; i < n;i++){
        printf("%s\n", s[i]);
    }
    return 0;
}