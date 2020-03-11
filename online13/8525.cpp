#include <stdio.h>
#include <string.h>
char a[8][300], b[8][300] = {0};
char num[11][10] = {
    "01101111",
    "00100100",
    "01110011",
    "01110110",
    "00111100",
    "01011110",
    "01011111",
    "01100100",
    "01111111",
    "01111110",
    "00010000",
};
int main()
{
    for (int i = 0; i < 7; i++)
    {
        scanf("%s", a[i]);
    }
    int len = strlen(a[0]);
    int ans[2] = {0}, flag = 0;
    for (int i = 0; i < len; i += 6)
    {
        char temp[10] = {0};
        temp[0] = 48;
        temp[1] = (a[0][i + 1] == 'x') + 48;
        temp[2] = (a[1][i + 4] == 'x') + 48;
        temp[3] = (a[3][i + 1] == 'x') + 48;
        temp[4] = (a[2][i + 0] == 'x') + 48;
        temp[5] = (a[4][i + 4] == 'x') + 48;
        temp[6] = (a[6][i + 1] == 'x') + 48;
        temp[7] = (a[5][i + 0] == 'x') + 48;
        for (int j = 0; j < 11; j++)
        {
            if (strcmp(num[j], temp) == 0)
            {
                if (j == 10)
                    flag = 1;
                else
                {
                    ans[flag] *= 10;
                    ans[flag] += j;
                }
            }
        }
    }
    ans[0] = ans[0] + ans[1];
    ans[1] = 0, flag = 0;
    int sta[10], si = 0;
    while (ans[0])
    {
        sta[si++] = ans[0] % 10;
        ans[0] = ans[0] / 10;
    }
    if (si == 0)
    {
        printf("xxxxx\n"
               "x...x\n"
               "x...x\n"
               "x...x\n"
               "x...x\n"
               "x...x\n"
               "xxxxx\n");
        return 0;
    }
    while (si > 0)
    {
        ans[0] = sta[si-- - 1];
        for (int i = 1; i <= 7; i++)
        {
            if (num[ans[0]][i] == '1')
            {
                if (i == 1)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        b[0][flag + j] = 'x';
                    }
                }
                if (i == 2)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        b[j][flag + 4] = 'x';
                    }
                }
                if (i == 3)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        b[3][flag + j] = 'x';
                    }
                }
                if (i == 4)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        b[j][flag] = 'x';
                    }
                }
                if (i == 5)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        b[j + 3][flag + 4] = 'x';
                    }
                }
                if (i == 6)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        b[6][flag + j] = 'x';
                    }
                }
                if (i == 7)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        b[j + 3][flag] = 'x';
                    }
                }
            }
        }
        ans[1] = ans[1] / 10;
        flag += 6;
    }
    for (int j = 0; j <= 6; j++)
    {
        for (int i = 0; i < flag - 1; i++)
        {
            printf("%c", b[j][i] == 'x' ? 'x' : '.');
        }
        printf("\n");
    }
    return 0;
}
/*
Description
....x.xxxxx.xxxxx.x...x.xxxxx.xxxxx.xxxxx.......xxxxx.xxxxx.xxxxx
....x.....x.....x.x...x.x.....x.........x...x...x...x.x...x.x...x
....x.....x.....x.x...x.x.....x.........x...x...x...x.x...x.x...x
....x.xxxxx.xxxxx.xxxxx.xxxxx.xxxxx.....x.xxxxx.xxxxx.xxxxx.x...x
....x.x.........x.....x.....x.x...x.....x...x...x...x.....x.x...x
....x.x.........x.....x.....x.x...x.....x...x...x...x.....x.x...x
....x.xxxxx.xxxxx.....x.xxxxx.xxxxx.....x.......xxxxx.xxxxx.xxxxx
​ 它的结果是

....x.xxxxx.xxxxx.xxxxx.x...x.xxxxx.xxxxx
....x.....x.....x.x.....x...x.x.........x
....x.....x.....x.x.....x...x.x.........x
....x.xxxxx.xxxxx.xxxxx.xxxxx.xxxxx.....x
....x.x.........x.....x.....x.....x.....x
....x.x.........x.....x.....x.....x.....x
....x.xxxxx.xxxxx.xxxxx.....x.xxxxx.....x
​ 是不是非常直观？

​ 你需要读入一个这样的表达式，然后输出它的结果。（表达式形如 a+b ，只有一个加号，两个数字）

​ 每相邻两个数字/字符之间有一列点，每个数字/字符本身是 7×5 的规格，细节可以参照上面的例子。它也就是本题样例啦。

​ 读入的两个数字长度都在 9 位以内。
*/