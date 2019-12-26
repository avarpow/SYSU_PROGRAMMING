/*
Description
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

Examples
输入: num1 = "2", num2 = "3"
输出: "6"
输入: num1 = "123", num2 = "456"
输出: "56088"
Hint
num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void rev(char s[],int len){
    for (int i = 0; i < len-1-i;i++){
        char t = s[i];
        s[i] = s[len - i-1];
        s[len - 1-i] = t;
    }
}
char* multiply(char *num1, char* num2){
    char *p = num1;
    int ans[500] = {0};
    char *ouput = (char *)malloc(500 * sizeof(char));
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    rev(num1,len1);
    rev(num2,len2);
    for (int i = 0; i < len1;i++){
        for (int j = 0; j < len2;j++){
            if(num1[i]!=0 && num2[j]!=0){
                ans[i + j] += (num1[i]-'0' ) * (num2[j]-'0');
            }
        }
    }
    for (int i = 0; i < 300;i++){
        if(ans[i]>10){
            ans[i + 1] += ans[i] / 10;
            ans[i] = ans[i] % 10;
        }
        
    }
    int t = 299;
    while(ans[t]==0)
        t--;
    int i=0;
    while(t >= 0){
        ouput[i++]=ans[t--]+'0';
    }
    ouput[i]=0;
    p = ouput;
    return p;
}
int main(){
	char num1[102];
    char num2[102];
    scanf("%s", num1);
    scanf("%s", num2);
    char* num = multiply(num1, num2);
    printf("%s", num);
    free(num);
	return 0;
}