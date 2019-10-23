/*
已知公元1年1月1日是星期一，问某年某月某日是星期几？

Input
输入为三个正整数y,m,d，分别代表年、月、日。其中，1≤y≤500000000000, m和d保证合法。

Output
输出星期几，星期一到星期六分别用1到6表示，星期天用7表示。注意输出最后有一个换行。

Sample Input
2017 9 25

Sample Output
1
*/
#include<stdio.h>
int main()
{
    long long y, m, d,ans;
    scanf("%ld%ld%ld", &y, &m, &d);
    ans = (((m<3?y-1:y) / 100) / 4 - 2 * ((m<3?y-1:y) / 100) + (m<3?y-1:y) % 100 + ((m<3?y-1:y) % 100) / 4 + (13 * ((m<3?m+12:m) + 1)) / 5 + d - 1) % 7;
    printf("%d\n", (ans+7)%7 ==0 ? 7:(ans+7)%7);
}