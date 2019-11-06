/*
Description
根据提供的 btd.h 及 main.c两个文件，在文件btd.c中，编写函数 long long BintoDec(char binary[])，把一个只包括0和1的字符串 表示的二进制数 转化为十进制数。

Input
不超过60个字符的0，1字符串

Sample Output
二进制数对应的十进制整数（long long 类型）

Sample Input
101010101
Sample Output
341
Sample Input
111111111111111111111111111111000
Sample Output
8589934584
*/
#include<stdio.h>
long long BintoDec(char binary[]){
    long long ans=0;
    for(int i=0;binary[i] && (ans=ans<<1,1);i++){
        ans = ans + binary[i] - '0';
    }
    return ans;
}
int main()
{
    char binary[60]; 
    scanf("%s", binary);
    printf("%lld\n", BintoDec(binary));
    return 0;
}


