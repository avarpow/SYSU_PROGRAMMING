/*
Description
Given a string, reverse the order of words in the string

Sample 1：
Input："the sky is blue."
Output："blue. is sky the"
Sample 2：
Input："   hello world!  "
Output："world! hello"
Note：The input string may contain extra spaces at the beginning or end, which needs to be removed after reverse.

Sample 3：
Input："a good     example"
Output："example good a"
Note: If there are more than one space between two words, only one space remains after reverse.

Rules：
A word is a number of consecutive characters that do not contain spaces
The input string may contain extra spaces at the beginning or end, which needs to be removed after reverse
If there are more than one space between two words, only one space remains after reverse
There is no newline at the end
The length of the input string should not exceed 300
*/
#include<stdio.h>
char s[100][20];
int main(){
    int a, b, c, d,num=0;
    while(scanf("%s",s[num])!=EOF){
        num++;
    }
    for(int i=num-1;i>=0;i--){
        printf("%s%s",s[i],i==0?"":" ");
    }
    return 0;
}