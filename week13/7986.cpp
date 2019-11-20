/*
现在给出一串字符串，里面的括号要不成双出现，要不就不出现，也就是括号匹配。括号的种类包括'{'、'}'、'('、')‘、'['、']'。请大家判断字符串是否括号匹配，是则输出"Yes"，反之输出"No"。字符串长度不大于100。

输入
abc(abc)
输出
Yes
输入
abv(aa
输出
No
*/
#include<stdio.h>
#include<string.h>
int main(){
    char s[123];
    scanf("%s", &s);
    int len = strlen(s);
    int c=0,flag=0;
    for (int i = 0; i < len;i++){
        if(s[i]=='(')
            c++;
        else if(s[i]==')'){
            if(c>0)
                c--;
            else{
                flag = 1;
                break;
            }
        }
    }
    printf("%s", flag || c!=0? "No" : "Yes");
    return 0;
}