#include <stdio.h>
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, a, te;
        scanf("%d%d", &n, &a);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &te);
            if (a >= te)
            {
                a += te;
            }
            else
            {
                a += gcd(a, te);
            }
        }
        printf("%d\n", a);
    }
}
/*
Description
Jack is addicted to online games. Once, he is playing a game of fighting monsters and upgrading. The initial ability value of his character is a. In the next period of time, he will meet n monsters in turn, each with a defense of b1,b2,b3,…,bn .

If the monster's defense bi is less than or equal to his current ability value c, then he can easily defeat the monster and increase his ability value by bi; if bi is greater than c, then he can also defeat the monster, but his ability value can only increase the greatest common divisor of bi and c.

So after a series of exercises, what is Jack's final ability value?

Input
The first row is the number of test data groups.

For each group of test data, the first row is two integers, n (1≤n<100000), indicating the number of monsters, and a, indicating the initial ability value of Jack. The second line is n integers.b1,b2,b3,…,bn (1≤bi≤n) indicates the defense of each monster.

Output
For each group of test data, output one line which only includes the the final ability value of Jack.

Examples
Input：

2
3 50
50 105 200
5 20
30 20 15 40 100
Output:

110
205
*/