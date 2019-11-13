/*
Description
根据提供的 bcd.h 及 main.c两个文件，在文件bcd.c中，编写函数 long long convertOctalToDecimal(int octalNumber);创建一个函数输入一个八进制数，输出十进制

Input
输入一个八进制数

Output
十进制

Sample Input
116
Sample Output
78
*/
#include <stdio.h>
int convertOctalToDecimal(int octalNumber){
    int base = 1,ans=0;
    while(octalNumber!=0){
        ans = ans + base * (octalNumber % 10);
        octalNumber = octalNumber / 10;
        base = base * 8;
    }
    return ans;
}
int main() {
    int octalNumber;
    scanf("%d", &octalNumber);
    printf("%d", convertOctalToDecimal(octalNumber));
    return 0;
}