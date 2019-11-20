/*
Description
给定一个数组（数组的长度不超过1000），它的第 i 个元素是一支给定股票第 i 天的价格（股票价格为正整数）。如果你只允许完成一笔交易（即买入和卖出一支股票），通过程序来计算你所能获取的最大利润。

注意：你不能在买入股票前卖出股票。

Examples
Input: [7,1,5,3,6,4]
Output:5
Explanation:

在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
Input: [7,6,4,3,1]
Output:0
Explanation:

在这种情况下, 没有交易完成, 所以最大利润为 0。
*/
#include<stdio.h>
int p[1323], n = 0,min,ans=0;
int main(){
    while(scanf("%d",&p[n++])!=EOF);
    printf("%d\n", n);
    min = p[0];
    for (int i = 0; i < n;i++){
        if(p[i]<min)
            min = p[i];
        if(p[i]-min>=ans)
            ans = p[i] - min;
    }
    printf("%d", ans);
    return 0;
}