/*
Description
输入一个整数，来判断它是否是 2 的幂次方，是输出“Yes”，不是输出“No”。

Input sample
3
1
16
218
Output sample
Yes
Yes
No
Hint
第一行输入应为一个整数 n ( 1<=n<=20)，表示要输入数字的个数。

第二行开始输入所需操作的数字，每一行包含一个数字 m (0 <= m < 10,000)

考虑整数的二进制表示。
*/
#include<stdio.h>
int main()
{
    int n,ans=0,t;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d", &t);
        printf("%s\n", t & (t - 1) ? "No" : "Yes");
    }
}