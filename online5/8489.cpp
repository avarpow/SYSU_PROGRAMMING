//bcd.h
void reverse(char *stptr);
//main.c
#include <stdio.h>
//#include "bcd.h"

#include <stdio.h>
int main()
{
    char str1[50];
    scanf("%s", str1);
    reverse(str1);
    return 0;
}
//bcd.c
#include <stdio.h>
#include <string.h>
void reverse(char *s)
{
    int len = strlen(s);
    for (int i = 0, j = len - 1; i < j; j--, i++)
    {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
    printf("%s", s);
}
/*
Description
根据提供的 bcd.h 及 main.c两个文件，在文件bcd.c中，编写函数void reverse(char *str1);，用这个函数反向打印字符串。

Input
输入一个字符串，长度小于50，包含空格

Output
输出反向的字符串

Sample Input
abcd
Sample Output
dcba
*/