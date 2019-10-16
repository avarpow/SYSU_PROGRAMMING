/*
最小公倍数的定义：对于两个整数a，b，整数c既可以整除a，也可以整除b且是满足这个条件的最小整数。如5, 7的最小公倍数是35。

输入的第一个数字N代表有多少个测试样例。接下来的每行输入的第一个整数M代表接下来要输入多少个整数。输出每一行的最小公倍数。

输入：
2
3 5 7 15
6 4 10296 936 1287 792 1
输出：
105
10296
*/
/*改用a*b=lcm*gcd的正确算法*/
#include<stdio.h>
#include<string.h>
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main()
{
    long long n, t, num, ans;
    scanf("%lld", &n);
    for (int i = 0; i < n;i++){
        ans = 1;
        scanf("%lld", &num);
        for (int j = 0; j < num;j++){
            scanf("%lld", &t);
            ans = ans / gcd(ans, t) * t;
        }
        printf("%lld\n", ans);
    }
        return 0;
}
