#include <stdio.h>
#include <string.h>

int main()
{
    int t, k, m;
    scanf("%d%d", &t, &k);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &m);
        int ans[20] = {0};
        int base = 1;
        for (int i = 0; i < 20 && base <= m; i++)
        {
            ans[i] = (m / base) % k;
            //printf("ans[%d]=%d d",i,ans[i]);
            base *= k;
        }
        int cur = 19;
        while (ans[cur] == 0 && cur >= 0)
            cur--;
        while (cur >= 0)
            printf("%d", ans[cur--]);
        printf("\n");
    }
}
/*
数制转换
第一行给出两个数，第一个数t表示有t个十进制数待转换，第二个数n表示转换后数的进制。(2≤n≤9)

接下来t行，分别表示这t个十进制数。

输出这t个数的n进制表示，每个数后面有换行。

Input
1 8
8
Output
10
8的八进制表示为10。

Hint
利用栈去储存n进制下的每一位数字。
*/
