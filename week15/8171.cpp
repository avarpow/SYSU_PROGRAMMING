/*
编写函数void swap(char * a, char * b), 实现两个任意长度（不超过1000）字符串的交换。

Hint
main函数已写好，只需提交swap函数的代码。

Sample Input
abcde

abc

Sample Output
abc

abcde
*/
#include <stdio.h>
#include "swap.h"
#define MaxLen 1010
void swap(char *a,char *b){
    for (int i = 0; i < 1010;i++){
        char t = a[i];
        a[i] = b[i];
        b[i] = t;
    }
}
int main()
{
    char a[MaxLen], b[MaxLen];
    scanf("%s", a);
    scanf("%s", b);
    swap(a, b);
    printf("%s\n%s\n", a, b);

    return 0;
}
