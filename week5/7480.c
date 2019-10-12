/*
Description
输入任意大写字母，输出该字母对应的小写字母
*/
#include <stdio.h>
int main()
{
    char c;
    scanf("%c", &c);
    printf("%c\n", c - 'A' + 'a');
}