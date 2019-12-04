/*
编写函数：
int strMatch(const char *, const char *)
该函数接受两个字符串作为参数，返回第二个字符串在第一个字符串中第一次出现的位置（从0开始），如果第一个字符串中不包含第二个字符串，返回-1

输入保证所有字符串长度均小于等于1000

Sample Input
ababc

abc
Sample Output
2
Sample Input
ababa

abc
Sample Output
-1
*/
#include <stdio.h>

#define MAXLENGTH (1000+1)
#include<string.h>
int strMatch(const char *a, const char *b){
    int pi = -1;
    int lena = strlen(a);
    int lenb = strlen(b);
    if(lenb>lena)
        return -1;
    else{
        for (int i = 0; i <= lena - lenb;i++){
            int flag = 0;
            for (int j = i,k=0; j < lenb + i;j++,k++){
                if(a[j]!=b[k]){
                    flag = 1;
                    break;
                }
            }
            if(flag==0){
                return i;
            }
        }
    }
    return -1;
}
int main() {
    char s1[MAXLENGTH], s2[101];
    scanf("%s%s", s1, s2);
    int strMatch(const char *, const char *);
    printf("%d\n", strMatch(s1, s2));
    return 0;
}
