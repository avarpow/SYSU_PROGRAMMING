#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a;
        scanf("%d", &a);
        int co[10] = {0};
        for (int i = 1; i <= a; i++)
        {
            int temp = i;
            while (temp != 0)
            {
                int mod = temp % 10;
                co[mod]++;
                temp = temp / 10;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            printf("%d%s", co[i], i == 9 ? "\n" : " ");
        }
    }
}
/*
Description
Given an integer N, you can write 1 to N in one line. For example, when N=12, the number from 1 to N written in a line, we can get a new string: 123456789101112
There are one '0', five '1', two '2', …, one '9' in the new string. Your task is very easy, for a given N, tell me how many '0','1','2', …,'8','9' in the new string which write down from 1 to N?

Input
The first line contains an integer M (1⩽M⩽10), indicating the number of test cases.

Then, for each case, there is only a number N (1⩽N⩽1000).

Output
One line for each case, print the number of '0','1','2', …,'8','9', separated by a space.

Sample Input
2
12  5
Sample Output
1 5 2 1 1 1 1 1 1 1
0 1 1 1 1 1 0 0 0 0
*/